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
from sklearn.neighbors import KNeighborsClassifier
		
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
	global defaultColorButton
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
imgFiles = []
append = False
mode = 0
db = pd.DataFrame()
refPt = []
image = []
clone = []

mode_DEBUG=0

def selectImagesForDB(textImages):
	global imgFiles
	listOfImages = filedialog.askopenfilenames(title = "Escolha as imagens para compor a base",filetypes = (("png files","*.png"),("jpg files","*.jpg"),("jpeg files","*.jpeg"),("all files","*.*")))
	imgFiles = listOfImages
	print(imgFiles)
	if(len(imgFiles) > 0):
		textImages['text'] = 'Imagens coletadas com sucesso'
	else:
		textImages['text'] = 'Imagens não foram escolhidas'

def selectDB(textChooseDB):
	global fileToCreateDB
	text = filedialog.asksaveasfilename(title = "Escolha uma base de dados ou crie uma",filetypes = (("csv files","*.csv"),("all files","*.*")))
	if(text[-4:] == ".csv"):
		textChooseDB['text'] = text
		fileToCreateDB = text
	else:
		textChooseDB['text'] = 'Arquivo escolhido não é base de dados'
	
def appendControl(btAppend):
	global append
	if(append == True):
		append = False
		btAppend['bg'] = defaultColorButton
	else:
		append = True
		btAppend['bg'] = '#7ccd7c'

def click_and_crop(event, x, y, flags, param):
	# Faz referencias as variáveis globais dentro da função
	global db
	global mode
	global refPt
	global image
	global clone
 
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
		# Apertando '1' o usuário adiciona aquela cor na base como vermelho
		# Apertando '0' o usuário adiciona aquela cor na base como laranja
		# Apertando ESC o usuário cancela aquela ação
		while True:
			keyColor = cv2.waitKey(20)
			if keyColor == 27 or keyColor == ord('q'):
				cv2.destroyWindow('ROI')
				break
			elif keyColor == ord("0"):
				print("Other color")
				vet = np.concatenate([roi[0,0,:], roiHSV[0,0,:], roiLAB[0,0,:], [0]])
				db = db.append(pd.Series(vet, index=db.columns ), ignore_index=True)
				cv2.destroyWindow('ROI')
				break
			elif keyColor == ord("1"):
				print("Target color")
				vet = np.concatenate([roi[0,0,:], roiHSV[0,0,:], roiLAB[0,0,:], [1]])
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
		# Apertando '1' o usuário adiciona aquela cor na base como vermelho
		# Apertando '0' o usuário adiciona aquela cor na base como laranja
		# Apertando ESC o usuário cancela aquela ação
		while True:
			keyColor = cv2.waitKey(20)
			if keyColor == 27 or keyColor == ord('q'):
				cv2.destroyWindow('ROI')
				break
			elif keyColor == ord("0"):
				print("Outra Cor")
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
			elif keyColor == ord("1"):
				print("Target color")
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


def criaBase():
	global append
	global fileToCreateDB
	global imgFiles
	global mode
	global db
	global image
	global clone

	#Checa se deve fazer append ou nao
	if(append):
		db = pd.read_csv(fileToCreateDB, sep='\t')
		print(db)
	else:
		db = pd.DataFrame(columns=['Bl', 'G', 'R', 'H', 'S', 'V', 'L', 'A','B', 'Color'])

	#Seleciona imagens
	index=0
	img_list=imgFiles
	border=[]

	# mode controla o tipo de seleção de pixels,
	# podendo esta ser em area (clicando e arrastando)
	# ou por pixel expecífico
	mode = 0

	l=len(imgFiles)

	# Cria uma nova janela do OpenCV
	cv2.namedWindow('image',cv2.WINDOW_NORMAL)
	cv2.moveWindow('image', 700, 500)
	cv2.resizeWindow('image', 800,800)
	# Comando designado para o mouse esta associado a função click_and_crop
	cv2.setMouseCallback("image", click_and_crop)
	
	
	while True:
		image = cv2.imread(img_list[index])
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
		
		# Muda para a imagem anterior
		elif(key == ord('[') or key == 81):
			index-=1
			index%=l

		# Muda para a próxima imagem
		elif(key == ord(']') or key == 83):
			index+=1
			index%=l

		# Salva a base de dados criada no programa
		# Futuramente na interface precisamos mudar o nome deste arquivo
		elif(key == ord('s')):
			print('salvando')
			db.to_csv(fileToCreateDB, sep='\t', index=False)
			break

	cv2.destroyAllWindows()
	
