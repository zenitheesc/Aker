import numpy as np
import os,os.path
import cv2

# mouse callback function
def draw_circle(event,x,y,flags,param):
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

global mouseX,mouseY
mouseX=-1
mouseY=-1

index=0

img_list=[]
border=[]

#Seleciona imagens
for file in os.listdir("for_crop/"):
	img_list.append(os.path.join("for_crop/", file))

l=len(img_list)

cv2.namedWindow('image')
cv2.setMouseCallback('image',draw_circle)

while(1):
	img = cv2.imread(img_list[index])
	cv2.imshow('image',img)
	k=cv2.waitKey(20) 
	if (k==ord('q')):
		break
	elif(k==ord('[')):
		index-=1
		index%=l
	elif(k==ord(']')):
		index+=1
		index%=l
	elif(k==ord('c')):
		try:
			cv2.destroyWindow('warp')
		except:
			pass
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
		pts=np.array(eval(str(border)),dtype="float32")
		warped=four_point_transform(img,pts)
		cv2.imshow('warp',warped)
		cv2.imwrite(img_list[index].replace('for_crop','cropped'),warped)

cv2.destroyAllWindows()