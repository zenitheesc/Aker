from serial import Serial
import RPi.GPIO as GPIO
import numpy as np
import socket 
import time
import cv2
import sys
import os


def take_picture(fileName="captura.jpg", w=600, h=500):
	os.system("raspistill -vf -hf -o " + fileName + " -w " + str(w) + " -h " + str(h))

def determine_attitude(fileName="captura.jpg", outputFileName="adc_cv.dat"):
	#Get the image
	img = cv2.imread(fileName)

	# Image size
	img_shape = img.shape
	img_center_x = img_shape[1]/2
	img_center_y = img_shape[0]/2

	# Camera opening angle
	cam_angle = 160

	# Output file
	output_file = open(outputFileName, "w")

	# BGR to grayscale
	imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

	# Findo contours
	edges = cv2.Canny(imgGray,50,150,apertureSize = 3)

	# Find lines 
	lines = cv2.HoughLines(edges,1,np.pi/180,10)

	# Process lines
	if lines is not None: 
		for rho,theta in lines[0]:
			# Get the line
			a = np.cos(theta)
			b = np.sin(theta)
			x0 = a*rho
			y0 = b*rho
			x1 = int(x0 + 1000*(-b))
			y1 = int(y0 + 1000*(a))
			x2 = int(x0 - 1000*(-b))
			y2 = int(y0 - 1000*(a))
			#limits the line size
			#to find the center
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
		
		#line position
		pos_line = ((x1+x2)/2,(y1+y2)/2)
	else:
		#if nothing was found, put an absurde value
		pos_line = (-1,-1)    

	#find circles
	circles = cv2.HoughCircles(imgGray,cv2.HOUGH_GRADIENT,1,200, param1=10,param2=30,minRadius=2,maxRadius=100)
	#process circles
	if circles is not None:
		circles = np.uint16(np.around(circles))
		#sort by radius
		circles_s = sorted(circles, key=lambda tup: tup[:,2])
		#get the center of the biggest circle
		x_c = circles_s[0][0][0]
		y_c = circles_s[0][0][1]
		r_c = circles_s[0][0][2]
		
		#circle pos
		pos_circle = (x_c, y_c)
		
		#finds the angle 
		sun_dif_angle = x_c*cam_angle/img_shape[1]
		sun_dif_angle = sun_dif_angle - cam_angle/2
	else:
		#absurd values
		pos_circle = (-1,-1)
		sun_dif_angle = -360


	#saves to the file
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
	
	found = 0
	if sun_dif_angle < 0:
		found = 1

	return found
	
def main():		
	print("Taking picture")
	take_picture()
	
	print("Determining attitude")
	determine_attitude()		
if __name__ == '__main__':
	main()

