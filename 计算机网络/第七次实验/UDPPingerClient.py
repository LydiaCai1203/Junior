from socket import *
import time

clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(3) #设置1秒的延迟

minimum = 10 #RTT最小值
maximum = 0 #RTT最大值
sum_RTT = 0 #RTT总值
average_RTT = 0 #平均RTT
loss_count = 0 #丢包数量

for i in range(0,10):
    send_time = time.time() #记录发送时间
    message = 'Ping '+str(i)+' '+str(send_time) #发送报文格式
    clientSocket.sendto(message.encode('utf-8'),('10.41.51.25',12000)) #发送报文

    try:
        count = 0
        RTT = 0
        received_message = clientSocket.recv(1024).decode('utf-8') #接收返回信息
        received_type,received_num= received_message.split()[0],received_message.split()[1] #截取报文类型和报文序号
        received_time = time.time() #记录接收时间
        RTT = received_time - send_time #计算RTT
        sum_RTT = sum_RTT+RTT #计算RTT总值
        if maximum<RTT: #计算RTT最大值
            maximum = RTT
        
        if minimum>RTT: #计算RTT最小值
            minimum = RTT
        print(received_type,received_num,send_time) #打印报文
        print("RTT:",RTT) #打印RTT

    except:
        print('Request timed out')
        loss_count = loss_count+1 #统计丢包数量
        continue

average_RTT = sum_RTT/(10-loss_count) #计算平均RTT
print("minimum:",minimum," maximum:",maximum," average_RTT:",average_RTT," loss_rate:",float(loss_count/10)*100,"%") #打印统计数据