def configureCreateDatabase():
	text1 = tk.Label(createDatabase, text = "Cria base de dados", font='Helvetica 18 bold').place(relx=0.5,y=15,anchor = tk.CENTER)
	
	textImages = tk.Label(createDatabase, text = '', wraplength=(largura - 20))
	textImages.place(relx=0.5,rely=0.3,anchor = tk.CENTER)
	
	btSelectImagesForDB = tk.Button(createDatabase, text='Selecionar imagens', command=lambda:selectImagesForDB(textImages), width=20)
	btSelectImagesForDB.place(relx=0.50, rely = 0.2 ,anchor = tk.CENTER)
	
	textSavedDB = tk.Label(createDatabase, text = '', wraplength=(largura - 20))
	textSavedDB.place(relx=0.5,rely=0.5,anchor = tk.CENTER)
	
	btWhereToSave = tk.Button(createDatabase, text='Selecionar base', command=lambda:selectDB(textSavedDB), width=20)
	btWhereToSave.place(relx=0.50, rely = 0.4 ,anchor = tk.CENTER)

	btAppend = tk.Button(createDatabase, text='Append', command=lambda:appendControl(btAppend), width=20)
	btAppend.place(relx=0.50, rely = 0.6 ,anchor = tk.CENTER)
	
	btSaveSB = tk.Button(createDatabase, text='Rodar', command=lambda:criaBase(), width=20)
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
	num_clusters = 7
	
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
	num_clusters = 7

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
	maxVerm=0
	clusVerm=[]
	for i in range(1,len(centers)):
		if centers[i][2] > maxVerm:
			maxVerm=centers[i][2]
	
	for i in range(1,len(centers)):
		if centers[i][2] >= (0.5*maxVerm):
			if((centers[i][2]>centers[i][0]) and (centers[i][2]>centers[i][1])):
				clusVerm.append(i)
	
	return clusVerm



# Acha qual o label que contem as cores vermelho e laranja
# Separa esse cluster verificando qual cluster possui o maior valor vermelho
# do espectro BGR
def getLabelGreenRGB(centers):
	global mode_DEBUG
	maxVerd=0
	clusVerd=[]
	for i in range(1,len(centers)):
		if centers[i][1] > maxVerd:
			maxVerd=centers[i][1]
	if(mode_DEBUG):
		print(maxVerd)
	for i in range(1,len(centers)):
		if(mode_DEBUG):
			print(centers)
		if centers[i][1] >= (0.4*maxVerd):
			if((centers[i][1]>centers[i][0]) and (centers[i][1]>centers[i][2])):
				clusVerd.append(i)
	if(mode_DEBUG):
		print("\n\n")
	
	return clusVerd


# Faz o kmeans utilizando a imagem LAB apenas
# essa segunda clusterização recebe uma mascara, para evitar que
# outras cores alem de laranja e vermelho estejam na imagem.
# São clusterizados 10 clusters, porém futuramente estes serão agrupados
# selecionando qual é vermelho e qual é laranja, excluido a parte preta da imagem
# Retorna os centros e os labels da clusterização
def secondKmeans(imgBGR, img_mask,num_clusters):
	# Retira as outras cores (deixando só vermelho e laranja)
	imgAux = 255*(img_mask).astype(np.uint8)
	imgFinal = cv2.bitwise_and(imgBGR, imgBGR, mask=imgAux)

	canais = [0,1,2]

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
	global mode_DEBUG
	redList = []
	med=0
	num=0
	for i,cent in enumerate(centers):
		tmp=np.zeros((1,1,3),np.uint8)
		cv2.rectangle(tmp,(0,0),(1,1),(cent[0],cent[1],cent[2]),-1)
		bgrVers=(cv2.cvtColor(tmp,cv2.COLOR_LAB2RGB))[0][0]
		if (cent[0]>12):
			minimum=bgrVers[2]
			med+=bgrVers[2]
			num+=1

	if(num):
		med/=num

	if(mode_DEBUG):
		print(num)
		print(med)

	for i,cent in enumerate(centers):
		tmp=np.zeros((1,1,3),np.uint8)
		cv2.rectangle(tmp,(0,0),(1,1),(cent[0],cent[1],cent[2]),-1)
		bgrVers=(cv2.cvtColor(tmp,cv2.COLOR_LAB2RGB))[0][0]
		if (bgrVers[2] > med and 0.3*bgrVers[2]>bgrVers[1]):
			redList.append(i)
	

	img_mask_r = np.zeros((imgBGR.shape[0], imgBGR.shape[1]),dtype=bool)
	for label in redList:
		currentMask = labels==label
		img_mask_r = (img_mask_r) | (currentMask)
	return redList, img_mask_r

