#Realiza os imports necessários
import cv2
import numpy as np
import pandas as pd
import tkinter as tk
import scipy.ndimage as ndi
import matplotlib.pyplot as plt
import matplotlib.colors as colors
import matplotlib.patches as patches
from scipy import ndimage
from skimage import io, color
from sklearn.mixture import GaussianMixture
from sklearn import cluster, datasets, mixture
from sklearn.neighbors import KNeighborsClassifier
from sklearn.cluster import KMeans, MeanShift, estimate_bandwidth
from tkinter.filedialog import askopenfilenames, askopenfilename


# Abre uma janela para selecionar quais bases de dados serão utilizadas
# As bases escolhidas tem seus caminhos retornados em uma lista
def getDataBaseToBeUsed():
    root = tk.Tk()
    root.withdraw() # we don't want a full GUI, so keep the root window from appearing
    paths = askopenfilenames(title = 'Choose the databases')
    return paths

# Abre uma janela para selecionar o arquivo da imagem a ser usada
# Essa imagem é carregada em BGR e é retornado a versão BGR, HSV e LAB
# nesta ordem
def getImages():
    root = tk.Tk()
    root.withdraw() # we don't want a full GUI, so keep the root window from appearing
    imgFile = askopenfilename(title = 'Choose the image')
    imgBGR = cv2.imread(imgFile,1)
    imgHSV = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2HSV)
    imgLAB = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2LAB)
    return imgBGR, imgHSV, imgLAB

# Cria o dataframe do pandas no python das bases escolhidas nas janelas
# Se mais de uma base foi selecionada, o algoritmo une elas
def createDataFrame(paths):
    if len(paths) > 1:
        frames = []
        for i in range(len(paths)):
            auxDB = pd.read_csv(paths[i], sep='\t')
            frames.append(auxDB)
        finalDB = pd.concat(frames)
    else:
        finalDB = pd.read_csv(paths[0], sep='\t')
    return finalDB

# Cria uma base de dados na forma de DataFrame utilizando as informações
# da imagem selecionada. Para cada pixel da imagem, adiciona uma nova instância
# colocando os valores B,G,R, H,S,V e L,A,B
def createTestDataBase(imgBGR, imgHSV, imgLAB):
    dbTest = pd.DataFrame(columns=['Bl', 'G', 'R', 'H', 'S', 'V', 'L', 'A','B'])
    listOfDF = []
    for i in range(imgBGR.shape[0]):
        for j in range(imgBGR.shape[1]):
            vet = np.concatenate([imgBGR[i,j,:], imgHSV[i,j,:], imgLAB[i,j,:] ])
            listOfDF.append(pd.Series(vet, index=dbTest.columns))
    dbTest = dbTest.append(listOfDF , ignore_index=True)
    return dbTest

# Percorre cada pixel da imagem e verifica o label atribuido pelo KNN
# Se este label e 0 significa que aquele pixel foi classificado como queimada
# e deve ser adicionado a uma mascara binaria vermelha.
# Esta mascara é retornada
def getRedImageMask(imgBGR, y_pred):
    img_mask = np.zeros((imgBGR.shape[0], imgBGR.shape[1]), dtype = bool)
    for i in range(imgBGR.shape[0]):
        for j in range(imgBGR.shape[1]):
            if y_pred[i*imgBGR.shape[1] + j] == 0:
                img_mask[i,j] = True
    return img_mask

# Percorre cada pixel da imagem e verifica o label atribuido pelo KNN
# Se este label e 1 significa que aquele pixel foi classificado como desmatamento
# e deve ser adicionado a uma mascara binaria laranja.
# Esta mascara é retornada
def getOrangeImageMask(imgBGR, y_pred):
    img_mask = np.zeros((imgBGR.shape[0], imgBGR.shape[1]), dtype = bool)
    for i in range(imgBGR.shape[0]):
        for j in range(imgBGR.shape[1]):
            if y_pred[i*imgBGR.shape[1] + j] == 1:
                img_mask[i,j] = True
    return img_mask



