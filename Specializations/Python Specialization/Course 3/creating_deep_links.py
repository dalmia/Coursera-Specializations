import urllib
from BeautifulSoup import *

url=raw_input('Enter URL :')
count=raw_input('Enter Count :')
position=raw_input('Enter position :')
position=int(position)
count=int(count)
for i in range(int(count)):
    html=urllib.urlopen(url).read()
    soup=BeautifulSoup(html)
    tags=soup('a')
    c=0
    for tag in tags:
        c+=1
        if c==position:
            url=tag.get('href',None)
            if i==count-1:
                print tag.contents[0]
                break
