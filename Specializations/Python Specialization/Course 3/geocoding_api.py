import urllib
import json
base_url="http://python-data.dr-chuck.net/geojson?"
address=raw_input("Address :")
url=base_url + urllib.urlencode({'sensor':'false','address':address})
data=urllib.urlopen(url).read()
val=json.loads(str(data))
print val['results'][1]['place_id']
