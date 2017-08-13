import json
import urllib

url="http://python-data.dr-chuck.net/comments_331618.json"
data=urllib.urlopen(url).read()

info = json.loads(data)['comments']
s=0
for item in info:
    s+= int(item['count']);
print s
