'''
Created on 2018年10月25日

@author: zhongteng
'''

from test.test_isinstance import AbstractClass
from abc import abstractmethod
from builtins import input
import random

class Lottery():
    @AbstractClass
    
    def __init__(self):
        winbnumber = []
        winanumber = []
    
    @abstractmethod
    def checkFormat(self):
        pass
    
    @abstractmethod
    def getLevel(self):
        pass
    
class DoubleLotery(Lottery):
    
    def __init__(self):
        self.winbnumber = []
        self.winanumber = []
        while len(self.winbnumber)<6:
            r = random.randint(1,33)
            if not r in self.winbnumber:
                self.winbnumber.append(r)
        self.winanumber.append(random.randint(1,16))
        
    def checkFormat(self,arg1):
        for i in arg1:
            if arg1.count(i)!=1:
                return False
        for i in range(0,6):
            if arg1[i]<1 or arg1[i]>33:
                return False
        if arg1[6]<1 or arg1[6]>16:
            return False
        return True
    
    def getLevel(self,arg1):
        counta = 0
        countb = 0
        for i in range(0,6):
            for j in range(0,6):
                if arg1[i]==self.winbnumber[j]:
                    countb+=1
        if arg1[6]==self.winanumber[0]:
            counta+=1
        if countb==6 and counta==1:
            return 1
        elif countb==6 and counta==0:
            return 2
        elif countb==5 and counta==1:
            return 3
        elif (countb==5 and counta==0) or (countb==4 and counta==1):
            return 4
        elif (countb==4 and counta==0) or (countb==3 and counta==1):
            return 5
        elif (countb==2 and counta==1) or (countb==1 and counta==1) or (countb==0 and counta==1):
            return 6
        else:
            return 0
        

class BigLotery(Lottery):
    
    def __init__(self):
        self.winbnumber = []
        self.winanumber = []
        while len(self.winbnumber)<5:
            r = random.randint(1,35)
            if not r in self.winbnumber:
                self.winbnumber.append(r)
        while len(self.winanumber)<2:
            r = random.randint(1,12)
            if not r in self.winanumber:
                self.winanumber.append(r)
        
    def checkFormat(self,arg1):
        for i in arg1:
            if arg1.count(i)!=1:
                return False
        for i in range(0,5):
            if arg1[i]<1 or arg1[i]>35:
                return False
        for i in range(5,7):
            if arg1[i]<1 or arg1[i]>12:
                return False
        return True
    
    def getLevel(self,arg1):
        counta=0
        countb=0
        for i in range(0,5):
            for j in range(0,5):
                if arg1[i]==self.winbnumber[j]:
                    countb+=1
        for i in range(5,7):
            for j in range(0,2):
                if arg1[i]==self.winanumber[j]:
                    counta+=1
        if countb==5 and counta==2:
            return 1
        elif countb==5 and counta==1:
            return 2
        elif (countb==5 and counta==0) or (countb==4 and counta==2):
            return 3
        elif (countb==4 and counta==1) or (countb==3 and counta==2):
            return 4
        elif (countb==4 and counta==0) or (countb==3 and counta==1) or (countb==2 and counta==2):
            return 5
        elif (countb==3 and counta==0) or (countb==1 and counta==2) or (countb==2 and counta==1) or (countb==0 and counta==2):
            return 6
        else:
            return 0
            

print("请选择玩法 输入数字: 1.双色球 2.大乐透")
type = int(input())
correctnumber = []

if not (type==1 or type==2):
    print("ERROR!")
    
if type==1:
    print("请输入前6个中奖号码，范围为1-33")
    for i in range(0,6):
        correctnumber.append(int(input()))
    print("请输入最后一位中奖号码，范围为1-16")
    correctnumber.append(int(input()))
    mynumber = DoubleLotery()
    if not (mynumber.checkFormat(correctnumber)):
        print("ERROR!")
    else:
        print("中奖号码是："+str(mynumber.winbnumber)+str(mynumber.winanumber))
        if mynumber.getLevel(correctnumber)==0:
            print("您没有中奖")
        else:
            print("您中了%d等奖!" % mynumber.getLevel(correctnumber))        
elif type==2:
    print("请输入前5个中奖号码，范围为1-35")
    for i in range(0,5):
        correctnumber.append(int(input()))
    print("请输入后两位中奖号码，范围为1-12")
    for i in range(0,2):
        correctnumber.append(int(input()))
    mynumber = BigLotery()
    if not (mynumber.checkFormat(correctnumber)):
        print("ERROR!")
    else:
        print("中奖号码是："+str(mynumber.winbnumber)+str(mynumber.winanumber))
        if mynumber.getLevel(correctnumber)==0:
            print("您没有中奖")
        else:
            print("您中了%d等奖!" % mynumber.getLevel(correctnumber))  
    