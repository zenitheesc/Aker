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
from sklearn.cluster import KMeans, MeanShift, estimate_bandwidth
from tkinter.filedialog import askopenfilenames, askopenfilename


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

# Cria uma base de dados que contem 9 colunas para cada atributo de cor, sendo eles
# Blue, Green, Red, Hue, Saturation, Value, ligh, A e B para ser usado na clusterização
# Retorna a base criada sem nenhum dado ainda
def createTestDataBase(imgBGR, imgHSV, imgLAB):
    dbTest = pd.DataFrame(columns=['Bl', 'G', 'R', 'H', 'S', 'V', 'L', 'A','B'])
    listOfDF = []
    for i in range(imgBGR.shape[0]):
        for j in range(imgBGR.shape[1]):
            vet = np.concatenate([imgBGR[i,j,:], imgHSV[i,j,:], imgLAB[i,j,:] ])
            listOfDF.append(pd.Series(vet, index=dbTest.columns))
    dbTest = dbTest.append(listOfDF , ignore_index=True)
    return dbTest

# Usa o kmeans com 5 clusters apenas com BGR - essa primeira clusterização é feita
# para separa apenas uma imagem com vermelho e laranja
# Em geral 5 clusters separa bem as duas cores
# Retorna os centros e os labels da clusterização
def firstKmeans(imgBGR):
    canais = [0,1,2]
    num_clusters = 5
    
    tst = imgBGR
    tst = tst[:,:,canais]
    data = tst.reshape(tst.shape[0]*tst.shape[1], len(canais))
    km = KMeans(n_clusters=num_clusters)
    km.fit(data)
    labels = km.predict(data)
    img_labels = labels.reshape(tst.shape[:2])
    centers=km.cluster_centers_
    return img_labels, centers

# Usa o kmeans com 5 clusters e todos os atibutos BGR, HSV e LAB da imagem
# essa primeira clusterização é feita
# para separa apenas uma imagem com vermelho e laranja
# Em geral 5 clusters separa bem as duas cores
# Retorna os centros e os labels da clusterização
def firstKmeansAllAtrib(db, imgBGR):
    
    X_train = db.iloc[:, :].values  
    
    canais = [0,1,2]
    num_clusters = 5

    km = KMeans(n_clusters=num_clusters)
    km.fit(X_train)
    labels = km.predict(X_train)
    img_labels = labels.reshape(imgBGR.shape[:2])
    centers=km.cluster_centers_
    return img_labels, centers

# Acha qual o label que contem as cores vermelho e laranja
# Separa esse cluster verificando qual cluster possui o maior valor vermelho
# do espectro BGR
def getLabelRedRGB(centers):
    clusVerm = 0
    for i in range(1,len(centers)):
        if centers[i][2] > centers[clusVerm][2]:
            clusVerm = i
    return clusVerm


# Usa o kmeans com 10 clusters utilizando a imagem LAB apenas
# essa segunda clusterização recebe uma mascara, para evitar que
# outras cores alem de laranja e vermelho estejam na imagem.
# São clusterizados 10 clusters, porém futuramente estes serão agrupados
# selecionando qual é vermelho e qual é laranja, excluido a parte preta da imagem
# Retorna os centros e os labels da clusterização
def secondKmeans(imgBGR, img_mask):
    # Retira as outras cores (deixando só vermelho e laranja)
    imgAux = 255*(img_mask).astype(np.uint8)
    imgFinal = cv2.bitwise_and(imgBGR, imgBGR, mask=imgAux)
    
    canais = [0,1,2]
    num_clusters = 10

    tst = cv2.cvtColor(imgFinal, cv2.COLOR_RGB2LAB)
    tst = tst[:,:,canais]

    data = tst.reshape(tst.shape[0]*tst.shape[1], len(canais))

    km = KMeans(n_clusters=num_clusters)
    km.fit(data)
    labels = km.predict(data)
    img_labels = labels.reshape(imgBGR.shape[:2])
    centers = km.cluster_centers_
    return img_labels, centers


# Cria uma mascara para a cor vermelha, buscando nos centros retornadas pela clusterização
# Uma mascara binaria é criada para cada centro escolhido, e ao final uma operação OR
# é feita com todas as mascaras para gerar a mascara final
def getRedImageMask(imgBGR, centers, labels):
    redList = []
    for i,cent in enumerate(centers):
        if (cent[0] > 40 and cent[0] < 80 and cent[1] > 160 and cent[1] < 190 and cent[2] > 40 and cent[2] < 70):
            redList.append(i)

    img_mask_r = np.zeros((imgBGR.shape[0], imgBGR.shape[1]),dtype=bool)
    for label in redList:
        currentMask = labels==label
        img_mask_r = (img_mask_r) | (currentMask)
    return redList, img_mask_r

