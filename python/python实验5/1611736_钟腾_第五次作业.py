'''
Created on 2018年11月8日

@author: zhongteng
'''

class Common:
    
    def __init__(self,num_left,num_right):
        self.left = num_left
        self.right = num_right
        self.count = -1    
    
    def __iter__(self):
        return self
    
    def __getitem__(self,item):
        return self.right[item]
    
    def __next__(self):
        if self.count >= len(self.left)-1:
            raise StopIteration
        else:
            self.count += 1
            return self.left[self.count]
        
common = Common(['a','b','c'],[1,2,3])
 
def print_left():
    print('num_left:')
    for i in common:
        print(i)
        
def print_right():
    print('num_right:')
    for i in range(0,3):
        print(common[i])

def print_total(com):
    for i in com.left:
        yield i
    for i in com.right:
        yield i

print_left()
print_right()

print('num_total:')
for i in print_total(common):
    print(i)