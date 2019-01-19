# from functools import wraps, partial
# import logging

func_log = []
def logged(level,name=None, message=None):
    
    def decorate(func):
        logname = name if name else func.__module__
        logmsg = message if message else func.__name__
        
        def wrapper(*args,**kwargs):
            func_log.append({
                'level':level,
                'name':logname,
                'msg':logmsg
                })
            return func(*args,**kwargs)
            
        return wrapper
    
    return decorate

@logged(0, 'add', 'add x and y')
def add(x,y):
    return x+y

@logged(2)
def spam():
    print('Spam!')
    

add(1, 2)
spam()
for i in func_log:
    print(i)