# Cria uma mascara para a cor laranja, buscando nos centros retornadas pela clusterização
# Uma mascara binaria é criada para cada centro escolhido, e ao final uma operação OR
# é feita com todas as mascaras para gerar a mascara final
def getOrangeImageMask(imgBGR, centers, labels, redList):
    black = []
    for i,cent in enumerate(centers):
        if (cent[1] > 127.9 and cent[1] < 128.1 and cent[2] > 127.9 and cent[2] < 128.1 and cent[0] < 2):
            black.append(i)

    orangeList = list(set(range(len(centers))) - set(redList) - set(black))
    
    img_mask_o = np.zeros((imgBGR.shape[0], imgBGR.shape[1]),dtype=bool)
    for label in orangeList:
        currentMask = labels==label
        img_mask_o = (img_mask_o) | (currentMask)
    return img_mask_o
    
    return orangeList, img_mask

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
def calcFires(img_mask, num):
    if num > 0:
        img_mask_sem_ruido = tiraRuido(img_mask, num)
    else:
        img_mask_sem_ruido = img_mask
    labeled, nr_objects = ndimage.label(img_mask_sem_ruido) 
    return labeled, nr_objects


# Calcula a area de desmatamento em percentual da area da imagem toda
def calcDeforestation(img_mask):
    whitePixels = sum(sum(img_mask))
    totalPixels = img_mask.shape[0]*img_mask.shape[1]
    area = round((whitePixels/totalPixels)*100, 2)
    return area

# Aumenta a saturação da imagem, colocando a saturação em 250 para toda a imagem
# Essa modificação é feina na imagem para a segunda clusterização, para que o vermelho
# se destaque mais e facilite a sepração do laranja
def increaseSaturation(imgBGR):
    imgHSV = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2HSV)
    for i in range(imgHSV.shape[0]):
        for j in range(imgHSV.shape[1]):
            #if imgHSV[i,j,1] + 100 > 254:
            #    imgHSV[i,j,1] = 255
            #else:
            #    imgHSV[i,j,1] += 100
            imgHSV[i,j,1] = 250

    imgBGR2 = cv2.cvtColor(imgHSV, cv2.COLOR_HSV2BGR)
    return imgBGR2

# Algoritmo geral
def unsupervisedMethodDark(imgBGR, imgHSV, imgLAB):
    
    # Cria uma base de dados para usar os 9 atributos
    # B,G,R, H,S,V e L,A,B
    db = createTestDataBase(imgBGR, imgHSV, imgLAB)

    #Realiza o primeiro kmeans para separar apenas as cores vermelho e laranja
    # utilizando todos os atributos
    labels1, centers1 = firstKmeansAllAtrib(db, imgBGR)

    #Identifica qual o cluster das cores vermelho e laranja
    clusRedOrange = getLabelRedRGB(centers1)

    #Cria uma mascara do cluster vermelho e laranja
    img_mask_RandO = labels1==clusRedOrange

    #Aumento de saturacao para a segunda clusterização
    imgHigherSat = increaseSaturation(imgBGR)
    
    # Faz um segundo k means para separar as duas cores
    labels2, centers2 = secondKmeans(imgHigherSat, img_mask_RandO)
    print(centers2)
    
    # Cria a mascara da cor vermelha a partir dos cluster do segundo kmeans
    redList, img_mask_Red = getRedImageMask(imgBGR, centers2, labels2)
    # Cria a mascara da cor laranja a partir dos cluster do segundo kmeans
    img_mask_Orange = getOrangeImageMask(imgBGR, centers2, labels2, redList)
    
    #Para Jupyter notebook para mostrar as imagens recortadas
    # a partir das mascaras. Se estiver rodando no terminal,
    # pode comentar essa parte
    #showMaskAsImage(imgBGR, img_mask_Red)
    #showMaskAsImage(imgBGR, img_mask_Orange)
    
    labels, nro = calcFires(img_mask_Red, 2)
   
    print('Nro de focos = {}'.format(nro))
    print('Area = {}%'.format(calcDeforestation(img_mask_Orange)))


imgBGR, imgHSV, imgLAB = getImages()
#Ignora o nome dark, esqueci de mudar hahaha
# Faz a versão nao supervisionada focando no vermelho (queimada)
# e laranja (desmatamento)
unsupervisedMethodDark(imgBGR, imgHSV, imgLAB)