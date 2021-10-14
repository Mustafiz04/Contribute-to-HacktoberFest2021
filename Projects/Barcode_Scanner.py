from pyzbar import pyzbar
import argparse
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,help="path to input image")
args = vars(ap.parse_args())
image = cv2.imread(args["image"])
barcodes = pyzbar.decode(image)

for barcode in barcodes:
    (x,y,w,h) = barcode.rect
    cv2.rectangle(image,(x,y),(x+w,y+h),(255.5,255),2)
    
    barcodeData = barcode.data.decode("utf-8")
    barcodeType = barcode.type
    
    print("{}({})".format(barcodeData,barcodeType))
cv2.imshow("image",image)
cv2.waitKey(0)