# Cria uma mascara para a cor laranja, buscando nos centros retornadas pela clusterização
# Uma mascara binaria é criada para cada centro escolhido, e ao final uma operação OR
# é feita com todas as mascaras para gerar a mascara final
def getDarkGreenImageMask(imgLAB, centers, labels):
	global mode_DEBUG
	greenList = []
	medLum=0
	medGreen=0
	num=0
	for i,cent in enumerate(centers):
		tmp=np.zeros((1,1,3),np.uint8)
		cv2.rectangle(tmp,(0,0),(1,1),(cent[0],cent[1],cent[2]),-1)
		bgrVers=(cv2.cvtColor(tmp,cv2.COLOR_LAB2RGB))[0][0]
		print(bgrVers)
		if (cent[0]>12):
			medGreen+=bgrVers[1]
			num+=1
	if(num):
		medGreen/=num

	if(mode_DEBUG):
		print("\n")
		print(medGreen)

	num=0
	for i,cent in enumerate(centers):
		tmp=np.zeros((1,1,3),np.uint8)
		cv2.rectangle(tmp,(0,0),(1,1),(cent[0],cent[1],cent[2]),-1)
		bgrVers=(cv2.cvtColor(tmp,cv2.COLOR_LAB2RGB))[0][0]
		if (cent[0]>12 and bgrVers[1]>medGreen):
			medLum+=cent[0]
			num+=1
	if(num):
		medLum/=num

	if(mode_DEBUG):
		print(medLum)

	for i,cent in enumerate(centers):
		tmp=np.zeros((1,1,3),np.uint8)
		cv2.rectangle(tmp,(0,0),(1,1),(cent[0],cent[1],cent[2]),-1)
		bgrVers=(cv2.cvtColor(tmp,cv2.COLOR_LAB2RGB))[0][0]

		if(mode_DEBUG):
			print("\n")
			print(bgrVers)
			print(cent)
		if (cent[0] < medLum and cent[0]>12 and bgrVers[1]>medGreen):
			greenList.append(i)
			
			if(mode_DEBUG):
				print("PASS")
	

	img_mask_g = np.zeros((imgLAB.shape[0], imgLAB.shape[1]),dtype=bool)
	for label in greenList:
		currentMask = labels==label
		img_mask_g = (img_mask_g) | (currentMask)
	return img_mask_g
	
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

	# Calculo das posicoes dos focos
	f = open("focos.txt", "w")
	print('Tamanho da imagem : ' + str(img_mask_sem_ruido.shape))
	f.write('Tamanho da imagem : ' + str(img_mask_sem_ruido.shape) + '\n')
	focos = ndimage.measurements.center_of_mass(img_mask_sem_ruido, labeled, range(1,nr_objects+1))
	print(nr_objects)
	for i in range(len(focos)):
		print('X = ' + str(round(focos[i][1],2)) + ',  Y = ' + str(round(focos[i][0],2)))
		f.write('X = ' + str(round(focos[i][1],2)) + ',  Y = ' + str(round(focos[i][0],2)) + '\n')
	f.close()
	
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
	global mode_DEBUG
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
	img_mask_RandO = np.zeros((imgBGR.shape[0], imgBGR.shape[1]),dtype=bool)
	for i in clusRedOrange:
		img_mask_RandO = img_mask_RandO|(labels1==i)

	if(mode_DEBUG):
		background = np.zeros((imgBGR.shape[0], imgBGR.shape[1],3),np.uint8)
		cv2.rectangle(background,(0,0),(imgBGR.shape[1], imgBGR.shape[0]),(0,0,0),-1)
		background[img_mask_RandO]=imgBGR[img_mask_RandO]
		cv2.imshow('Red and Orange',background)
		cv2.waitKey(0)
		cv2.destroyAllWindows()


	#Aumento de saturacao para a segunda clusterização
	imgHigherSat = increaseSaturation(imgBGR)
	
	# Faz um segundo k means para separar o vermelho e laranja
	labelsR, centersR = secondKmeans(imgHigherSat, img_mask_RandO,10)
	#print(centers2)
	
	# Cria a mascara da cor vermelha a partir dos clusters do segundo kmeans
	redList, img_mask_Red = getRedImageMask(imgBGR, centersR, labelsR)
	img_mask_Red=tiraRuido(img_mask_Red,2)
	
	if(mode_DEBUG):
		background = np.zeros((imgBGR.shape[0], imgBGR.shape[1],3),np.uint8)
		cv2.rectangle(background,(0,0),(imgBGR.shape[1], imgBGR.shape[0]),(0,0,0),-1)
		background[img_mask_Red]=imgBGR[img_mask_Red]
		cv2.imshow('Red',background)
		cv2.waitKey(0)
		cv2.destroyAllWindows()

	labels, nro = calcFires(img_mask_Red, 1)
   


	#Identifica qual o cluster dos verdes
	clusGreen = getLabelGreenRGB(centers1)

	#Cria uma mascara do cluster verde
	img_mask_AllGreen = np.zeros((imgBGR.shape[0], imgBGR.shape[1]),dtype=bool)
	for i in clusGreen:
		img_mask_AllGreen = img_mask_AllGreen|(labels1==i)

	img_mask_AllGreen=tiraRuido(img_mask_AllGreen,2)
	img_mask_AllGreen=tiraBuraco(img_mask_AllGreen,1)
	img_mask_AllGreen=tiraRuido(img_mask_AllGreen,3)

	if(mode_DEBUG):
		background = np.zeros((imgBGR.shape[0], imgBGR.shape[1],3),np.uint8)
		cv2.rectangle(background,(0,0),(imgBGR.shape[1], imgBGR.shape[0]),(0,0,0),-1)
		background[img_mask_AllGreen]=imgBGR[img_mask_AllGreen]
		cv2.imshow('AllGreen',background)
		cv2.waitKey(0)
		cv2.destroyAllWindows()

	# Faz um segundo k means para separar obter o verde escuro
	labelsG, centersG = secondKmeans(imgBGR, img_mask_AllGreen,6)
	

	# Cria a mascara do verde escuro a partir dos clusters do segundo kmeans
	img_mask_Green = getDarkGreenImageMask(imgLAB, centersG, labelsG)
	img_mask_Green = tiraRuido(img_mask_Green,1)
	img_mask_Green = tiraBuraco(img_mask_Green,1)

	
	if(mode_DEBUG):
		background = np.zeros((imgBGR.shape[0], imgBGR.shape[1],3),np.uint8)
		cv2.rectangle(background,(0,0),(imgBGR.shape[1], imgBGR.shape[0]),(0,0,0),-1)
		background[img_mask_Green]=imgBGR[img_mask_Green]
		cv2.imshow('Green',background)
		cv2.waitKey(0)
		cv2.destroyAllWindows()
	
	label['text']="Area:{}%".format(calcDeforestation(img_mask_Green))+"\nFocos:{}".format(nro)


