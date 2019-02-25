import time 
import datetime

#创建时间戳
tm = time.time()
#把时间戳转换成struct time  gmtime/localtime
stm = time.gmtime(tm)
print(stm)
# 把struct time 转换成字符串时间 strftime
string_time = time.strftime('%Y-%m-%d %H-%M-%S',stm)
print(string_time)

#把字符串时间转换成struct time strptime
back_stm = time.strptime(string_time,'%Y-%m-%d %H-%M-%S')
print(back_stm)
#把struct time 转换成时间戳 mktime
back_tm = time.mktime(back_stm)
print(back_tm)

#创建字符串时间
str_time = time.ctime()
print(str_time)
#创建struct time 格式时间
struct_time = time.gmtime()
print(struct_time)
struct_time_local =time.localtime()
print(struct_time_local)

# 字典按value排序
# dict1 = {
#     'a':1,
#     'c':3,
#     'b':2
# }
# dict2 = sorted(dict1.items(),key = lambda item:item[1])
# list_1 = []
# list_2 = []
# for i in dict2:
#     list_1.append(i[0])
#     list_2.append(i[1])
# dict3 = dict(zip(list_1,list_2))
# print(dict3)