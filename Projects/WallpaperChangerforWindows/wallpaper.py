import json
import requests
import urllib.request as url
import os

a = "yhM2ZxT7Bwk5yCWNLbn_QOiAfmTEWRrSJSbkbQ4ityw"
query = "ocean" #change it as you like !!
x = "https://api.unsplash.com/search/collections?query="+query+"&page=1&per_page=30&client_id="+a
j = requests.get(x)
j = j.json()
l = []
for i in range(30):
  img_url = j['results'][i]['cover_photo']['urls']['regular']
  l.append(img_url)
t = os.getcwd()
path = t+"\images"
try:  
  os.mkdir(path)  
except OSError as error:  
  print(error)

for i in range(30):
  img_url = j['results'][i]['cover_photo']['id']
  file = "./images/"+ str(img_url) + '.jpg'
  url.urlretrieve(l[i],file)

