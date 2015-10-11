import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
addr = ''
port = 12345
sock.bind((addr,port))

sock.listen(5)

while True:
    (clientsocket, address) = sock.accept()
    print(str(address))
    
