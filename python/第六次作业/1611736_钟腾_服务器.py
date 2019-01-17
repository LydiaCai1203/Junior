import random
import time
from socket import *

# Create a UDP socket 
serverSocket = socket(AF_INET, SOCK_DGRAM)
# Assign IP address and port number to socket
serverSocket.bind(('10.41.51.25', 10000))

while True:
	print('listening..')  
	# Receive the client packet along with the address it is coming from 
	message, address = serverSocket.recvfrom(1024)
	message = float(message)
	message = time.gmtime(message)
	message = time.strftime("%Y-%m-%d %H-%M-%S",message)
	serverSocket.sendto(message.encode('utf-8'), address)