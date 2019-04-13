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


def color_difference (color1, color2):
    # Retorna a distância euclidiana entre duas cores no espaço RGB
    return math.sqrt(sum([(abs(component1-component2))**2 for component1, component2 in zip(color1, color2)]))

#Função retorna a imagem contornada e a área desmatada da mesma
def rgbKMeansImageSeg(img, num_clusters, defaultColors, difThres, it):
    
    #Define a proporção entre os dois lados da imagem
    prop = img.shape[1]/img.shape[0]
    
    #Redimensiona a imagem para a mesma sempre ter 480 de altura, sem alterar as proporções
    imgResized = cv2.resize(img,(round(480*prop),480))
    
    #Reshape da imagem deixar como um vetor de pixels contendo as 3 cores para o mesmo
    data = imgResized.reshape(imgResized.shape[0]*imgResized.shape[1], 3)

    #Cria um agrupamento K-means e ajusta o mesmo aos dados
    km = KMeans(n_clusters=num_clusters)
    km.fit(data)
    
    #Salva os labels encontrados
    labels = km.predict(data)
    img_labels = labels.reshape(imgResized.shape[:2])
    
    #Define clusters que estão próximos as cores default passadas
    chosenColors = set()
    for i, clusterColor in enumerate(km.cluster_centers_):
        for color in defaultColors:
            dif = color_difference(color,clusterColor)
            if dif < difThres:
                chosenColors.add(i)
    #Transforma o set em lista para poder indexar
    chosenColors = list(chosenColors)
    
    #Prints de teste - APAGAR DEPOIS
    #print(km.cluster_centers_)
    #print(chosenColors)
    
    #Cria a imagem binaria contendo o Target definido pelas cores padrão 
    binImageTarget = np.zeros((imgResized.shape[0], imgResized.shape[1]),dtype=bool)
    for label in chosenColors:
        img_mask = img_labels==label
        #PRECISA DO CLOSING????
        binImg = ndi.binary_closing(img_mask, iterations=it)
        #binImg = img_mask
        binImageTarget = (binImageTarget) | (binImg)
        
    imgContourned = imgResized.copy()
    imgAux = 255*(binImageTarget).astype(np.uint8)
    border = cv2.copyMakeBorder(imgAux, 1, 1, 1, 1, cv2.BORDER_CONSTANT, value=0 )

    _, contours, hierarchy = cv2.findContours(imgAux.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE,offset=(0, 0))
    
    #Desenha os contornos na imagem
    cv2.drawContours(imgContourned, contours, -1, (255, 0, 0), 1)
    
    #Calculando a area das queimadas
    whitePixels = sum(sum(binImageTarget))
    totalPixels = binImageTarget.shape[0]*binImageTarget.shape[1]
    area = round((whitePixels/totalPixels)*100, 2)
    
    return imgContourned, area



tonsMarrons = [(140,120,90),(60,40,10), (95,74,46)]
cinzaForte = [(202, 199, 193)]
branco = [(210,210,210)]

#img = cv2.imread('Imagens/def2.jpg',1)
#img = cv2.imread('Imagens/Alta_Floresta_AMO_2007217_lrg.jpg',1)
img = cv2.imread('Imagens/Brazil.A2003181.1720_lrg.jpg',1)
img = img[:, :, ::-1]

num_clusters = 5
defaultColors = tonsMarrons
#defaultColors = cinzaForte
start_time = time.time()
imagemCont, area = rgbKMeansImageSeg(img, num_clusters, defaultColors, 30, 1)
print("--- %s seconds ---" % (time.time() - start_time))

print('Area = {}%'.format(area))

plt.figure(figsize=(15,15))
plt.imshow(imagemCont)
plt.savefig('image.png')