# !/usr/bin/python3
import tkinter as tk
from tkinter import filedialog
from io import StringIO
import requests
import subprocess
import arff
import os,os.path
import cv2
import numpy as np
        
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
    else:
        print("foi para unsupervised")
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
    
    btSupervised = tk.Button(menu, text='Supervisionado', command=lambda:raise_frame(supervised), width=20)
    btSupervised.place(relx=0.50, rely = 0.5 ,anchor = tk.CENTER)
    
    btUnsupervised = tk.Button(menu, text='Não-Supervisionado', command=lambda:raise_frame(unsupervised), width=20)
    btUnsupervised.place(relx=0.50, rely = 0.6 ,anchor = tk.CENTER)
    
    btExit = tk.Button(menu, text='SAIR', command=lambda:sair(), width=20)
    btExit.place(relx=0.50, rely = 0.9 ,anchor = tk.CENTER)

#####################
#Fim da Area do MENU#
#####################


########################
#Inicio da Area do CROP#
########################

#Globais
fileToCrop = ""
whereToSaveCropped = ""
mouseX = -1
mouseY = -1

def selectImage(textChooseImage):
    global fileToCrop
    text = filedialog.askopenfilename(title = "Escolha a imagem",filetypes = (("png files","*.png"),("jpg files","*.jpg"),("jpeg files","*.jpeg"),("all files","*.*")))
    print(text[-4:])
    print(text[-4:] == ".png")
    if(text[-4:] == ".png" or text[-4:] == ".jpg" or text[-5:] == ".jpeg"):
        print("aqui")
        textChooseImage['text'] = text
        fileToCrop = text
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
    global fileToCrop, mouseX, mouseY
    mouseX=-1
    mouseY=-1

    border=[]
    cv2.namedWindow('image')
    cv2.setMouseCallback('image',get_click)
    img = cv2.imread(fileToCrop)
    cv2.imshow('image',img)
    while(1):
        k=cv2.waitKey(20) 
        if (k==ord('q') or k==27):
            break
        elif(k==ord('c') or k == 32):
            del border[:]
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
            break
    cv2.destroyAllWindows()

def configureCrop():

    text1 = tk.Label(crop, text = "Crop", font='Helvetica 18 bold').place(relx=0.5,y=15,anchor = tk.CENTER)
    
    textChooseImage = tk.Label(crop, text = fileToCrop, wraplength=(largura - 20))
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



##############################
#Inicio da Area do SUPERVISED#
##############################
def configureUnsupervised():
    text1 = tk.Label(unsupervised, text = "Não-Supervisionado", font='Helvetica 18 bold').place(relx=0.5,y=15,anchor = tk.CENTER)
    
    btBack = tk.Button(unsupervised, text='Voltar ao menu', command=lambda:raise_frame(menu), width=20)
    btBack.place(relx=0.50, rely = 0.9 ,anchor = tk.CENTER)
    
#############################
#Fim da Area do UNSUPERVISED#
############################# 

#####################
#        MAIN       #
#####################
    

# Cria a janela em que a interface irá rodar
largura = 400
altura = 300
window = tk.Tk()
window.title('Zenith - Missão INPE')
window.geometry(str(largura) + "x" + str(altura) + "+100+100")
window.resizable(0, 0) 

#Cria frames da interface
menu = tk.Frame(window,width=largura, height=altura)
crop = tk.Frame(window,width=largura, height=altura)
createDatabase = tk.Frame(window,width=largura, height=altura)
supervised = tk.Frame(window,width=largura, height=altura)
unsupervised = tk.Frame(window,width=largura, height=altura)

# Gruda os frames para que todos fechem juntos
for frame in (menu, crop, createDatabase, supervised, unsupervised):
    frame.grid(row=0, column=0, sticky='news')

#Configura todos os frames
configureMenu()
configureCrop()
configureCreateDatabase()
configureSupervised()
configureUnsupervised()

#Inicia no frame do MENU
raise_frame(menu)

#Loop da interface
window.mainloop()
