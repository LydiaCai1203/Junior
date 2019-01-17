#引用PIL包
from PIL import Image
import argparse

#创建解析对象
parser = argparse.ArgumentParser()

#在创建的对象中添加关注的命令行参数和选项
parser.add_argument('file') #输入文件
parser.add_argument('-o','--output') #输出文件
parser.add_argument('--width',type = int,default = 140) #输出字符画的宽度
parser.add_argument('--height',type = int,default = 80) #输出字符画的高度

#调用parse_args()方法进行解析
args = parser.parse_args()

#使用
IMG = args.file
WIDTH = args.width
HEIGHT = args.height
OUTPUT = args.output

ascii_char = list("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ")

#字符与RGB的对应的映射关系
def get_char(r,g,b,alpha=256):
    if alpha == 0 :
        return ' '
    lenght = len(ascii_char)
    gray = int(0.2126 * r + 0.7152 * g + 0.0722 * b)
    unit = (256.0 + 1)/lenght
    return ascii_char[int(gray/unit)]

#设置图片大小
if __name__ == '__main__':
    im = Image.open(IMG)
    im = im.resize((WIDTH,HEIGHT),Image.ANTIALIAS)
    txt = ""

    for i in range(HEIGHT):
        for j in range(WIDTH):
            #im.getpixel:根据坐标取得RGB对应的r，g，b三个值,这里的getpixel((i,j))的两个括号非常重要
            txt += get_char(*im.getpixel((j,i)))
        txt += '\n'


#字符输出到文件
if OUTPUT:
    with open(OUTPUT,'w') as f:
        f.write(txt)
else:
    with open("output.txt",'w') as f:
        f.write(txt)