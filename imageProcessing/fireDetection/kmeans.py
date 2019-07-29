#Realiza os imports necessarios
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

# mouse callback function
def draw_circle(event,x,y,flags,param):
	global mouseX,mouseY
	if event == cv2.EVENT_LBUTTONDBLCLK:
		mouseX=x
		mouseY=y

def color_difference (color1, color2):
	# Retorna a distancia euclidiana entre duas cores no espaco RGB
	return math.sqrt(sum([(abs(component1-component2))**2 for component1, component2 in zip(color1, color2)]))

#Funcao retorna a imagem contornada e a area desmatada da mesma
def rgbKMeansImageSeg(img, num_clusters, difThres, it):
	
	#Define a proporcao entre os dois lados da imagem
	prop = img.shape[1]/img.shape[0]
	
	#Redimensiona a imagem para a mesma sempre ter 480 de altura, sem alterar as proporcoes
	imgResized = cv2.resize(img,(int(720*prop),720))


	#Reshape da imagem deixar como um vetor de pixels contendo as 3 cores para o mesmo
	data = imgResized.reshape(imgResized.shape[0]*imgResized.shape[1], 3)

	#Cria um agrupamento K-means e ajusta o mesmo aos dados
	km = KMeans(n_clusters=num_clusters)
	km.fit(data)
	
	#Salva os labels encontrados
	labels = km.predict(data)
	img_labels = labels.reshape(imgResized.shape[:2])
	
	'''
	#Define clusters que estao proximos as cores default passadas
	chosenColors = set()
	for i, clusterColor in enumerate(km.cluster_centers_):
		for color in defaultColors:
			dif = color_difference(color,clusterColor)
			if dif < difThres:
				chosenColors.add(i)
	#Transforma o set em lista para poder indexar
	chosenColors = list(chosenColors)
	
	#Cria a imagem binaria contendo o Target definido pelas cores padrao 
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
	'''
	return img_labels, km.cluster_centers_

def draw(img,center):
	inv=(255*(1-center[0]/127),255*(1-center[1]/127),255*(1-center[2]/127))

	cv2.rectangle(img,(0,0),(600,400),center,-1)

	cv2.line(img,(0,200),(600,200),inv,2)
	cv2.line(img,(200,0),(200,400),inv,2)
	cv2.line(img,(400,0),(400,400),inv,2)

	cv2.rectangle(img,(75,75),(125,125),(255,0,0),-1)
	cv2.rectangle(img,(75,275),(125,325),(0,255,0),-1)

	cv2.rectangle(img,(275,75),(325,125),(0,128,255),-1)
	cv2.rectangle(img,(275,275),(325,325),(0,128,0),-1)

	cv2.rectangle(img,(475,75),(525,125),(0,0,255),-1)
	cv2.rectangle(img,(475,275),(525,325),(0,0,0),-1)


	cv2.rectangle(img,(75,75),(125,125),inv)
	cv2.rectangle(img,(75,275),(125,325),inv)

	cv2.rectangle(img,(275,75),(325,125),inv)
	cv2.rectangle(img,(275,275),(325,325),inv)

	cv2.rectangle(img,(475,75),(525,125),inv)
	cv2.rectangle(img,(475,275),(525,325),inv)

	return img


global mouseX,mouseY
mouseX=-1
mouseY=-1
#AZUL,VERMELHO,LARANJA,VERDE_CLA,VERDE_ESC,PRETO
class_centers=[[],[],[],[],[],[]]
color_list=[(0,255,255),(255,0,0),(255,255,0),(255,0,255),(255,0,255),(255,255,255)]
color=np.zeros((400,600,3),np.uint8)
cv2.namedWindow('Centers')
cv2.setMouseCallback('Centers',draw_circle)

color=draw(color,(250,100,0))
cv2.imshow('Centers',color)

img = cv2.imread('1080p/CubeDesign_1.png',1)
#img = img[:, :, ::-1]

prop = img.shape[1]/img.shape[0]
imgResized = cv2.resize(img,(int(720*prop),720))


num_clusters = 6

start_time = time.time()
labels, centers = rgbKMeansImageSeg(img, num_clusters, 30, 1)

print("--- %s seconds ---" % (time.time() - start_time))

i=0
for center in centers:
	draw(color,center)
	cv2.imshow('Centers',color)
	mouseX=-600
	Col=-1
	while(Col<0):
		Col=(3*mouseX)/600
		Lin=(2*mouseY)/400
		cv2.waitKey(15)
	print(center)
	print(3*Lin+Col)
	#class_centers[3*Lin+Col].append(center)
	class_centers[3*Lin+Col].append(i)
	i+=1

running=1
show=1
calc=0
pos=0

while(running):
	imgCont = imgResized.copy()

	if show:
		if calc:
			pass

		binImg = np.zeros((imgResized.shape[0], imgResized.shape[1]),dtype=bool)
		for label in class_centers[pos]:
			img_mask = labels==label
			binImg = (binImg) | (img_mask)
		
		imgAux = 255*(binImg).astype(np.uint8)
	
		_, contours, hierarchy = cv2.findContours(imgAux, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE,offset=(0, 0))
		
		#Calculando a area das queimadas
		whitePixels = sum(sum(binImg))
		totalPixels = binImg.shape[0]*binImg.shape[1]
		area = (100.0*whitePixels)/totalPixels
		print(pos)
		print('Area = {0:.2f}%'.format(area))
		#Desenha os contornos na imagem
		
		cv2.drawContours(imgCont, contours, -1, color_list[pos], -1)
		cv2.addWeighted(imgResized,0.5,imgCont,0.5,0,imgCont)
	cv2.imshow('Image',imgCont)


	k=cv2.waitKey(0)
	if(k==ord('q')):
		running=0
	elif(k==ord('-')):
		pos-=1
		pos=pos%6
		show=1
	elif(k==ord('=')):
		pos+=1
		pos=pos%6
		show=1
	elif(k==ord(']')):
		pass
	elif(k==ord('[')):
		pass
	elif(k==ord('f')):
		show+=1
		show=show%2
cv2.destroyAllWindows()