def autoEscuro(label):
	global mode_DEBUG
	imgBGR, imgHSV, imgLAB = getImages()

	#Realiza o primeiro kmeans para separar apenas as cores vermelho e laranja
	labels1, centers1 = firstKmeans(imgBGR)

	#Identifica qual o cluster das cores vermelho e laranja
	clusRedOrange = getLabelRedRGB(centers1)

	#Cria uma mascara do cluster vermelho e laranja
	img_mask_RandO = np.zeros((imgBGR.shape[0], imgBGR.shape[1]),dtype=bool)
	for i in clusRedOrange:
		img_mask_RandO = img_mask_RandO|(labels1==i)
	
	if(mode_DEBUG):
		background = np.zeros((imgBGR.shape[0], imgBGR.shape[1],3),np.uint8)
		cv2.rectangle(background,(0,0),(imgBGR.shape[1], imgBGR.shape[0]),(0,0,0),-1)
		background[img_mask_RandO]=imgBGR[img_mask_RandO]
		cv2.imshow('Red and Orange',background)
		cv2.waitKey(0)
		cv2.destroyAllWindows()


	# Faz um segundo k means para separar as duas cores
	labels2, centers2 = secondKmeans(imgBGR, img_mask_RandO,10)
	
	# Cria a mascara da cor vermelha a partir dos cluster do segundo kmeans
	redList, img_mask_Red = getRedImageMask(imgBGR, centers2, labels2)
	img_mask_Red=tiraRuido(img_mask_Red,2)
	
	if(mode_DEBUG):
		background = np.zeros((imgBGR.shape[0], imgBGR.shape[1],3),np.uint8)
		cv2.rectangle(background,(0,0),(imgBGR.shape[1], imgBGR.shape[0]),(0,0,0),-1)
		background[img_mask_Red]=imgBGR[img_mask_Red]
		cv2.imshow('Red',background)
		cv2.waitKey(0)
		cv2.destroyAllWindows()
	

	labels, nro = calcFires(img_mask_Red, 1)


	#Identifica qual o cluster dos verdes
	clusGreen = getLabelGreenRGB(centers1)

	#Cria uma mascara do cluster verde
	img_mask_AllGreen = np.zeros((imgBGR.shape[0], imgBGR.shape[1]),dtype=bool)
	for i in clusGreen:
		img_mask_AllGreen = img_mask_AllGreen|(labels1==i)

	
	img_mask_AllGreen=tiraRuido(img_mask_AllGreen,2)
	img_mask_AllGreen=tiraBuraco(img_mask_AllGreen,1)
	img_mask_AllGreen=tiraRuido(img_mask_AllGreen,3)

	if(mode_DEBUG):
		background = np.zeros((imgBGR.shape[0], imgBGR.shape[1],3),np.uint8)
		cv2.rectangle(background,(0,0),(imgBGR.shape[1], imgBGR.shape[0]),(0,0,0),-1)
		background[img_mask_AllGreen]=imgBGR[img_mask_AllGreen]
		cv2.imshow('AllGreen',background)
		cv2.waitKey(0)
		cv2.destroyAllWindows()


	# Faz um segundo k means para separar obter o verde escuro
	labelsG, centersG = secondKmeans(imgBGR, img_mask_AllGreen,6)

	# Cria a mascara do verde escuro a partir dos clusters do segundo kmeans
	img_mask_Green = getDarkGreenImageMask(imgLAB, centersG, labelsG)
	img_mask_Green = tiraRuido(img_mask_Green,1)
	img_mask_Green = tiraBuraco(img_mask_Green,1)

	if(mode_DEBUG):
		background = np.zeros((imgBGR.shape[0], imgBGR.shape[1],3),np.uint8)
		cv2.rectangle(background,(0,0),(imgBGR.shape[1], imgBGR.shape[0]),(0,0,0),-1)
		background[img_mask_Green]=imgBGR[img_mask_Green]
		cv2.imshow('Green',background)
		cv2.waitKey(0)
		cv2.destroyAllWindows()


	label['text']="Area:{}%".format(calcDeforestation(img_mask_Green))+"\nFocos:{}".format(nro)

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

