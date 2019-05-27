import socket
import sys

# Sao passados 3 argumentos neste codigo
# O primeiro eh o ip do servidor (raspberry)
# O segundo eh a porta a ser usada, se possivel usar a 32000
# O terceiro eh o nome do arquivo onde serao salvos os dados recebidos
args = sys.argv
HOST=args[1]
PORT=int(args[2])
fileName = args[3]

# Cria o socket
s = socket.socket()

# Conecta o socket
s.connect((HOST, PORT))
# Envia uma mensagem de inicio para confirmar conexao
s.send("Mensagem de inicio".encode())

# Abre o arquivo a ser escrito e recebe os dados enquanto escreve no mesmo
with open(fileName, 'wb') as f:
    print('Arquivo aberto')
    while True:
        print('Recebendo dado...')
        data = s.recv(1024)
        if not data:
            break
        # Escreve dados
        f.write(data)

f.close()
print('Recebimento realizado com sucesso')
s.close()
print('Fechando conexao')