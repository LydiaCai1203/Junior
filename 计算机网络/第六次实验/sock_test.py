'''
Created on 2018年11月13日

@author: zhongteng
'''

from socket import *
from pip._vendor.distlib.compat import raw_input
import time,threading

    
if __name__ == '__main__':
    serverSocket = socket(AF_INET, SOCK_STREAM)
    port_num = 6781
    serverSocket.bind(('10.41.169.203', port_num))
    serverSocket.listen(5)
    
    # clientSocket = socket(AF_INET, SOCK_STREAM)
    # clientSocket.connect(('10.41.169.203', port_num))
    # sentence = raw_input('input html filename:')
    # clientSocket.send(sentence.encode())
    
    while True:
        print('Ready to serve...')
        connectionSocket, addr = serverSocket.accept()
        try:
            print('From:', addr)
            message = connectionSocket.recv(1024).decode('utf-8')
            if message:
                print(message)
                filename = message.split()[1].split('/')[1].split()[0]
                # filename = sentence
                f = open(filename)
                output_data = f.read()
                connectionSocket.send('\nHTTP/1.1 200 OK\n\n'.encode('utf-8'))
                connectionSocket.send(output_data.encode('utf-8'))
                f.close()
            connectionSocket.send("\r\n".encode())
            
            # modifiedSentence = clientSocket.recv(1024)
            print('From Server:' , modifiedSentence.decode())
            connectionSocket.close()
        except IOError:
            connectionSocket.send('\nHTTP/1.1 404 Not Found\n\n'.encode('utf-8'))
            connectionSocket.close()
    
#     try:
#         threading._start_new_thread(loop) 
#     except:
#         print('ERROR:unable to start thread')
    clientSocket.close()