import socket 
import sys

# Sao passados 3 argumentos neste codigo
# O primeiro eh o ip do servidor (raspberry)
# O segundo eh a porta a ser usada, se possivel usar a 32000
# O terceiro eh o nome do arquivo que sera enviado
args = sys.argv
HOST=args[1]
PORT=int(args[2])
fileName = args[3]

# Cria o socket
s = socket.socket()
# Faz a ligacao com o socket
s.bind((HOST, PORT))
# Espera 1 cliente se conectar
s.listen(1)

print('Servidor ouvindo...')
# Se conecta com o cliente
conn, addr = s.accept()
print('Conectado a', addr)
data = conn.recv(1024)
print('Mensagem inicial recebida', repr(data))

# Abre o arquivo especificado e envia pacotes de 1024 bytes ate finalizar
f = open(fileName,'rb')
l = f.read(1024)
while (l):
   conn.send(l)
   l = f.read(1024)
f.close()

print('Envio finalizado')
conn.close() 