#Realiza os imports necessários
import cv2
import numpy as np
import skimage.color
import matplotlib.pyplot as plt
import scipy.ndimage as ndi
from sklearn.cluster import KMeans
from sklearn.cluster import MeanShift
import matplotlib.patches as patches
import matplotlib.colors as colors
from skimage import io, color
import math
import time


#Define variáveis que serão as cores padrão para desmatamento
vermelho = (246,0,0)
laranja = (254, 128, 0)

def color_difference (color1, color2):
    # Retorna a distância euclidiana entre duas cores no espaço RGB
    return math.sqrt(sum([(abs(component1-component2))**2 for component1, component2 in zip(color1, color2)]))

#Função retorna a imagem contornada e a área desmatada da mesma
def rgbKMeansImageSeg(img, num_clusters, closeQueimada, itQueimada, closeDesmat, itDesmat, resize):
    
    #Define a proporção entre os dois lados da imagem
    prop = img.shape[1]/img.shape[0]
    
    #Redimensiona a imagem para a mesma sempre ter 480 de altura, sem alterar as proporções
    if resize:
        imgResized = cv2.resize(img,(round(480*prop),480))
    else:
        imgResized = img
    
    #Reshape da imagem deixar como um vetor de pixels contendo as 3 cores para o mesmo
    data = imgResized.reshape(imgResized.shape[0]*imgResized.shape[1], 3)

    #Cria um agrupamento K-means e ajusta o mesmo aos dados
    km = KMeans(n_clusters=num_clusters)
    km.fit(data)
    
    #Salva os labels encontrados
    labels = km.predict(data)
    img_labels = labels.reshape(imgResized.shape[:2])
    
    #Pega os indices das cores vermelho e laranja
    difVerm = [color_difference(p, vermelho) for p in km.cluster_centers_]
    indexQueimada = difVerm.index(min(difVerm))
    difLar = [color_difference(p, laranja) for p in km.cluster_centers_]
    indexDesmat = difLar.index(min(difLar))
    
    
    binQueimada = img_labels==indexQueimada
    if closeQueimada:
        binQueimada = ndi.binary_closing(binQueimada, iterations=itQueimada)
    binDesmat = img_labels==indexDesmat
    if closeDesmat:
        binDesmat = ndi.binary_closing(binDesmat, iterations=itDesmat)
    
    #Analise de desmatamento ###################################
    imgContornada = imgResized.copy()
    imgAux = 255*(binDesmat).astype(np.uint8)

    _, contours, hierarchy = cv2.findContours(imgAux, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE,offset=(0, 0))
    
    #Desenha os contornos na imagem
    cv2.drawContours(imgContornada, contours, -1, (255, 255, 0), 3)
    
    #Calculando a area das queimadas
    areaCalc = 0.0
    for con in contours:    
        areaCalc += cv2.contourArea(con)
    
    whitePixels = sum(sum(binDesmat))
    totalPixels = imgResized.shape[0]*imgResized.shape[1]
    area = round((whitePixels/totalPixels)*100, 2)
    area2 = round((areaCalc/totalPixels)*100, 2)
    ########################################################
    
    
    #Analise de queimada ###################################
    imgAux = 255*(binQueimada).astype(np.uint8)
    ret, labels = cv2.connectedComponents(imgAux)
    
    
    
    #Analise de desmatamento ###################################
    imgContornada2 = imgResized.copy()
    imgAux = 255*(binQueimada).astype(np.uint8)

    _, contours, hierarchy = cv2.findContours(imgAux, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE,offset=(0, 0))
    
    #Desenha os contornos na imagem
    cv2.drawContours(imgContornada2, contours, -1, (0, 255, 255), 3)
    
    ########################################################
    
    return imgContornada, imgContornada2, area, area2, ret, labels



#img = cv2.imread('CubeDesign_Mission_4x3_IMG-CAL.png',1)
img = cv2.imread('CubeDesign_Mission_IMG-CAL.png',1)
img = img[:, :, ::-1]
start_time = time.time()
imagemCont,imagemCont2, area, area2, ret, labels = rgbKMeansImageSeg(img, 6, False, 1, False, 1, False)
print("--- %s seconds ---" % (time.time() - start_time))