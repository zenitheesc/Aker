# -*- coding: UTF-8 -*-
import Tkinter as tk
import tkFileDialog as filedialog
from io import StringIO
import requests
import subprocess
import arff
import scipy.ndimage as ndi
import pandas as pd
import os,os.path
import cv2
import numpy as np
from scipy import ndimage
from sklearn.cluster import KMeans
		
#Funcao de troca de frame
# Toda vez que ela é chamada, muda-se o frame que esta no topo sendo
# mostrado ao usuário.
def raise_frame(frame):
	if(frame == menu):
		print("foi para menu")
	elif(frame == crop):
		print("foi para crop")
	elif(frame == createDatabase):
		print("foi para createDatabase")
	elif(frame == supervised):
		print("foi para supervised")
	elif(frame == auto):
		print("foi para automatico")
	elif(frame == manual):
		print("foi para manual")
	frame.tkraise()    



##############
#Area do MENU#
##############    

#Globais
defaultColorButton = ""

def sair():
	global window
	window.destroy()

def configureMenu():
	
	text1 = tk.Label(menu, text = "Menu", font='Helvetica 18 bold').place(relx=0.5,y=15,anchor = tk.CENTER)
	
	
	#instrCrop = "CROP: se refere ao processo de cortar uma imagem para isolar apenas a imagem que o INPE\
	#            disponibilizou. Neste modo o usuário escolher uma imagem e nela seleciona 4 pontos\
	#            que serão utilizados para cortar aquela parte da imagem tranformando-a em um retangulo"
	#textCrop = tk.Label(menu, text = instrCrop, wraplength=(largura - 50))
	#textCrop.place(relx=0.5,rely=0.1,anchor = tk.CENTER)
	btCrop = tk.Button(menu, text='Crop', command=lambda:raise_frame(crop), width=20)
	btCrop.place(relx=0.50, rely = 0.3 ,anchor = tk.CENTER)
	# Pega cor padrão do botao
	defaultColorButton = btCrop['bg']
	
	btCreateDatabase = tk.Button(menu, text='Criar Base de Dados', command=lambda:raise_frame(createDatabase), width=20)
	btCreateDatabase.place(relx=0.50, rely = 0.4 ,anchor = tk.CENTER)
		
	btUnsupervised = tk.Button(menu, text='Automatico', command=lambda:raise_frame(auto), width=20)
	btUnsupervised.place(relx=0.50, rely = 0.5 ,anchor = tk.CENTER)

	btSupervised = tk.Button(menu, text='Supervisionado', command=lambda:raise_frame(supervised), width=20)
	btSupervised.place(relx=0.50, rely = 0.6 ,anchor = tk.CENTER)

	btUnsupervised = tk.Button(menu, text='Manual', command=lambda:raise_frame(manual), width=20)
	btUnsupervised.place(relx=0.50, rely = 0.7 ,anchor = tk.CENTER)
	
	btExit = tk.Button(menu, text='SAIR', command=lambda:sair(), width=20)
	btExit.place(relx=0.50, rely = 0.9 ,anchor = tk.CENTER)

#####################
#Fim da Area do MENU#
#####################



########################
#Inicio da Area do CROP#
########################

#Globais
imgFile = ""
whereToSaveCropped = ""
mouseX = -1
mouseY = -1

def selectImage(textChooseImage):
	global imgFile
	text = filedialog.askopenfilename(title = "Escolha a imagem",filetypes = (("png files","*.png"),("jpg files","*.jpg"),("jpeg files","*.jpeg"),("all files","*.*")))
	print(text[-4:])
	print(text[-4:] == ".png")
	if(text[-4:] == ".png" or text[-4:] == ".jpg" or text[-5:] == ".jpeg"):
		print("aqui")
		textChooseImage['text'] = text
		imgFile = text
	else:
		print("aqui2")
		textChooseImage['text'] = 'Arquivo escolhido não é imagem'
		#Avisar do erro
		
