from PIL import Image
img = Image.open('lisa.jpg')
thresh = 200
fn = lambda x : 255 if x > thresh else 0
r = img.convert('1')
r.save('foo.png')