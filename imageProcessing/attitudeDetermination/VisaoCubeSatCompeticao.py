#Este codigo e uma versao do programa de processamento de imagens que utiliza
#como base os algoritmos de Canny, HoughLines e HoughCircles.
#A forma de captura da imagem e atraves da imagem capturada
import cv2
import numpy as np

#captura o video exemplo
img = cv2.imread('captura.jpg')

#Tamanho a imagem
img_shape = img.shape
img_center_x = img_shape[1]/2
img_center_y = img_shape[0]/2

#definicao do angulo de abertura da camera
cam_angle = 160

#abre o arquivo de output
output_file = open("adc_cv.dat", "w")

#converte a imagem para tons de cinza
imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

#encontra os contornos
edges = cv2.Canny(imgGray,50,150,apertureSize = 3)

#detecta as linhas  
lines = cv2.HoughLines(edges,1,np.pi/180,10)

#processamento das linhas
if lines is not None: 
    for rho,theta in lines[0]:
        #monta a reta
        a = np.cos(theta)
        b = np.sin(theta)
        x0 = a*rho
        y0 = b*rho
        x1 = int(x0 + 1000*(-b))
        y1 = int(y0 + 1000*(a))
        x2 = int(x0 - 1000*(-b))
        y2 = int(y0 - 1000*(a))
        #limita o tamanho da reta para
        #ser possivel achar o centro
        if x1 < 0:
            x1 = 0
            y1 = int(rho/b)
        if y1 < 0:
            y1 = 0
            x1 = int(rho/a)
        if x2 > img_shape[1]:
            x2 = img_shape[1]
            y2 = int((rho - x2*a)/b)
        if y2 > img_shape[0]:
            y2 = img_shape[0]
            x2 = int((rho - y2*b)/a)
    
    #posicao da reta
    pos_line = ((x1+x2)/2,(y1+y2)/2)
else:
    #se nao achou nada, coloca uma posica absurda
    pos_line = (-1,-1)    

#detecta os circulos
circles = cv2.HoughCircles(imgGray,cv2.HOUGH_GRADIENT,1,200, param1=10,param2=30,minRadius=2,maxRadius=100)
#processamento dos circulos
if circles is not None:
    circles = np.uint16(np.around(circles))
    #ordena pelo raio para pegarmos o maior
    circles_s = sorted(circles, key=lambda tup: tup[:,2])
    #pega as coodernadas do maior circulo
    x_c = circles_s[0][0][0]
    y_c = circles_s[0][0][1]
    r_c = circles_s[0][0][2]
    
    #posicao do circulo
    pos_circle = (x_c, y_c)
    
    #encontra o angulo em relacao ao centro da camera
    sun_dif_angle = x_c*cam_angle/img_shape[1]
    sun_dif_angle = sun_dif_angle - cam_angle/2
else:
    #valores absurdos
    pos_circle = (-1,-1)
    sun_dif_angle = -360

#grava tudo no arquivo
output_file.write(str(pos_line[0]).zfill(8))
output_file.write("\n")
output_file.write(str(pos_line[1]).zfill(8))
output_file.write("\n")
output_file.write(str(pos_circle[0]).zfill(8))
output_file.write("\n")
output_file.write(str(pos_circle[1]).zfill(8))
output_file.write("\n")
output_file.write(str(round(sun_dif_angle,4)).zfill(8))
output_file.write("\n")
output_file.close()
