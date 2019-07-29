#Realiza os imports necessarios
from sklearn.cluster import MeanShift
import matplotlib.patches as patches
import matplotlib.colors as colors
from sklearn.cluster import KMeans, MeanShift, estimate_bandwidth
import matplotlib.pyplot as plt
from skimage import io, color
import scipy.ndimage as ndi
import skimage.color
import numpy as np
import os,os.path
import cv2
import math
import time

def nothing(e):
    pass
#Obtem valor para resize da imagem
def get_ratio(pic):
    ratio_x=int(pic.shape[1]/480)
    ratio_y=int(pic.shape[0]/400)
    if ratio_x>ratio_y:
        ratio=(pic.shape[1]/ratio_x,pic.shape[0]/ratio_x)
    else:
        ratio=(pic.shape[1]/ratio_y,pic.shape[0]/ratio_y)
    return ratio

def color_difference (color1, color2):
    # Retorna a distancia euclidiana entre duas cores no espaco RGB
    return math.sqrt(sum([(abs(component1-component2))**2 for component1, component2 in zip(color1, color2)]))

#Funcao retorna a imagem contornada e a area desmatada da mesma
def rgbMeanShiftImageSeg(img,mode):
    data = img.reshape(img.shape[0]*img.shape[1], mode)
    
    #data = img.reshape(img.shape[0]*img.shape[1], 2)
    #data = img.reshape(img.shape[0]*img.shape[1], 1)
    
    bandwidth = estimate_bandwidth(data, quantile=0.2, n_samples=500)
    
    print(bandwidth)
    print(bandwidth/3.7)
    mShift=MeanShift(bandwidth=(bandwidth/3.75),bin_seeding=True)

    labels=mShift.fit_predict(data)
    img_labels=labels.reshape(img.shape[:2])
    centers=mShift.cluster_centers_
    return img_labels, centers

#Mascara Azul
def findBlue(img):
    pass

#Mascara Vermelho e Laranja
def findRedOrange(pic):
    top=[0,0]
    bot=[255,255]
    center=[]
    img=cv2.cvtColor(pic,cv2.COLOR_BGR2Lab)
    labels, centers=rgbMeanShiftImageSeg(img[:,:,1:],2)
    mask=np.zeros((img.shape[0],img.shape[1]), dtype=bool)
    redMask=np.zeros((img.shape[0],img.shape[1]), dtype=bool)
    orangeMask=np.zeros((img.shape[0],img.shape[1]), dtype=bool)
    

    for i in range(0,len(centers)):
        if(3<abs(centers[i][0]-centers[i][1])<20 and (132.5<=centers[i][0]<=187.5) and(130<=centers[i][1]<=180)):
            #mask=mask or(i==labels)
            mask=np.logical_or(mask,(i==labels))
            center.append(list(centers[i]))
    mask=255*mask.astype(np.uint8)
    for i in range(0,len(center)):
        soma=float(sum(center[i]))
        if(soma>sum(top)):
            top=center[i]
        if(soma<sum(bot)):
            bot=center[i]
    for i in range(0,len(centers)):
        if(list(centers[i]) in center):
            if((abs(top[0]-centers[i][0])+abs(top[1]-centers[i][1]))<(abs(bot[0]-centers[i][0])+abs(bot[1]-centers[i][1]))):
                redMask=np.logical_or((i==labels),redMask)
            else:
                orangeMask=np.logical_or((i==labels),orangeMask)
    redMask=255*(redMask).astype(np.uint8)
    orangeMask=255*(orangeMask).astype(np.uint8)
    return redMask, orangeMask

