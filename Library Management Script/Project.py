# Imports. --------------------------------

import time as t
import mysql.connector as c

# Functions. ------------------------------


# Students ------------------------------

def student():
    while True:
        print("\n")
        print("Student")
        print("---------")
        print("Options:")
        print("1. Add")
        print("2. Display")
        print("3. Delete")
        print("4. Search")
        print("5. Back")
        ch = int(input("Enter the option: "))
        if ch == 1:
            add("std")
        elif ch == 2:
            display("student")
        elif ch == 3:
            x = input("Enter the Student ID: ")
            delete(x,"st_id","student")
        elif ch == 4:
            x = input("Student Name: ")
            search(x,"student","sname")
        elif ch == 5:
            print("Going back to Main Menu")
            t.sleep(1)
            main_menu()
        else:
            print("Invalid option try again.")

# ------------------------------------------

# Book ------------------------------

def book():
    while True:
        print("\n")
        print("Book")
        print("---------")
        print("Options:")
        print("1. Add")
        print("2. Display")
        print("3. Delete")
        print("4. Search")
        print("5. Book Issue")
        print("6. Book Return")
        print("7. Back")
        ch = int(input("Enter the option: "))
        if ch == 1:
            add("book")
        elif ch == 2:
            display("book")
        elif ch == 3:
            x = input("Enter the Book ID: ")
            delete(x,"bk_id", "book")
        elif ch == 4:
            print("How do you want to search?")
            print("1. Author")
            print("2. Type")
            print("3. Book Name")
            ch = int(input("Enter option number: "))
            if ch==1:
                x=input("Enter Name of Author: ")
                search(x, "book", "author")
            elif ch==2:
                x=input("Enter Type of book: ")
                search(x,"book","type")
            elif ch==3:
                x=input("Name of book to search: ")
                search(x, "book", "bname")
            else:
                print("Invalid search")
                t.sleep(2)
                book()
        elif ch == 5:
            x = int(input("Enter Book ID: "))
            y = int(input("Student ID: "))
            cur.execute("select is_issue from book where bk_id={};".format(x))
            if cur.fetchall()[0][0] == 0:
                book_issue(x,y)
                print("Book Taken succesfully")
            else:
                print("Book has not been Returned")
        elif ch == 6:
            x = int(input("Enter Book ID: "))
            z= int(input("Student ID: "))
            cur.execute("select is_issue from book where bk_id={};".format(x))
            y=cur.fetchall()
            print(y[0][0])
            if y[0][0] == z:
                book_return(x,z)
                print("Book Returned succesfully")
            else:
                print("Book has not been Taken Or \n This student has not taken a book")
        elif ch == 7:
            print("Going back to Main Menu")
            t.sleep(3)
            main_menu()
        else:
            print("Invalid option try again.")

# ------------------------------------------

# Add------------------------------

def add(ta):
    if ta == "std":
        x = int(input("Enter Student ID: "))                               # st_id
        cur.execute("select st_id from student;")
        for i in cur.fetchall():
            if x ==i[-1]:
                print("\nThis ID Already Exists\n")
                t.sleep(3)
                student()
        y = input("Enter Student Name: ")
        z = input("Enter student class and Divition: ")
        cur.execute("insert into student values({},'{}','{}',{});".format(x, y, z,0))
    elif ta=="book":
        w = int(input("Enter Book ID: "))
        cur.execute("select bk_id from book;")
        for i in cur.fetchall():
            if w ==i[-1]:
                print("\nThis ID Already Exists\n")
                t.sleep(3)
                book()
        x = input("Enter Book Name: ")
        y=input("Author of name: ")
        z=input("Type of book: ")
        a=int(input("Price: "))
        cur.execute("insert into Book values({},'{}',{},'{}','{}',{});".format(w,x,0,y,z,a))
    con.commit()

# ------------------------------

# Display ------------------------------

