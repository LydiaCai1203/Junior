from bs4 import BeautifulSoup
import requests
from collections import deque

BASE_URL = 'https://www.autohome.com.cn/159/0/0-0-1-0/#pvareaid=3454442' #车型网址
TITLE_COUNT = 1  #标题计数
PAGE_COUNT = 1  #页数

init_queue = deque()  #页面列表
init_queue.append(BASE_URL)

if __name__ == '__main__':
    while init_queue:
        url = init_queue.popleft()
        try:
            start_html = requests.get(url)
            data = BeautifulSoup(start_html.text,"html.parser")  #爬下网页html文件
        except:
            continue
        print('第' + str(PAGE_COUNT) + '页')
        for link in data.find_all('h3'):  #找到标题并输出
            sublink = link.find_all('a')
            substring = sublink[0]
            print(str(TITLE_COUNT) + '.' + substring.string)
            TITLE_COUNT += 1
        
        for next_page in data.find_all('a'):  #找到下一页的按钮，将下一页网址加入到页面列表中
            if next_page.string == '下一页':
                next_page_url = next_page.get('href')[2:]
                next_page_url = 'https://' + next_page_url
                init_queue.append(next_page_url)
        PAGE_COUNT += 1
        