def chooseWhereToSaveCropped(textCroppedImage):
	global whereToSaveCropped
	text = filedialog.asksaveasfilename(title = "De um nome ao arquivo novo",defaultextension=".png")
	whereToSaveCropped = text
	textCroppedImage['text'] = text

def four_point_transform(image, pts):
	# obtain a consistent order of the points and unpack them
	# individually
	rect = order_points(pts)
	(tl, tr, br, bl) = rect
 
	# compute the width of the new image, which will be the
	# maximum distance between bottom-right and bottom-left
	# x-coordiates or the top-right and top-left x-coordinates
	widthA = np.sqrt(((br[0] - bl[0]) ** 2) + ((br[1] - bl[1]) ** 2))
	widthB = np.sqrt(((tr[0] - tl[0]) ** 2) + ((tr[1] - tl[1]) ** 2))
	maxWidth = max(int(widthA), int(widthB))
 
	# compute the height of the new image, which will be the
	# maximum distance between the top-right and bottom-right
	# y-coordinates or the top-left and bottom-left y-coordinates
	heightA = np.sqrt(((tr[0] - br[0]) ** 2) + ((tr[1] - br[1]) ** 2))
	heightB = np.sqrt(((tl[0] - bl[0]) ** 2) + ((tl[1] - bl[1]) ** 2))
	maxHeight = max(int(heightA), int(heightB))
 
	# now that we have the dimensions of the new image, construct
	# the set of destination points to obtain a "birds eye view",
	# (i.e. top-down view) of the image, again specifying points
	# in the top-left, top-right, bottom-right, and bottom-left
	# order
	dst = np.array([
		[0, 0],
		[maxWidth - 1, 0],
		[maxWidth - 1, maxHeight - 1],
		[0, maxHeight - 1]], dtype = "float32")
 
	# compute the perspective transform matrix and then apply it
	M = cv2.getPerspectiveTransform(rect, dst)
	warped = cv2.warpPerspective(image, M, (maxWidth, maxHeight))
 
	# return the warped image
	return warped

# mouse callback function
def get_click(event,x,y,flags,param):
	global mouseX,mouseY
	if event == cv2.EVENT_LBUTTONDBLCLK:
		mouseX=x
		mouseY=y

def order_points(pts):
	# initialzie a list of coordinates that will be ordered
	# such that the first entry in the list is the top-left,
	# the second entry is the top-right, the third is the
	# bottom-right, and the fourth is the bottom-left
	rect = np.zeros((4, 2), dtype = "float32")
 
	# the top-left point will have the smallest sum, whereas
	# the bottom-right point will have the largest sum
	s = pts.sum(axis = 1)
	rect[0] = pts[np.argmin(s)]
	rect[2] = pts[np.argmax(s)]
 
	# now, compute the difference between the points, the
	# top-right point will have the smallest difference,
	# whereas the bottom-left will have the largest difference
	diff = np.diff(pts, axis = 1)
	rect[1] = pts[np.argmin(diff)]
	rect[3] = pts[np.argmax(diff)]
 
	# return the ordered coordinates
	return rect
	
	
def cropImage():
	global imgFile, mouseX, mouseY
	mouseX=-1
	mouseY=-1

	border=[]
	cv2.namedWindow('image')
	cv2.setMouseCallback('image',get_click)
	img = cv2.imread(imgFile)
	cv2.imshow('image',img)
	
	i=0
	prevX=mouseX
	prevY=mouseY
	while(i<4):
		cv2.waitKey(25)
		if(mouseX!=prevX or mouseY!=prevY):
			prevX=mouseX
			prevY=mouseY
			print(str(mouseX)+','+str(mouseY))
			border.append([mouseX,mouseY])
			i+=1
	
	#Transformando e salvando a nova imagem
	pts=np.array(eval(str(border)),dtype="float32")
	warped=four_point_transform(img,pts)
	cv2.imwrite(whereToSaveCropped,warped)
	
	cv2.destroyAllWindows()

