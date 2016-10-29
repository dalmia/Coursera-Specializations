import urllib
import xml.etree.ElementTree as ET

serviceurl = 'http://python-data.dr-chuck.net/comments_331614.xml'
data=urllib.urlopen(serviceurl).read()
tree = ET.fromstring(data)
count=tree.findall('.//count')
s=0
for c in count:
    s+= int(c.text)


print s
