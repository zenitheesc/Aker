# Importa pacotes nececssarios
import argparse
import cv2
import os
import numpy as np
import pandas as pd
import sys
import tkinter as tk
from tkinter.filedialog import askopenfilenames, askopenfilename
from sklearn.cluster import KMeans
import scipy.ndimage as ndi
 
 # Abre uma seleção de arquivo do Tkinter e retorna a string com o arquivo escolhido
def getDataBaseToBeUsed():
    root = tk.Tk()
    root.withdraw() # we don't want a full GUI, so keep the root window from appearing
    paths = askopenfilename(title = 'Choose the database')
    return paths

# Funcão principal do código, seleciona os pixels a serem incluidos na base de dados
def click_and_crop(event, x, y, flags, param):
    # Faz referencias as variáveis globais dentro da função
    global refPt
    global db
 
    # se o botao esquerdo do mouse é pressionado ele salva as coordenadas iniciais e checa
    # o modo para decidir o que fazer

    # Se o modo for 0, espera o botao esquerdo ser solto para capturar uma area da imagem
    if event == cv2.EVENT_LBUTTONDOWN and mode == 0:
        # Salva a coordenada em que o botao do mouse eh pressionado
        refPt = [[x, y]]
        
    # Se o modo for 1, cria um quadrado com a cor do pixel para representar
    # para o usuário, para que ele decida adicionar ou não na base aquela cor
    elif event == cv2.EVENT_LBUTTONDOWN and mode == 1:
        refPt = [[x, y]]
        #Cria o quadrado a ser mostrado para o usuário
        roi = np.zeros((300,300,3), np.uint8)
        roi[:] = image[y,x,:]
        # Adiciona as versão HSV e LAB da imagem
        roiHSV = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
        roiLAB = cv2.cvtColor(roi, cv2.COLOR_BGR2LAB)
        cv2.namedWindow('ROI',cv2.WINDOW_NORMAL)
        cv2.moveWindow('ROI', 900, 50)
        cv2.resizeWindow('ROI', 300,300)
        cv2.imshow("ROI", roi)

        # Esse loop basicamente espera um comando do usuário para dizer qual o label daquele quadrado
        # Apertando 'r' o usuário adiciona aquela cor na base como vermelho
        # Apertando 'o' o usuário adiciona aquela cor na base como laranja
        # Apertando 'z' o usuário adiciona aquela cor na base como outra cor
        while True:
            keyColor = cv2.waitKey(20)
            if keyColor == 27:
                cv2.destroyWindow('ROI')
                break
            elif keyColor == ord("r"):
                print("red")
                vet = np.concatenate([roi[0,0,:], roiHSV[0,0,:], roiLAB[0,0,:], [0]])
                db = db.append(pd.Series(vet, index=db.columns ), ignore_index=True)
                cv2.destroyWindow('ROI')
                break
            elif keyColor == ord("o"):
                print("orange")
                vet = np.concatenate([roi[0,0,:], roiHSV[0,0,:], roiLAB[0,0,:], [1]])
                db = db.append(pd.Series(vet, index=db.columns ), ignore_index=True)
                cv2.destroyWindow('ROI')
                break
            elif keyColor == ord("z"):
                print("others")
                vet = np.concatenate([roi[0,0,:], roiHSV[0,0,:], roiLAB[0,0,:], [2]])
                db = db.append(pd.Series(vet, index=db.columns ), ignore_index=True)
                cv2.destroyWindow('ROI')
                break
 
    # Se o modo for 0, e o botão esquerdo for solto, o código recorta a area
    #selecionada e mostra para o usuário
    elif event == cv2.EVENT_LBUTTONUP and mode == 0:
        # Salva a coordenada em que o botao do mouse e solto
        refPt.append([x, y])
        
        #Ajusta valores selecionados (para pode arrastar o mouse de qualquer direção)
        if refPt[0][0] > refPt[1][0]:
            aux = refPt[0][0]
            refPt[0][0] = refPt[1][0]
            refPt[1][0] = aux
        if refPt[0][1] > refPt[1][1]:
            aux = refPt[0][1]
            refPt[0][1] = refPt[1][1]
            refPt[1][1] = aux
 
        #Cria uma imagem chamada roi, clonando a parte da imagem selecionada pelo usuario
        roi = clone[refPt[0][1]:refPt[1][1], refPt[0][0]:refPt[1][0]]
        # Adiciona as versão HSV e LAB da imagem
        roiHSV = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
        roiLAB = cv2.cvtColor(roi, cv2.COLOR_BGR2LAB)

        # Mostra a imagem recortada para o usuário e espera ele decidir o que fazer com ela
        cv2.imshow("ROI", roi)
        # Esse loop basicamente espera um comando do usuário para dizer qual o label daquele quadrado
        # Apertando 'r' o usuário adiciona aquela cor na base como vermelho
        # Apertando 'o' o usuário adiciona aquela cor na base como laranja
        # Apertando 'z' o usuário adiciona aquela cor na base como outra cor
        # Apertando ESC o usuário cancela aquela ação para a area recortada
        while True:
            keyColor = cv2.waitKey(20)
            if keyColor == 27:
                cv2.destroyWindow('ROI')
                break
            elif keyColor == ord("r"):
                print("red")
                listOfDF = []
                # Cria uma lista onde serão salvos os valores de cada pixel em BGR, HSV e LAB junto
                # com a classe para depois adicionar na base de dados
                for i in range(roi.shape[0]):
                    for j in range(roi.shape[1]):
                        if roi[i,j,0] != 0 and roi[i,j,0] != 1 and roi[i,j,2] != 0:
                            vet = np.concatenate([roi[i,j,:], roiHSV[i,j,:], roiLAB[i,j,:], [0]])
                            listOfDF.append(pd.Series(vet, index=db.columns))
                db = db.append(listOfDF , ignore_index=True)
                cv2.destroyWindow('ROI')
                break
            elif keyColor == ord("o"):
                print("orange")
                listOfDF = []
                # Cria uma lista onde serão salvos os valores de cada pixel em BGR, HSV e LAB junto
                # com a classe para depois adicionar na base de dados
                for i in range(roi.shape[0]):
                    for j in range(roi.shape[1]):
                        if roi[i,j,0] != 0 and roi[i,j,0] != 1 and roi[i,j,2] != 0:
                            vet = np.concatenate([roi[i,j,:], roiHSV[i,j,:], roiLAB[i,j,:], [1]])
                            listOfDF.append(pd.Series(vet, index=db.columns))
                db = db.append(listOfDF , ignore_index=True)
                cv2.destroyWindow('ROI')
                break
            elif keyColor == ord("z"):
                print("others")
                listOfDF = []
                # Cria uma lista onde serão salvos os valores de cada pixel em BGR, HSV e LAB junto
                # com a classe para depois adicionar na base de dados
                for i in range(roi.shape[0]):
                    for j in range(roi.shape[1]):
                        vet = np.concatenate([roi[i,j,:], roiHSV[i,j,:], roiLAB[i,j,:], [2]])
                        listOfDF.append(pd.Series(vet, index=db.columns))
                db = db.append(listOfDF , ignore_index=True)
                cv2.destroyWindow('ROI')
                break

