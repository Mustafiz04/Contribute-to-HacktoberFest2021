# **Lib-Python-Project**
---

### This is a simple project using vanilla Python and Mysql
> **Prerequists :**
 - Python 3.8 +
 - MySQL Connector/Python 8.0

[Download links](#DOWNLOAD-LINKS)

### It was created as a program to be used in a library 
> **The Program tries to achive the following things:**
 - Book tracking (Which includes adding books, deleting them their lending and returning.)
- Student tracking (This also includes the logging of students)
 - The program intergrates the use of MySQL Connector 
  

#  **MySQL TABLE DISCRIPTION**
-------
># **Table book :-**

| Field    | Type | Null | Key | Default | Extra |
|----------|-------------|------|-----|---------|-------|
| bk_id    | int(4)      | NO   | PRI | NULL    |       |
| bname    | varchar(50) | YES  |     | NULL    |       |
| is_issue | int(4)      | YES  |     | NULL    |       |
| author   | varchar(20) | YES  |     | NULL    |       |
| type     | varchar(10) | YES  |     | NULL    |       |
| price    | int(5)      | YES  |     | NULL    |       |

># **Table Student :-**

| Field | Type | Null | Key | Default | Extra |
|----------|-------------|------|-----|---------|-------|
| st_id | int(4)      | NO   | PRI | NULL    |       |
| sname | varchar(25) | YES  |     | NULL    |       |
| st_cd | varchar(10) | YES  |     | NULL    |       |
| book  | int(4)      | YES  |     | NULL    |       |

#### **DOWNLOAD-LINKS**

[![mysql](https://i.ibb.co/MCjFnY3/Mysql.png)](https://drive.google.com/file/d/1atgvrxOllQFe0fN6j3T2MJfnDmEaCNlH/view?usp=sharing)
[![python](https://i.ibb.co/0XCPPcF/Python.png)](https://www.python.org/)

>**PIP COMMAND FOR MYSQL-CONNECTOR**

`pip install mysql-connector-python`