def configureCrop():

	text1 = tk.Label(crop, text = "Crop", font='Helvetica 18 bold').place(relx=0.5,y=15,anchor = tk.CENTER)
	
	textChooseImage = tk.Label(crop, text = imgFile, wraplength=(largura - 20))
	textChooseImage.place(relx=0.5,rely=0.3,anchor = tk.CENTER)
	
	btSelectImageCrop = tk.Button(crop, text='Selecionar Imagem', command=lambda:selectImage(textChooseImage), width=20)
	btSelectImageCrop.place(relx=0.50, rely = 0.2 ,anchor = tk.CENTER)
	
	textCroppedImage = tk.Label(crop, text = whereToSaveCropped, wraplength=(largura - 20))
	textCroppedImage.place(relx=0.5,rely=0.5,anchor = tk.CENTER)
	
	btWhereToSaveCrop = tk.Button(crop, text='Onde Salvar', command=lambda:chooseWhereToSaveCropped(textCroppedImage), width=20)
	btWhereToSaveCrop.place(relx=0.50, rely = 0.4 ,anchor = tk.CENTER)
	
	btCut = tk.Button(crop, text='Cortar', command=lambda:cropImage(), width=20)
	btCut.place(relx=0.50, rely = 0.8 ,anchor = tk.CENTER)
	
	btBack = tk.Button(crop, text='Voltar ao menu', command=lambda:raise_frame(menu), width=20)
	btBack.place(relx=0.50, rely = 0.9 ,anchor = tk.CENTER)
	
#####################
#Fim da Area do CROP#
#####################



###################################
#Inicio da Area do CREATE_DATABASE#
###################################

#Globais
fileToCreateDB = ""
whereToSaveDB = ""
imgFiles = []

def selectImagesForDB():
	global imgFiles
	listOfImages = filedialog.askopenfilenames(title = "Escolha as imagens para compor a base",filetypes = (("png files","*.png"),("jpg files","*.jpg"),("jpeg files","*.jpeg"),("all files","*.*")))
	imgFiles = listOfImages
	print(imgFiles)

def selectDB(textChooseDB):
	global fileToCreateDB
	text = filedialog.askopenfilename(title = "Escolha uma base de dados ou crie uma",filetypes = (("csv files","*.csv"),("all files","*.*")))
	print(text[-4:])
	print(text[-4:] == ".png")
	if(text[-4:] == ".csv"):
		textChooseDB['text'] = text
		fileToCreateDB = text
	else:
		textChooseDB['text'] = 'Arquivo escolhido não é base de dados'
		#Avisar do erro
		
def chooseWhereToSaveDB(textSavedDB):
	global whereToSaveDB
	text = filedialog.asksaveasfilename(title = "De um nome ao arquivo novo",defaultextension=".csv")
	whereToSaveDB = text
	textSavedDB['text'] = text
	
def createDB():
	global fileToCreateDB
	global whereToSaveDB
	global imgFiles
	
	image = cv2.imread(img_list[index])
	
def configureCreateDatabase():
	text1 = tk.Label(createDatabase, text = "Cria base de dados", font='Helvetica 18 bold').place(relx=0.5,y=15,anchor = tk.CENTER)
	
	textChooseDB = tk.Label(createDatabase, text = fileToCreateDB, wraplength=(largura - 20))
	textChooseDB.place(relx=0.5,rely=0.3,anchor = tk.CENTER)
	
	btCrop = tk.Button(createDatabase, text='Selecionar Base de Dados', command=lambda:selectDB(textChooseDB), width=20)
	btCrop.place(relx=0.50, rely = 0.2 ,anchor = tk.CENTER)
	
	textSavedDB = tk.Label(createDatabase, text = whereToSaveDB, wraplength=(largura - 20))
	textSavedDB.place(relx=0.5,rely=0.5,anchor = tk.CENTER)
	
	btWhereToSave = tk.Button(createDatabase, text='Onde Salvar', command=lambda:chooseWhereToSaveDB(textSavedDB), width=20)
	btWhereToSave.place(relx=0.50, rely = 0.4 ,anchor = tk.CENTER)
	
	btSelectImagesForDB = tk.Button(createDatabase, text='Selecionar imagens', command=lambda:selectImagesForDB(), width=20)
	btSelectImagesForDB.place(relx=0.50, rely = 0.6 ,anchor = tk.CENTER)
	
	btSaveSB = tk.Button(createDatabase, text='Salvar', command=lambda:createDB(), width=20)
	btSaveSB.place(relx=0.50, rely = 0.8 ,anchor = tk.CENTER)
	
	
	btBack = tk.Button(createDatabase, text='Voltar ao menu', command=lambda:raise_frame(menu), width=20)
	btBack.place(relx=0.50, rely = 0.9 ,anchor = tk.CENTER)
	
	