# Abre uma janela para selecionar o arquivo da imagem a ser usada
# Essa imagem é carregada em BGR e é retornado a versão BGR, HSV e LAB
# nesta ordem
def getImagesSup(imgFile):
	imgBGR = cv2.imread(imgFile,1)
	imgHSV = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2HSV)
	imgLAB = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2LAB)
	return imgBGR, imgHSV, imgLAB

# Cria o dataframe do pandas no python das bases escolhidas nas janelas
# Se mais de uma base foi selecionada, o algoritmo une elas
def createDataFrame(fileName):
	finalDB = pd.read_csv(fileName, sep='\t')
	return finalDB

def selectDBSup(textChooseDB):
	global supDBFile
	text = filedialog.askopenfilename(title = "Escolha uma base de dados",filetypes = (("csv files","*.csv"),("all files","*.*")))
	if(text[-4:] == ".csv"):
		textChooseDB['text'] = text
		supDBFile = text
	else:
		textChooseDB['text'] = 'Arquivo escolhido não é base de dados'

def selectImageSup(textChooseImage):
	global supImgFile
	text = filedialog.askopenfilename(title = "Escolha a imagem",filetypes = (("png files","*.png"),("jpg files","*.jpg"),("jpeg files","*.jpeg"),("all files","*.*")))
	print(text[-4:])
	print(text[-4:] == ".png")
	if(text[-4:] == ".png" or text[-4:] == ".jpg" or text[-5:] == ".jpeg"):
		print("aqui")
		textChooseImage['text'] = text
		supImgFile = text
	else:
		print("aqui2")
		textChooseImage['text'] = 'Arquivo escolhido não é imagem'
		#Avisar do erro