def getBlueKMeans(imgBGR):
    start_time = time.time()
    
    # Passa a imagem de BGR para RGB
    img = imgBGR[:, :, ::-1]

    # Separa os canais R, G e B, fazendo os subtracts necessários para melhorar a separação dos canais
    # imgR = Red, imgG = Green, imgB = Blue (não usa todos em geral)
    imgR = cv2.subtract(img[:,:,0],img[:,:,2])
    imgG = cv2.subtract(img[:,:,1],img[:,:,0])
    imgB = cv2.subtract(img[:,:,2],img[:,:,1])
    imgG = cv2.subtract(imgG,imgB)

    # Usa limiarização de Otsu para binarizar o canal específico
    retB1, thB1 = cv2.threshold(imgB,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
    binBlue = thB1
    binBlue = 255*(binBlue).astype(np.uint8)
    # Cria uma mascar usando a imagem binaria citada anteriormente
    imgBlue = cv2.bitwise_and(img, img, mask=binBlue)
    
    # Seleciona quais canais do espaço de cor serão usados para a segmentação
    # Nesse caso será usado o espaço de cor HSV, utilizando apenas o H (separa por cor, pois o azul é bem distinto)
    canais = [0]

    #Transformação da imagem para HSV
    tst = cv2.cvtColor(imgBlue, cv2.COLOR_RGB2HSV)

    #Pega apenas os canais necessários da imagem
    tst = tst[:,:,canais]
    #Reshape na imagem para usar nos algoritmos de agrupamento
    data = tst.reshape(img.shape[0]*img.shape[1], len(canais))

    #Faz o K-means (coloquei 20 clusters, pq ficou bom e rápido dessa forma)
    # Se precisar ou ficar melhor pode usar o MeanShift
    km = KMeans(n_clusters=20)
    km.fit(data)
    labels = km.predict(data)

    img_labels = labels.reshape(img.shape[:2])
    centers=km.cluster_centers_
    
    '''
    Nessa parte so definidas as regras que selecionam quais cluster vão reprensentar a cor
    Para o caso do Azul verificamos se o valor de H está dentro da faixa 100 < H < 130,
    pois essa faixa de cor representa as cores mais próximas do azul no espectro HSV
    Os clusters que tiverem seu valor dentro dos parametros são adicionados na lista chosenColors
    '''
    chosenColors = []
    for i,cent in enumerate(centers):
        if cent[0] < 130 and cent[0] > 100:
            chosenColors.append(i)

    # Cria a máscara final fazendo ORs nas mascaras escolhidas acima
    imgFinal = np.zeros((img.shape[0], img.shape[1]),dtype=bool)
    for label in chosenColors:
        img_mask = img_labels==label
        imgFinal = (imgFinal) | (img_mask)
    
    #Pode fazer uma abertura ou fechamento se precisar aqui
    #imgFinal = ndi.binary_opening(imgFinal, iterations=3)
    #Cria a mascara final a ser retornada
    imgAux = 255*(imgFinal).astype(np.uint8)
    imgCont = cv2.bitwise_and(img, img, mask=imgAux)
    
    print("--- %s seconds ---" % (time.time() - start_time))
    return imgAux 

#Mascara Verdes
def findGreens(pic):
    img=cv2.cvtColor(pic,cv2.COLOR_BGR2HSV)
    labels, centers=rgbMeanShiftImageSeg(img[:,:,:1],2)


calc=1
index=0
running=1
img_list=[]
label_pos=0


#[Azul,Laranja,Vermelho,Verde Claro, Verde Escuro,Preto]
masks=[]

'''
Azul
[161.4  47.87]
[159.7  53.27] [154.67 68.80] [128.4  83.71]
[146.2  64.35] [128.0  83.76]
[148.4  88.51] [164.0  61.26] [155.8  74.64] [151.9  81.47]
[147.7  88.76] [162.4  63.02] [156.7  73.04] [159.9  67.55] [153.5  78.02] [166.0  58.14]

Laranja
[160.3  174.2] [147.3  148.8]
[146.2  151.8]
[141.6  144.2]
[135.1  143.7] [134.7  143.5]

Vermelho
[184.9  176.5]
[163.2  154.1]
[158.3  131.0] [158.0  123.2]
[147.5  140.5] [147.6  140.1]
'''

test=1


#Seleciona imagens
for file in os.listdir("imgs_padr/"):
    img_list.append(os.path.join("imgs_padr/", file))

l=len(img_list)



while running:
    start_time = time.time()
    img = cv2.imread(img_list[index],1)
    ratio=get_ratio(img)
    tst=cv2.cvtColor(img,cv2.COLOR_BGR2Lab)
    

    if calc:
        blueMask =getBlueKMeans(img)
        imgBlue=cv2.bitwise_and(img, img, mask=blueMask)
        
        
    cv2.imshow('Imagem '+str(index+1)+'/'+str(l),cv2.resize(img,(int(1.5*img.shape[1]),int(1.5*img.shape[0])),interpolation=cv2.INTER_NEAREST))
    cv2.moveWindow('Imagem '+str(index+1)+'/'+str(l),int(1.5*img.shape[1])+64,32)
    
    cv2.imshow('Blue',cv2.resize(imgBlue,(int(1.5*img.shape[1]),int(1.5*img.shape[0])),interpolation=cv2.INTER_NEAREST))
    cv2.moveWindow('Blue',64,32)


    #Tempo para processar imagem
    k=cv2.waitKey(0)
    
    #Sai do programa
    if(k==ord('q')):
        running=0;

    #Vai para imagem anterior
    elif(k==ord('[')):
        cv2.destroyAllWindows()
        calc=1
        index-=1
        index=index%l
        label_pos=0
        
    #Vai para proxima imagem
    elif(k==ord(']')):
        cv2.destroyAllWindows()
        calc=1
        index+=1
        index=index%l
        label_pos=0
    
cv2.destroyAllWindows()