################################
#Fim da Area do CREATE_DATABASE#
################################    



################################
#Inicio da Area do UNSUPERVISED#
################################

# Abre uma janela para selecionar o arquivo da imagem a ser usada
# Essa imagem é carregada em BGR e é retornado a versão BGR, HSV e LAB
# nesta ordem
def getImages():
	global imgFile
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
	area = round(float(100*whitePixels)/totalPixels, 2)
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
def autoClaro(label):	
	imgBGR, imgHSV, imgLAB = getImages()

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
	
	labels, nro = calcFires(img_mask_Red, 2)
   
	label['text']="Area:{}%".format(calcDeforestation(img_mask_Orange))+"\nFocos:{}".format(nro)


def autoEscuro(label):
	imgBGR, imgHSV, imgLAB = getImages()

	#Realiza o primeiro kmeans para separar apenas as cores vermelho e laranja
	labels1, centers1 = firstKmeans(imgBGR)

	#Identifica qual o cluster das cores vermelho e laranja
	clusRedOrange = getLabelRedRGB(centers1)

	#Cria uma mascara do cluster vermelho e laranja
	img_mask_RandO = labels1==clusRedOrange
	# Faz um segundo k means para separar as duas cores
	labels2, centers2 = secondKmeans(imgBGR, img_mask_RandO)
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
	
	labels, nro = calcFires(img_mask_Red, 0)

	label['text']="Area:{}%".format(calcDeforestation(img_mask_Orange))+"\nFocos:{}".format(nro)

def configureAuto():
	text1 = tk.Label(auto, text = "Automatico", font='Helvetica 18 bold').place(relx=0.5,y=15,anchor = tk.CENTER)
	
	textAutoImage = tk.Label(auto, text = supImgFile, wraplength=(largura - 20))
	textAutoImage.place(relx=0.5,rely=0.4,anchor = tk.CENTER)
	
	btSelectImageAuto = tk.Button(auto, text='Selecionar Imagem', command=lambda:selectImage(textAutoImage), width=20)
	btSelectImageAuto.place(relx=0.50, rely = 0.3 ,anchor = tk.CENTER)

	textAutoDados=tk.Label(auto,text="Area:\nFocos:",wraplength=(largura-20))
	textAutoDados.place(relx=0.5,rely=0.7,anchor=tk.CENTER)

	btCut = tk.Button(auto, text='Modo Claro', command=lambda:autoClaro(textAutoDados), width=20)
	btCut.place(relx=0.25, rely = 0.55 ,anchor = tk.CENTER)

	btCut = tk.Button(auto, text='Modo Escuro', command=lambda:autoEscuro(textAutoDados), width=20)
	btCut.place(relx=0.75, rely = 0.55 ,anchor = tk.CENTER)

	btBack = tk.Button(auto, text='Voltar ao menu', command=lambda:raise_frame(menu), width=20)
	btBack.place(relx=0.50, rely = 0.9 ,anchor = tk.CENTER)

#############################
#Fim da Area do UNSUPERVISED#
#############################
	
	
	
##############################
#Inicio da Area do SUPERVISED#
##############################

#Globais
supImgFile = ""
supDBFile = ""

