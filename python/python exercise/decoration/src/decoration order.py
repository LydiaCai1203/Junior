'''
Created on 2018年10月18日

@author: zhongteng
'''
'''usage of format on list tuple dist'''
# site = {"name": "菜鸟教程","url": "www.runoob.com"}
# print("网站名:{name},地址{url}".format( **site))

# my_list = ['菜鸟教','www.runoob.com']
# print("网站名:{0},地址{1}".format(*my_list))

# my_tuple = ('菜鸟','www.runoob.com')
# print("网站名:{0[0]},地址{0[1]}".format(my_tuple))

# s = ' this is my string '
# print(s.split(' '))

# print([x * x for x in range(1,11)])

def make_bond(fun):
    print('----a----')
 
    def inner():
        print('----1----')
        return '<b>' + fun() + '</b>'
 
    return inner
 
 
def make_italic(fun):
    print('----b----')
 
    def inner():
        print('----2----')
        return '<i>' + fun() + '</i>'
 
    return inner
 
 
@make_bond
@make_italic
def test():
    print('----c----')
    print('----3----')
    return 'hello python decorator'
 
 
ret = test()
print(ret)

# def w_say(fun):
# 
#     def inner(name):
#         print('say inner called')
#         fun(name)
# 
#     return inner
# 
# 
# @w_say
# def hello(name):
#     print('hello', name)
# 
# 
# hello('xiaoming')