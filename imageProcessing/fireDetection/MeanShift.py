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
def rgbMeanShiftImageSeg(img, num_clusters, defaultColors, difThres):
    data = img.reshape(img.shape[0]*img.shape[1], 3)
    bandwidth = estimate_bandwidth(data, quantile=0.2, n_samples=500)
    mShift=MeanShift(bandwidth=bandwidth,bin_seeding=True)

    labels=mShift.fit_predict(data)
    img_labels=labels.reshape(img.shape[:2])
    centers=mShift.cluster_centers_
    return img_labels, centers

show=1
calc=1
index=0
running=1
img_list=[]
label_pos=0


#tonsMarrons = [(140,120,90),(60,40,10), (95,74,46)]
tonsMarrons = [(90,120,140),(10,40,60), (46,74,95)]
cinzaForte = [(200, 200, 195)]
branco = [(210,210,210)]


#Seleciona imagens
for file in os.listdir("1080p/"):
    img_list.append(os.path.join("1080p/", file))

l=len(img_list)



#Inicializacao para a janela de barras
bar=np.zeros((1,450,3),np.uint8)
cv2.namedWindow('Val')

#Cria as barras
cv2.createTrackbar('Off/On','Val',0,1,nothing)
cv2.setTrackbarPos('Off/On','Val',1)

cv2.imshow('Val',bar)
cv2.moveWindow('Val',0,0)



while running:
    cv2.setTrackbarPos('Off/On','Val',show)

    img = cv2.imread(img_list[index],1)
    #img = img[:, :, ::-1]
    ratio=get_ratio(img)

    #img=cv2.resize(img,ratio,interpolation=cv2.INTER_NEAREST)

    num_clusters = 5
    defaultColors = tonsMarrons
    #defaultColors = cinzaForte
    start_time = time.time()
    
    imgCont = img.copy()
    if show:
        if calc:
            calc=0
            labels, centers=rgbMeanShiftImageSeg(img, num_clusters, defaultColors, 30)
            print("--- %s seconds ---" % (time.time() - start_time))
            ###print('Area = {}%'.format(area))
        img_mask=(labels==label_pos)
        binImg = ndi.binary_closing(img_mask, iterations=1)
        #binImageTarget = (binImageTarget) | (binImg)
        imgAux = 255*(binImg).astype(np.uint8)
        
        _, contours, hierarchy = cv2.findContours(imgAux, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE,offset=(0, 0))
        
        #Calculando a area das queimadas
        whitePixels = sum(sum(binImg))
        totalPixels = binImg.shape[0]*binImg.shape[1]
        area = (100.0*whitePixels)/totalPixels
        print(str(label_pos)+' -> ['+str(int(centers[label_pos][0]))+','+str(int(centers[label_pos][1]))+','+str(int(centers[label_pos][2]))+']')
        print('Area = {0:.2f}%'.format(area))
        #Desenha os contornos na imagem
        cv2.drawContours(imgCont, contours, -1, (255, 255, 255), -1)
        cv2.addWeighted(img,0.75,imgCont,0.25,0,imgCont)

    

    cv2.imshow('Imagem '+str(index+1)+'/'+str(l),cv2.resize(imgCont,(2*imgCont.shape[1],2*imgCont.shape[0]),interpolation=cv2.INTER_NEAREST))
    #Tempo para processar imagem
    k=cv2.waitKey(0)
    
    #Sai do programa
    if(k==ord('q')):
        running=0;

    #Vai para imagem anterior
    elif(k==ord('[')):
        cv2.destroyWindow('Imagem '+str(index+1)+'/'+str(l))
        calc=1
        index-=1
        index=index%l
        label_pos=0
        
    #Vai para proxima imagem
    elif(k==ord(']')):
        cv2.destroyWindow('Imagem '+str(index+1)+'/'+str(l))
        calc=1
        index+=1
        index=index%l
        label_pos=0
    
    #Liga/Desliga Exibicao dos contornos
    elif(k==ord('f')):
        show+=1
        show=show%2
    elif(k==ord('-')):
        label_pos-=1
        label_pos=label_pos%len(centers)
    elif(k==ord('=')):
        label_pos+=1
        label_pos=label_pos%len(centers)
cv2.destroyAllWindows()