import os, os.path
import numpy as np
import time
import cv2

#Necessario para barras do opencv
def nothing(x):
	pass

#Altera as barras para algum valor fixo
def set_default(thresh):
	cv2.setTrackbarPos('Min_1','Val',thresh[0][0])
	cv2.setTrackbarPos('Min_2','Val',thresh[0][1])
	cv2.setTrackbarPos('Min_3','Val',thresh[0][2])
	cv2.setTrackbarPos('Max_1','Val',thresh[1][0])
	cv2.setTrackbarPos('Max_2','Val',thresh[1][1])
	cv2.setTrackbarPos('Max_3','Val',thresh[1][2])

#Obtem valor para resize da imagem
def get_ratio(pic):
	ratio_x=int(pic.shape[1]/800)
	ratio_y=int(pic.shape[0]/600)
	if(ratio_x==0 or ratio_y==0):
		return (pic.shape[1],pic.shape[0])
	elif ratio_x>ratio_y:
		ratio=(pic.shape[1]/ratio_x,pic.shape[0]/ratio_x)
	else:
		ratio=(pic.shape[1]/ratio_y,pic.shape[0]/ratio_y)
	return ratio

#Processamento para queimada
def process(img,thresh,mode):	
	
	#Kernel para erodir e dilatar
	kernel = np.ones((11,11), np.uint8)

	slices=img.copy()
	
	#Troca para HSV ou Lab
	if (mode==1):
		hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
	elif(mode==2):
		lab=cv2.cvtColor(img,cv2.COLOR_BGR2Lab)
	
	#Faz o threshold
	mask=cv2.inRange(img,thresh[0],thresh[1])
	
	#Erosao e dilatacao
	mask=cv2.erode(mask,kernel,iterations=5)
	mask=cv2.dilate(mask,kernel,iterations=5)

	#Acha os contornos
	im2,contours,hierarchy = cv2.findContours(mask,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
	area=0
	cnt=[]

	#Encontra o maior contorno
	for data in contours:
		if(area<cv2.contourArea(data)):
			area=cv2.contourArea(data)

	area=0.25*area

	#Seleciona todos os contornos com pelo menos 25% da area do maior 
	for data in contours:
		if(area<cv2.contourArea(data)):
			cnt.append(data)

	return cnt

i=0
mode=0
running=1
last_mode=0
img_list=[]

#Valores iniciais de Threshold
#Uma dupla (Min,Max) de trios (R,G,B/H,S,V/L,a,b) de valores para cada espaco de cor
thresh=[[(90,85,90),(165,170,170)],[(135,5,70),(255,190,255)],[(100,0,0),(175,202,155)]]

#Seleciona imagens
for file in os.listdir("1080p/"):
	img_list.append(os.path.join("1080p/", file))

l=len(img_list)

#Inicializacao para a janela de barras
bar=np.zeros((1,450,3),np.uint8)
cv2.namedWindow('Val')

#Cria as barras
cv2.createTrackbar('Min_1','Val',0,255,nothing)
cv2.createTrackbar('Min_2','Val',0,255,nothing)
cv2.createTrackbar('Min_3','Val',0,255,nothing)

cv2.createTrackbar('Max_1','Val',0,255,nothing)
cv2.createTrackbar('Max_2','Val',0,255,nothing)
cv2.createTrackbar('Max_3','Val',0,255,nothing)

cv2.createTrackbar('0:BGR\n1:HSV\n2:Lab','Val',0,2,nothing)

cv2.createTrackbar('Off/On','Val',0,1,nothing)
cv2.setTrackbarPos('Off/On','Val',1)

cv2.imshow('Val',bar)
cv2.moveWindow('Val',0,0)

#Muda barra para valores inicias escritos no codigo
set_default(thresh[mode])

pic=cv2.imread(img_list[i],1)
ratio=get_ratio(pic)

cv2.imshow('Imagem '+str(i+1)+'/'+str(l),cv2.resize(pic,ratio,interpolation=cv2.INTER_NEAREST))
cv2.moveWindow('Imagem '+str(i+1)+'/'+str(l),520,0)

while(running):
	ticks=time.time()
	img=pic.copy()

	#Atualiza vetor de Threshold pelo menu de barras
	thresh[mode][0]=(cv2.getTrackbarPos('Min_1','Val'),cv2.getTrackbarPos('Min_2','Val'),cv2.getTrackbarPos('Min_3','Val'))
	thresh[mode][1]=(cv2.getTrackbarPos('Max_1','Val'),cv2.getTrackbarPos('Max_2','Val'),cv2.getTrackbarPos('Max_3','Val'))
	
	#Atualiza modo de espaco de cor
	mode=cv2.getTrackbarPos('0:BGR\n1:HSV\n2:Lab','Val')
	show=cv2.getTrackbarPos('Off/On','Val')

	#Altera barras quando se troca o espaco de cor
	if(mode!=last_mode):
		set_default(thresh[mode])
		last_mode=mode

	#Conversao de escala caso espaco de cor seja HSV
	if(mode==1):
		thresh[mode][0]=(int(float(thresh[mode][0][0]*180)/255.0),thresh[mode][0][1],thresh[mode][0][2])
		thresh[mode][1]=(int(float(thresh[mode][1][0]*180)/255.0),thresh[mode][1][1],thresh[mode][1][2])
	
	#Contornos do processamento normal
	cnt_img=process(img,thresh[mode],mode)
	
	#Contornos para imagem com Blur aplicado
	blur=cv2.GaussianBlur(img,(17,17),0)
	cnt_blr=process(blur,thresh[mode],mode)

	#Exibe os contornos caso a opcao esteja ativa
	if(show):
		tmp_1=img.copy()
		tmp_2=img.copy()

		#Sobreposicao dos contornos
		#Gera o efeito transparente das areas detectadas
		cv2.drawContours(tmp_1, cnt_img,-1,(200,0,35),-1)
		cv2.drawContours(tmp_2, cnt_blr,-1,(0,200,35),-1)

		cv2.addWeighted(tmp_1,0.5,tmp_2,0.5,0,tmp_1)
		cv2.addWeighted(tmp_1,0.6,img,0.4,0,img)

	#imshow eh feito com o resize dentro da funcao
	#Evitar criar outra copia da imagem ou alteras as proporcoes da original
	cv2.imshow('Imagem '+str(i+1)+'/'+str(l),cv2.resize(img,ratio,interpolation=cv2.INTER_NEAREST))

	k=cv2.waitKey(1)
	
	#Sai do programa
	if(k==ord('q')):
		running=0;

	#Vai para imagem anterior
	elif(k==ord('[')):
		cv2.destroyWindow('Imagem '+str(i+1)+'/'+str(l))
		i-=1
		i=i%l

		pic=cv2.imread(img_list[i],1)
		ratio=get_ratio(pic)
		cv2.imshow('Imagem '+str(i+1)+'/'+str(l),cv2.resize(pic,ratio,interpolation=cv2.INTER_NEAREST))
		cv2.moveWindow('Imagem '+str(i+1)+'/'+str(l),520,0)
		
	#Vai para proxima imagem
	elif(k==ord(']')):
		cv2.destroyWindow('Imagem '+str(i+1)+'/'+str(l))
		i+=1
		i=i%l

		pic=cv2.imread(img_list[i],1)
		ratio=get_ratio(pic)
		cv2.imshow('Imagem '+str(i+1)+'/'+str(l),cv2.resize(pic,ratio,interpolation=cv2.INTER_NEAREST))
		cv2.moveWindow('Imagem '+str(i+1)+'/'+str(l),520,0)
	
	#Liga/Desliga Exibicao dos contornos
	elif(k==ord('f')):
		show+=1
		show=show%2
		cv2.setTrackbarPos('Off/On','Val',show)

	#Tempo para processar imagem
	print(time.time()-ticks)
cv2.destroyAllWindows()
