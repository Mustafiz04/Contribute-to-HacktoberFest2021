a = 1
while a in range (100):      # Remember to change to 100 in range
    a = a + 1
    print("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *")
for i in range(100,2,-1):     # Remember to change to 100 in range
    for j in range(i,2,-1):
        print("*",end =" ")
    print()
b =1
while b in range(75):
    print()
    b+=1
name =input("Enter your name ")
print ('''
???: Hello''',name,',','''
C-3PO: My name is C-3PO

R2-D2: And I am R2-D2
''')
waste =input("Enter next(ie. hit enter) ")
print()
# noinspection PyRedeclaration
waste =input("OH no! some error has occured ")
Number  = 925 # Remember to change it to 925
i  = 0
First_Value  = 0
Second_Value  = 1
while i < Number:
           if i < 1 or i == 1:
               Next  = i
           else:
               Next  = First_Value + Second_Value
               First_Value  = Second_Value
               Second_Value  = Next
           print(Next)
           i  = i + 1
b =1
while b in range(75):
    print()                                                                                                # This is to make the program colourfull
    b+=1                                                                                                   #..................................................................
waste =input("R2-D2: Phew, I thougt it was some bug!  ")                                                    #...................................................................
print()                                                                                                    #....................................................................
info =input('''C-3PO: So we have introduced our selfs, Now tell us more about you,                          
tell us what you like: ''')
if info == "death" or info == "no":
    print("death avaits you ")
    waste =input("So face it ")
    exit()
print()
x ="C-3PO: Oh! It seems that you and R2-D2 have some thing in common, "+str(info)+" !"
# noinspection PyRedeclaration
waste =input(x)
print()
yn =input("C-3PO: So would you like to come with us? ")
if yn == "no" or yn == "nope":
    print("death avaits you ")
    waste =input("So face it ")
    exit()
print()
# noinspection PyRedeclaration
waste  =input("C-3PO: So you decided to come with us! ")
print()
# noinspection PyRedeclaration
waste  =input("R2-D2: Good choice we were going to Tatooine!")
print()
# noinspection PyRedeclaration
waste  =input("C-3PO: Shh! don't mind him!(to you) We are not going to Tatooine. We were going to buy some house hold stuff!.")
waste = input("R2-D2: Anyway lets go")
waste = input("At the store")
shop = input("C-3PO: Pls type apple to pick an apple")
if shop.upper()=="apple".upper():
    print("You have succesfully chosen apple")
else:
    while True:
        shop = input("C-3PO: Pls type apple to pick an apple")
        if shop.upper()=="apple".upper():
            print("You have succesfully chosen apple")
            Break
print("Thank you for shopping with us!")
