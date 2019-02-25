from socket import *
import time
import threading

clientSocket = socket(AF_INET, SOCK_DGRAM)
#clientSocket.settimeout(10) #设置10秒的延迟

def send_recv_message():
    send_time = time.time() #记录发送时间
    message = str(send_time) #发送报文格式
    print("send_message:",send_time) #打印报文
    clientSocket.sendto(message.encode('utf-8'),('10.41.51.25',10000)) #发送报文

    try:
        received_message = clientSocket.recv(1024).decode('utf-8')#接收返回信息
        print("received_message:",received_message) #打印报文

    except:
        print('Request timed out')
    
    finally:
        timer = threading.Timer(10,send_recv_message)   #10秒调用一次函数
        timer.start()    #启用定时器

if __name__ == '__main__':
    global timer  #定义变量
    timer = threading.Timer(1,send_recv_message)
    timer.start()    #启用定时器