#Para Jupyter notebook para mostrar as imagens recortadas
    # a partir das mascaras. Se estiver rodando no terminal,
    # pode comentar essa parte
def showMaskAsImage(imgBGR, img_mask):
    imgAux = 255*(img_mask).astype(np.uint8)
    imgFinal = cv2.bitwise_and(imgBGR, imgBGR, mask=imgAux)
    plt.figure(figsize=(8,8))
    plt.imshow(imgFinal[:,:,::-1])
    
# Faz um fechamento na imagem
# Funcão pq eu sempre esqueço o que um fechamento faz
def tiraBuraco(img_mask, num):
    return ndi.binary_closing(img_mask, iterations=num)

# Faz uma abertura na imagem
# Funcão pq eu sempre esqueço o que uma abertura faz
def tiraRuido(img_mask, num):
    return ndi.binary_opening(img_mask, iterations=num)

# Calcula o numero de objetos vermelhos da imagem e retorna em nr_objects
# Essa função depende da quantidade de ruido que vai vir no cluster vermelho
# Se tiver muito ruido, passar um num, maior para tirar o ruido da mascara
# utilizando abertura
def calcFires(img_mask, imgBGR, num):
    if num > 0:
        img_mask_sem_ruido = tiraRuido(img_mask, num)
    else:
        img_mask_sem_ruido = img_mask
    labeled, nr_objects = ndimage.label(img_mask_sem_ruido)
    #showMaskAsImage(imgBGR, img_mask_sem_ruido)
    return labeled, nr_objects

# Calcula a area de desmatamento em percentual da area da imagem toda
# Essa função depende da quantidade de ruido que vai vir na mascara laranja
# Se tiver muito ruido, passar um num, maior para tirar o ruido da mascara
# utilizando abertura
def calcDeforestation(img_mask, imgBGR, num):
    if num > 0:
        img_mask_sem_ruido = tiraRuido(img_mask, num)
    else:
        img_mask_sem_ruido = img_mask
    whitePixels = sum(sum(img_mask_sem_ruido))
    totalPixels = img_mask_sem_ruido.shape[0]*img_mask_sem_ruido.shape[1]
    area = round((whitePixels/totalPixels)*100, 2)
    #showMaskAsImage(imgBGR, img_mask_sem_ruido)
    return area

#Algoritmo geral
def supervisedMethod(imgBGR, imgHSV, imgLAB):
	#Seleciona as bases que serão usadas
    paths = getDataBaseToBeUsed()
    #Cria o dataframe a partir das bases selecionadas
    db = createDataFrame(paths)

    #Separa os atributos da base criada para treinamento
    # X = atributos
    # y = labels
    X_train = db.iloc[:, :-1].values  
    y_train = db.iloc[:, 9].values 
    
    #Cria um KNN (deu bons resultados com ele e é rapido de treinar caso precisar
    # criar uma nova base na hora da competição)
    classifier = KNeighborsClassifier(n_neighbors=30)  
    # Treina o KNN com os dados da base
    classifier.fit(X_train, y_train) 

    # Cria a base de dados da imagem a ser classificada
    dbTest = createTestDataBase(imgBGR, imgHSV, imgLAB)
    
    # Separa os atributos
    X_test = dbTest.iloc[:, :].values  

    #Realiza a predição utilizando o KNN
    y_pred = classifier.predict(X_test) 
    
    #Pega as mascaras de cada cor
    img_mask_Red = getRedImageMask(imgBGR, y_pred)
    img_mask_Orange = getOrangeImageMask(imgBGR, y_pred)
    
    labels, nro = calcFires(img_mask_Red, imgBGR, 1)
   
    print('Nro de focos = {}'.format(nro))
    print('Area = {}%'.format(calcDeforestation(img_mask_Orange,imgBGR, 2)))

imgBGR, imgHSV, imgLAB = getImages()

supervisedMethod(imgBGR, imgHSV, imgLAB)