# Faz um kmeans na imagem BGR e retorna os centro e labels
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

# Procura dentre os centros encontados o que tem o vermelho (BGR)
# mais forte e retorna este cluster
def getLabelRedRGB(centers):
    clusVerm = 0
    for i in range(1,len(centers)):
        if centers[i][2] > centers[clusVerm][2]:
            clusVerm = i
    return clusVerm



print(sys.argv)
# Verifica se algum argumento foi passado
# Eu criei isso para ter 2 modos: usar uma base de dados antiga ou criar uma nova
# Se um argumento for passado no terminal, este deve ser uma base de dados em .csv
# utilizando tab como separação - assim o algoritmo vai carregar essa base e 
# complementar ela. Se nenhum argumento for passado, o algoritmo cria uma base
# vazia.
if len(sys.argv) > 1:
    paths = getDataBaseToBeUsed()
    db = pd.read_csv(paths, sep='\t')
    print(db)
else:
    db = pd.DataFrame(columns=['Bl', 'G', 'R', 'H', 'S', 'V', 'L', 'A','B', 'Color'])

#Seleciona imagens
index=0
img_list=[]
border=[]

# mode controla o tipo de seleção de pixels,
# podendo esta ser em area (clicando e arrastando)
# ou por pixel expecífico
mode = 0

# modew controla o tipo de representação da imagem,
# podendo esta ser da imagem original ou da imagem
# com as cores vermelhas e laranja isoladas
mode2 = 0

#Usa os arquivos da pasta nomeada cropped
for file in os.listdir("cropped/"):
    img_list.append(os.path.join("cropped/", file))

l=len(img_list)

# Cria uma nova janela do OpenCV
cv2.namedWindow('image',cv2.WINDOW_NORMAL)
cv2.moveWindow('image', 50, 50)
cv2.resizeWindow('image', 800,800)
# Comando designado para o mouse esta associado a função click_and_crop
cv2.setMouseCallback("image", click_and_crop)
 
 
while True:
    image = cv2.imread(img_list[index])
    
    #Isola as cores proximas de vermelho e laranja
    # Feito para facilitar a selecão em area destas cores
    if mode2 == 1:
        labels, centers = firstKmeans(image)
        clusVerm = getLabelRedRGB(centers)
        img_mask = labels==clusVerm
        img_mask = ndi.binary_opening(img_mask, iterations=2)
        imgAux = 255*(img_mask).astype(np.uint8)
        image = cv2.bitwise_and(image, image, mask=imgAux)

    clone = image.copy()

    # Mostra a imagem e espera por um botão ser apertado
    cv2.imshow("image", image)
    key = cv2.waitKey(1) & 0xFF
 
    # Fecha a janela se ESC (27) ou 'q' forem apertados
    if key == 27 or key == ord('q'):
        break
        
    #Troca o modo de captura de cor
    elif key == ord("1"):
        if mode == 0:
            print("Modo de pontos")
            mode = 1
        else:
            print("Modo de quadrados")
            mode = 0

    #Isola cores Vermelhas e Laranjas - usando kmeans
    elif key == ord("2"):
        if mode2 == 0:
            print("Modo Cores Isoladas")
            mode2 = 1
        else:
            print("Modo todas as cores")
            mode2 = 0
    
    # Muda para a próxima imagem
    elif(key == ord('[')):
        index-=1
        index%=l

    # Muda para a imagem anterior
    elif(key == ord(']')):
        index+=1
        index%=l

    # Salva a base de dados criada no programa
    # Futuramente na interface precisamos mudar o nome deste arquivo
    elif(key == ord('s')):
        print('salvando')
        db.to_csv('baseDeDados.csv', sep='\t', index=False)

cv2.destroyAllWindows()
