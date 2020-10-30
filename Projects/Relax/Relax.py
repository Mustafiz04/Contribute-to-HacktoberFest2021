import pygame
import random
import turtle
import time
import threading
import sys

pygame.mixer.init()
kill_command=False
def get ():
    time.sleep(1140)
    kill_command=True

thread=threading.Thread(target=get)
thread.start()


pygame.mixer.music.load('lofi.mp3')
#pygame.mixer.music.play()


turtle.bgcolor("black")

t=turtle.Turtle()
t2=turtle.Turtle()
t3=turtle.Turtle()
t4=turtle.Turtle()

t.ht()
t2.ht()
t3.ht()
t4.ht()

t.pensize(20)
t2.pensize(20)
t3.pensize(20)
t4.pensize(20)

l=['yellow', 'gold', 'orange', 'red', 'maroon', 'violet', 'magenta', 'navy', 'blue', 'skyblue', 'cyan', 'turquoise', 'lightgreen', 'green', 'darkgreen', 'chocolate', 'brown', 'gray', 'white']

while True:
    ch=random.randint(1,4)
    ch2=random.randint(1,4)
    ch3=random.randint(1,4)
    ch4=random.randint(1,4)
    
    t.color(random.choice(l))
    t2.color(random.choice(l))
    t3.color(random.choice(l))
    t4.color(random.choice(l))
    
    if ch==1:
        t4.right(ch4*10)
        t3.left(ch3*10)
        t2.right(ch2*10)
        t.left(ch*10)
    elif ch==2:
        t4.left(ch4*10)
        t3.right(ch3*10)
        t2.left(ch2*10)
        t.right(ch*10)
    elif ch==3:
        t4.right(ch4*100)
        t3.left(ch3*100)
        t2.right(ch2*100)
        t.left(ch*100)
    elif ch==4:
        t4.left(ch4*100)
        t3.right(ch3*100)
        t2.left(ch2*100)
        t.right(ch*100)
    t.fd(15)
    t2.fd(15)
    t3.fd(15)
    t4.fd(15)
    if kill_command:
        break
writer=turtle.Turtle()
writer.ht()
writer.write("Thanks for joining!")
