装饰器、作者相关guido van rossum 1989Python 荷兰人  “仁慈大君” 英国肥皂剧<Monty Python飞行马戏团>、大小写敏感、raise

number支持int、float、bool、comlpex（复数）

complex("1+2j")

low() upper() capitalize() strip()去掉首尾字符 

index()  str.index(str, beg=0, end=len(string))

```python
str.find(str, beg=0, end=len(string))
```

没有子字符串返回-1

eval( '3 * x' ) 返回表达式的值 只能执行一个表达式

```python
exec("print(x,y)")
```

exec可执行复杂的python代码，不像eval那样只能计算一个表达式的值，返回值永远是None

c=copy.copy(alist)

count() str.count("i", 4, 40) 

repr() 转化成字符串 repr() 转化为供解释器读取的形式。

compile() 函数将一个字符串编译为字节代码。

字典 查询速度快、遍历、多少生成方法

extend() == +=

列表生成式 生成器 lamda匿名函数  map  fiter  reduce  mapreduce一定会考

非贪婪匹配 正则表达式

闭包

函数传参