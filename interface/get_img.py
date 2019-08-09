import socket 


fileName="../captura.jpg"
#MASTER
socket_host="172.20.10.7"
socket_port=32001

# Creates socket
s = socket.socket()

# Connect
s.connect((socket_host, socket_port))
# Send start message
s.send("Start message".encode())

# Opens the file to write
with open(fileName, 'wb') as f:
	print('File openned')
	while True:
		print('Receiving...')
		data = s.recv(1024)
		if not data:
				break
		# Escreve dados
		f.write(data)

f.close()
print('Receiving done')
s.close()
print('Closing connection')