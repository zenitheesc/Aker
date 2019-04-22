import cv2 as cv
import numpy as np
import sys 

def imgToTxt(imgPath, txtPath):

	img = cv.imread(imgPath)
	rows, cols, chan = img.shape

	txtFile = open(txtPath, 'w')

	for i in range(rows):
		for j in range(cols):
			for c in range(chan):
				if i != 0 or j != 0 or c!=0:
					txtFile.write(',')

				txtFile.write(str(img[i,j,c]))

	return txtFile


def txtToImg(txtPath, imgPath, rows, cols, chan):

	img = np.zeros((rows, cols, chan))

	txtFile = open(txtPath, 'r')

	pixValues = np.zeros(rows*cols*chan)
	pixValues = (txtFile.read()).split(',')
	pixValues = np.reshape(pixValues, (rows, cols, chan))

	cv.imwrite(imgPath, pixValues.astype(int))

	return img

def sendTxt(txtPath, imgPkgSize):

	txtFile = open(txtPath, 'r')
	pixValues = (txtFile.read()).split(',')
	numPixels = len(pixValues)

	numBytesSent = 0
	for pkg in range(numPixels//imgPkgSize):
		for i in range(imgPkgSize):
			val = int(pixValues[i + pkg*imgPkgSize])
			#print("Sending:: pkg: " + str(pkg) + "  pixel: " + str(i) + "   values:" + str(val))
			numBytesSent = numBytesSent + sys.getsizeof(val)

		print("***********Num bytes sent : " + str(numBytesSent) + ' ***************')
		numBytesSent = 0


imgToTxt('Image.jpg', 'imgTxt.txt')
txtToImg('imgTxt.txt', 'NewImage.jpg', 400, 600, 3)
sendTxt('imgTxt.txt', 8)