def display(x):
    print("\n")
    dash=0
    na=0
    if x == "student":
        cur.execute("insert into {} values(0,'0','0',0) ;".format(x))
        cur.execute("select * from {}".format(x))
        na = cur.fetchall()
    elif x=="book":
        cur.execute("insert into {} values(0,'0',0,'0','0',0) ;".format(x))
        cur.execute("select * from {}".format(x))
        na=cur.fetchall()
    if len(na)==1:
        print("""                   _____________________
                  /                 `   |
                  |  .-----------.  |   |-----.
                  |  |           |  |   |-=---|
                  |  | No one    |  |   |-----|
                  |  | Found  !  |  |   |-----|
                  |  |           |  |   |-----|
                  |  `-----------'  |   |-----'/|
                   \________________/___'     /  |
                      /                      / / /
                     / //               //  / / /
                    /                      / / /
                   / _/_/_/_/_/_/_/_/_/_/ /   /
                  / _/_/_/_/_/_/_/_/_/_/ /   /
                 / _/_/_/_______/_/_/_/ / __/
                /______________________/ /    
                \______________________\/
                """)
        if x == "student":
            cur.execute("delete from student where st_id=0;")
            student()
        else:
            cur.execute("delete from book where bk_id=0;")
            book()

    if x == "student":
        cur.execute("delete from student where st_id=0;")
    else:
        cur.execute("delete from book where bk_id=0;")

    cur.execute("select * from {}".format(x))
    print("The following details will be printed out in the following maner:\n")
    if x=="student":
        print("STUDENT ID \t STUDENT NAME \t Class \t Due book ID".upper())
        print("---------------------------------------")
    if x=="book":
        print("BOOK ID       book name       Available (if=0)       Author       type       Price".upper())
        print("---------------------------------------")
    for i in cur.fetchall():
        print("\n",end="")
        for j in i:
            print(j, end="     |     ")
            dash+=len(i)
        print("\n")
        print("-" * dash)
    else:
        print("That's folks!")

#------------------------------

# Delete ------------------------------

def delete(a,b,z):
    waste = input("""Are you sure you want to delete
    Press enter to confirm/press b and enter to go back """)
    if waste.upper() == "B":
        main_menu()
    cur.execute("delete from {} where {}= {};".format(z,b,a))
    con.commit()

#------------------------------

# Search ------------------------------

def search(x,y,z="sname"):
    cur.execute("select * from {} where {} like '% {}%';".format(y,z,x))
    if len(cur.fetchall())==0:
        print("\n")
        print("Invalid search")
        print("Try Checking The Spelling")
        t.sleep(1)
        print("returning to previoes menu".title())
        if y=="student":
            student()
        elif y=="book":
            book()
    else:
        cur.execute("select * from {} where {} like '%{}%';".format(y, z, x))
        print("\n")
        for i in cur.fetchall():
            for j in i:
                print(j, end=" ")
            print("\n")
    con.commit()

#------------------------------

# Book issue ------------------------------

def book_issue(x,y):                                                         # x bk_id, y st_id
    cur.execute("update book set is_issue={} where bk_id={};".format(y,x))
    cur.execute("update student set book={} where st_id={};".format(x,y))
    con.commit()

#------------------------------

# Book return ------------------------------

def book_return(x,z):
    cur.execute("update book set is_issue=0 where bk_id={};".format(x))
    print(x)
    cur.execute("update student set book = 0 where st_id = {};".format(z))
    con.commit()

# ------------------------------------------

def back(x):
    if x == "std":
        student()
    else:
        book()

# ------------------------------------------

# Main ------------------------------

def main_menu():
    while True:
        print("\n")
        print("Main menu")
        print("---------")
        print("Options:")
        print("1. Student")
        print("2. Book")
        print("3. Exit")
        ch = int(input("Enter the option: "))
        if ch == 1:
            student()
        elif ch == 2:
            book()
        elif ch == 3:
            ask=input("Do you want to confirm your exit and end the program (Y/N) ? ".title())
            if ask.upper()=="Y":
                print("\n")
                for i in range(5,0,-1):
                    print(i)
                    t.sleep(0.5)
                exit()
            else:
                pass
        else:
            print("Invalid option try again.")

# ------------------------------------------

# Connector ------------------------------

con = c.connect(host="localhost", user="root", passwd="1234", database="lib")
cur = con.cursor()
print("""          $$\ $$\ $$\                         $$$$$$\      $$$$$$\        $$\   
          $$ |\__|$$ |                       $$$ __$$\    $$$ __$$\     $$$$ |  
          $$ |$$\ $$$$$$$\        $$\    $$\ $$$$\ $$ |   $$$$\ $$ |    \_$$ |  
          $$ |$$ |$$  __$$\       \$$\  $$  |$$\$$\$$ |   $$\$$\$$ |      $$ |  
          $$ |$$ |$$ |  $$ |       \$$\$$  / $$ \$$$$ |   $$ \$$$$ |      $$ |  
          $$ |$$ |$$ |  $$ |        \$$$  /  $$ |\$$$ |   $$ |\$$$ |      $$ |  
          $$ |$$ |$$$$$$$  |         \$  /   \$$$$$$  /$$\\$$$$$$  /$$\ $$$$$$\ 
          \__|\__|\_______/           \_/     \______/ \__|\______/ \__|\______|""")

#------------------------------

while True:
    main_menu()

# FIN ------------------------------
