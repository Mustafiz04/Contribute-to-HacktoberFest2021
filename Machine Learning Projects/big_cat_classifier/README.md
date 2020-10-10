Ever looked at a photo of a big ferocious looking cat with big gnarly teeth and having spots all over its body and wondered whether it is a leopard or a cheetah? Well, worry not as deeplearning's got your back. This is the implementation of a fully functional classifier that recognizes from among the various species of big cats like Lion, Cheetah, Leopard, or Jaguar.

## How It Works:
  
  The above code is written and implemented using Jupyter notebooks running Python 3, and makes use of a technique called as Transfer learning in Deep Learning. Here's a step-by-step approach:
  1. Downloaded images into path using Bing Image search API.
  2. Creating Dataloaders from DataBlocks using fastai library, keeping 20% data as validation set.
  3. Downloaded parameters and fine tuned the *Resnet-50* model on the data.
  4. Exported the inference of the model to be used in application.
  5. Used IPythonWidgets provided by Jupyter to create a notebook app.
  
  
## How To Use:

![ss](Machine Learning Projects/big_cat_classifier/Screenshot (8).png)

  1. The testing.ipynb notebook can be used to test images and see the application working properly.
  2. Upload a file using the upload button.
  3. Click on Classify, and Voila!...you have the prediction made by the model along with the model's confidence.
