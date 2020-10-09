drop database school;
create database school;
use school
create table emp(eno int(4) primary key,ename varchar(20),desig varchar(10),salary int(5), dname varchar(10),comm int(4),doj date);
insert into emp values(101,'Hima','Officer',25000,'Purchase',NULL ,NULL);
insert into emp values(102,'Manu','Clerk',14000,'Purchase',1000,'2009-09-09');
insert into emp values(103,'Deepak','Manager',50000,'Admin',5000,NULL);
select * from emp;