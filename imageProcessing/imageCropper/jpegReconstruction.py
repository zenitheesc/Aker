import random

imgFile = open('Image.jpg','rb')
imgData = imgFile.read()
imgFile.close()

imgDataChars = list(imgData)

pixelsToCrash = random.sample(range(1,len(imgDataChars)-1), 50)


for p in (pixelsToCrash):
	print(p)
	imgDataChars[p] = chr((ord(imgDataChars[p-2]) + ord(imgDataChars[p-1])
				 + ord(imgDataChars[p+1]) + ord(imgDataChars[p+2]))//4)  

imgDataOut = "".join(imgDataChars)

outFile = open('NewImage.jpg', 'wb')
outFile.write(imgDataOut)
outFile.close()