# Percorre cada pixel da imagem e verifica o label atribuido pelo KNN
# Se este label e 1 significa que aquele pixel foi classificado como target
# e deve ser adicionado a uma mascara binaria da imagem.
# Esta mascara é retornada
def getImageMaskSup(imgBGR, y_pred):
	img_mask = np.zeros((imgBGR.shape[0], imgBGR.shape[1]), dtype = bool)
	for i in range(imgBGR.shape[0]):
		for j in range(imgBGR.shape[1]):
			if y_pred[i*imgBGR.shape[1] + j] == 1:
				img_mask[i,j] = True
	return img_mask


def showMaskAsImage(imgBGR, img_mask):
	imgAux = 255*(img_mask).astype(np.uint8)
	imgFinal = cv2.bitwise_and(imgBGR, imgBGR, mask=imgAux)
	imgFinalBoth = np.hstack((imgBGR, imgFinal))
	cv2.imshow('imagemCortada',imgFinalBoth)
	while True: 
		cv2.waitKey(100)
		if (cv2.getWindowProperty('imagemCortada',cv2.WND_PROP_VISIBLE) < 1):
			break
	cv2.destroyWindow('imagemCortada')
	cv2.imwrite('imagemComparacao.png',imgFinalBoth)
	

# Calcula o numero de objetos vermelhos da imagem e retorna em nr_objects
# Essa função depende da quantidade de ruido que vai vir no cluster vermelho
# Se tiver muito ruido, passar um num, maior para tirar o ruido da mascara
# utilizando abertura
def calcFiresSup(img_mask, imgBGR, transfString, textTransf):
	if len(transfString) > 0:
		img_mask_aux = img_mask
		for i in range(len(transfString)//2):
			if(transfString[i*2] == 'A' or transfString[i*2] == 'a'):
				print('Fazendo abertura de ' + transfString[i*2+1])
				img_mask_aux = tiraRuido(img_mask_aux, int(transfString[i*2+1]))
			else:
				print('Fazendo fechamento de ' + transfString[i*2+1])
				img_mask_aux = tiraBuraco(img_mask_aux, int(transfString[i*2+1]))
		img_mask_sem_ruido = img_mask_aux
	else:
		img_mask_sem_ruido = img_mask
	labeled, nr_objects = ndimage.label(img_mask_sem_ruido)
	# Calculo das posicoes dos focos
	f = open("focos.txt", "w")
	print('Tamanho da imagem : ' + str(img_mask_sem_ruido.shape))
	f.write('Tamanho da imagem : ' + str(img_mask_sem_ruido.shape) + '\n')
	focos = ndimage.measurements.center_of_mass(img_mask_sem_ruido, labeled, range(1,nr_objects+1))
	imgBGR_aux = imgBGR
	print(nr_objects)
	for i in range(len(focos)):
		print('X = ' + str(round(focos[i][1],2)) + ',  Y = ' + str(round(focos[i][0],2)))
		f.write('X = ' + str(round(focos[i][1],2)) + ',  Y = ' + str(round(focos[i][0],2)) + '\n')
		#Adicionando pontos na imagem
		imgBGR_aux[int(focos[i][0]), int(focos[i][1]), :] = [255,255,255]
		imgBGR_aux[int(focos[i][0]), int(focos[i][1]+1), :] = [255,255,255]
		imgBGR_aux[int(focos[i][0]), int(focos[i][1]-1), :] = [255,255,255]
		imgBGR_aux[int(focos[i][0]+1), int(focos[i][1]-1), :] = [255,255,255]
		imgBGR_aux[int(focos[i][0]+1), int(focos[i][1]+1), :] = [255,255,255]
		imgBGR_aux[int(focos[i][0]+1), int(focos[i][1]), :] = [255,255,255]
		imgBGR_aux[int(focos[i][0]-1), int(focos[i][1]-1), :] = [255,255,255]
		imgBGR_aux[int(focos[i][0]-1), int(focos[i][1]+1), :] = [255,255,255]
		imgBGR_aux[int(focos[i][0]-1), int(focos[i][1]), :] = [255,255,255]
	f.close()
	showMaskAsImage(imgBGR_aux, img_mask_sem_ruido)
	textTransf['text'] = 'Nro de focos = ' + str(nr_objects)
	return labeled, nr_objects, img_mask_sem_ruido

# Calcula a area de desmatamento em percentual da area da imagem toda
# Essa função depende da quantidade de ruido que vai vir na mascara laranja
# Se tiver muito ruido, passar um num, maior para tirar o ruido da mascara
# utilizando abertura
def calcDeforestationSup(img_mask, imgBGR, transfString, textTransf):
	print(transfString)
	if len(transfString) > 0:
		img_mask_aux = img_mask
		for i in range(len(transfString)//2):
			if(transfString[i*2] == 'A'):
				print('Fazendo abertura de ' + transfString[i*2+1])
				img_mask_aux = tiraRuido(img_mask_aux, int(transfString[i*2+1]))
			else:
				print('Fazendo fechamento de ' + transfString[i*2+1])
				img_mask_aux = tiraBuraco(img_mask_aux, int(transfString[i*2+1]))
		img_mask_sem_ruido = img_mask_aux
	else:
		img_mask_sem_ruido = img_mask
	whitePixels = sum(sum(img_mask_sem_ruido))
	totalPixels = img_mask_sem_ruido.shape[0]*img_mask_sem_ruido.shape[1]
	area = round((whitePixels/totalPixels)*100, 2)
	showMaskAsImage(imgBGR, img_mask_sem_ruido)
	textTransf['text'] = 'Area = ' + str(area) + '%'
	return area

#Algoritmo geral
def supervisedMethod(area, transfString, textTransf):
	global supImgFile
	global supDBFile
	imgBGR, imgHSV, imgLAB = getImagesSup(supImgFile)

	#Cria o dataframe a partir das bases selecionadas
	db = createDataFrame(supDBFile)

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
	img_mask = getImageMaskSup(imgBGR, y_pred)
	
	if(area):
		print('Area = {}%'.format(calcDeforestationSup(img_mask,imgBGR, transfString, textTransf)))
	else:
		labels, nro, img_mask_final = calcFiresSup(img_mask, imgBGR, transfString, textTransf)
		print('Nro de focos = {}'.format(nro))

def configureSupervised():
	text1 = tk.Label(supervised, text = "Supervisionado", font='Helvetica 18 bold').place(relx=0.5,y=15,anchor = tk.CENTER)
	
	textSupImage = tk.Label(supervised, text = supImgFile, wraplength=(largura - 20))
	textSupImage.place(relx=0.5,rely=0.25,anchor = tk.CENTER)
	
	btSelectImageSup = tk.Button(supervised, text='Selecionar Imagem', command=lambda:selectImageSup(textSupImage), width=20)
	btSelectImageSup.place(relx=0.50, rely = 0.2 ,anchor = tk.CENTER)
	
	textSupDB = tk.Label(supervised, text = supDBFile, wraplength=(largura - 20))
	textSupDB.place(relx=0.5,rely=0.38,anchor = tk.CENTER)
	
	btWhereToSave = tk.Button(supervised, text='Selecionar Base de Dados', command=lambda:selectDBSup(textSupDB), width=20)
	btWhereToSave.place(relx=0.50, rely = 0.33 ,anchor = tk.CENTER)

	textOut = tk.Label(supervised, text = '', wraplength=(largura - 200),bg="white")
	textOut.place(relx=0.5,rely=0.62, anchor = tk.CENTER)
	
	btGetArea = tk.Button(supervised, text='Área', command=lambda:supervisedMethod(True, E1.get(), textOut), width=10)
	btGetArea.place(relx=0.25, rely = 0.52 ,anchor = tk.CENTER)
	
	btGetPos = tk.Button(supervised, text='Posições', command=lambda:supervisedMethod(False, E1.get(), textOut), width=10)
	btGetPos.place(relx=0.75, rely = 0.52 ,anchor = tk.CENTER)

	textTransf = tk.Label(supervised, text = 'Transformações', wraplength=(largura - 20))
	textTransf.place(relx=0.5,rely=0.47, anchor = tk.CENTER)

	textRes = tk.Label(supervised, text = 'Resultados:', wraplength=(largura - 20))
	textRes.place(relx=0.5,rely=0.57, anchor = tk.CENTER)

	E1 = tk.Entry(supervised, bd =2)
	E1.place(relx=0.5, rely = 0.52 ,anchor = tk.CENTER)

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
	for label in class_centers[4]:
		mask = labels==label
		print(label)
		print(class_centers[4])
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