def configureSupervised():
	text1 = tk.Label(supervised, text = "Supervisionado", font='Helvetica 18 bold').place(relx=0.5,y=15,anchor = tk.CENTER)
	
	textSupImage = tk.Label(supervised, text = supImgFile, wraplength=(largura - 20))
	textSupImage.place(relx=0.5,rely=0.3,anchor = tk.CENTER)
	
	btSelectImageSup = tk.Button(supervised, text='Selecionar Imagem', command=lambda:selectImage(textSupImage), width=20)
	btSelectImageSup.place(relx=0.50, rely = 0.2 ,anchor = tk.CENTER)
	
	textSupDB = tk.Label(supervised, text = supDBFile, wraplength=(largura - 20))
	textSupDB.place(relx=0.5,rely=0.5,anchor = tk.CENTER)
	
	btWhereToSave = tk.Button(supervised, text='Selecionar Base de Dados', command=lambda:selectDB(textSupDB), width=20)
	btWhereToSave.place(relx=0.50, rely = 0.4 ,anchor = tk.CENTER)
	
	btGetArea = tk.Button(supervised, text='Área', command=lambda:cropImage(), width=10)
	btGetArea.place(relx=0.25, rely = 0.6 ,anchor = tk.CENTER)
	
	btGetPos = tk.Button(supervised, text='Posições', command=lambda:cropImage(), width=10)
	btGetPos.place(relx=0.75, rely = 0.6 ,anchor = tk.CENTER)
	
	#btShowMask = tk.Button(supervised, text='Mostrar máscara?', command=lambda:cropImage(), width=10)
	#btShowMask.place(relx=0.5, rely = 0.6 ,anchor = tk.CENTER)
	
	spinBox = tk.Spinbox(supervised, from_=0, to=10)
	spinBox.place(relx = 0.35, rely = 0.7)
	
	btBack = tk.Button(supervised, text='Voltar ao menu', command=lambda:raise_frame(menu), width=20)
	btBack.place(relx=0.50, rely = 0.9 ,anchor = tk.CENTER)
	

###########################
#Fim da Area do SUPERVISED#
########################### 



##########################
#Inicio da Area do MANUAL#
##########################

def color_difference (color1, color2):
	# Retorna a distancia euclidiana entre duas cores no espaco RGB
	return math.sqrt(sum([(abs(component1-component2))**2 for component1, component2 in zip(color1, color2)]))

#Funcao retorna a imagem contornada e a area desmatada da mesma
def rgbKMeansImageSeg(img, num_clusters, difThres, it):
	
	#Reshape da imagem deixar como um vetor de pixels contendo as 3 cores para o mesmo
	data = img.reshape(img.shape[0]*img.shape[1], 3)

	#Cria um agrupamento K-means e ajusta o mesmo aos dados
	km = KMeans(n_clusters=num_clusters)
	km.fit(data)
	
	#Salva os labels encontrados
	labels = km.predict(data)
	img_labels = labels.reshape(img.shape[:2])
	
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

def classifyCenters(num_clusters,txtLabel):
	global mouseX,mouseY,imgFile
	mouseX=-1
	mouseY=-1
	
	#AZUL,VERMELHO,LARANJA,VERDE_CLA,VERDE_ESC,PRETO
	class_centers=[[],[],[],[],[],[]]
	color=np.zeros((400,600,3),np.uint8)
	cv2.namedWindow('Centers')
	cv2.setMouseCallback('Centers',get_click)

	img = cv2.imread(imgFile)

	if(img.shape[0]>img.shape[1]):
		prop = float(img.shape[1])/img.shape[0]
		imgResized = cv2.resize(img,(int(prop*720),720))
	else:
		prop = float(img.shape[0])/img.shape[1]
		imgResized = cv2.resize(img,(720,int(prop*720)))

	cv2.imshow('Image',imgResized)
	cv2.moveWindow('Image',670,0)


	labels, centers = rgbKMeansImageSeg(imgResized, num_clusters, 30, 1)

	i=0
	for center in centers:
		draw(color,center)
		cv2.imshow('Centers',color)
		cv2.moveWindow('Centers',0,0)
		

		inv=(255*(1-center[0]/127),255*(1-center[1]/127),255*(1-center[2]/127))
		background = np.zeros((imgResized.shape[0], imgResized.shape[1],3),np.uint8)
		cv2.rectangle(background,(0,0),(imgResized.shape[1], imgResized.shape[0]),inv,-1)

		mask=(labels==i)
		#binImg = 255*(mask).astype(np.uint8)
		
		
		background[mask]=imgResized[mask]

		cv2.imshow('Masked',background)
		cv2.moveWindow('Masked',670,720)
		
		mouseX=-600
		Col=-1
		while(Col<0):
			Col=(3*mouseX)/600
			Lin=(2*mouseY)/400
			cv2.waitKey(15)
		class_centers[3*Lin+Col].append(i)
		i+=1

	cv2.destroyAllWindows()

	binImg = np.zeros((imgResized.shape[0], imgResized.shape[1]),dtype=bool)
	for label in class_centers[1]:
		mask = labels==label
		print(label)
		print(class_centers[1])
		binImg = (binImg) | (mask)
	area=calcDeforestation(binImg) #1

	binImg = np.zeros((imgResized.shape[0], imgResized.shape[1]),dtype=bool)
	for label in class_centers[2]:
		mask = labels==label
		binImg = (binImg) | (mask)
	labels, nro=calcFires(binImg,0) #2

	txtLabel['text']="Area:{}%".format(area)+"\nFocos:{}".format(nro)

def configureManual():
	text1 = tk.Label(manual, text = "Manual", font='Helvetica 18 bold').place(relx=0.5,y=15,anchor = tk.CENTER)
	
	textManImage = tk.Label(manual, text = supImgFile, wraplength=(largura - 20))
	textManImage.place(relx=0.5,rely=0.35,anchor = tk.CENTER)

	btSelectImageMan = tk.Button(manual, text='Selecionar Imagem', command=lambda:selectImage(textManImage), width=20)
	btSelectImageMan.place(relx=0.5, rely = 0.27 ,anchor = tk.CENTER)

	textManDados=tk.Label(manual,text="Area:\nFocos:",wraplength=(largura-20))
	textManDados.place(relx=0.5,rely=0.8,anchor=tk.CENTER)

	textSpinBox=tk.Label(manual,text="Numero de Centros:",wraplength=(largura-20))
	textSpinBox.place(relx=0.5,rely=0.475,anchor=tk.CENTER)
	
	spinBox = tk.Spinbox(manual, from_=1, to=16)
	spinBox.place(relx = 0.35, rely = 0.5)
	spinBox.insert(0,8)
	spinBox.delete(1)

	btCut = tk.Button(manual, text='Classificar centros', command=lambda:classifyCenters(int(spinBox.get()),textManDados), width=20)
	btCut.place(relx=0.50, rely = 0.65 ,anchor = tk.CENTER)

	btBack = tk.Button(manual, text='Voltar ao menu', command=lambda:raise_frame(menu), width=20)
	btBack.place(relx=0.50, rely = 0.9 ,anchor = tk.CENTER)



#######################
#Fim da Area do MANUAL#
####################### 



#####################
#        MAIN       #
#####################
	

# Cria a janela em que a interface irá rodar
largura = 600
altura = 400
window = tk.Tk()
window.title('Zenith - Missão INPE')
window.geometry(str(largura) + "x" + str(altura) + "+100+100")
window.resizable(0, 0) 

#Cria frames da interface
menu = tk.Frame(window,width=largura, height=altura)
crop = tk.Frame(window,width=largura, height=altura)
createDatabase = tk.Frame(window,width=largura, height=altura)
supervised = tk.Frame(window,width=largura, height=altura)
auto = tk.Frame(window,width=largura, height=altura)
manual = tk.Frame(window,width=largura, height=altura)

# Gruda os frames para que todos fechem juntos
for frame in (menu, crop, createDatabase, supervised, auto, manual):
	frame.grid(row=0, column=0, sticky='news')

#Configura todos os frames
configureMenu()
configureCrop()
configureCreateDatabase()
configureSupervised()
configureAuto()
configureManual()

#Inicia no frame do MENU
raise_frame(menu)

#Loop da interface
window.mainloop()
