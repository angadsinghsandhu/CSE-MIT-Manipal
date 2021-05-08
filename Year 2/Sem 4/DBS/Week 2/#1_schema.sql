-- #1
create table employee(
  2  EmpNo number(10) primary key,
  3  EmpName varchar(20) not null,
  4  Gender char(2) not null,
  5  Salary number(10,2) not null,
  6  Address varchar(30) not null,
  7  DNo number(10),
  8  check(gender in('F','M')));


"
Table created.
"

-- #2
create table Department(
  2  DeptNo number(10) primary key,
  3  DeptName varchar(20) unique,
  4  Location varchar(20));

"
Table created.
"

-- #3
alter table employee modify foreign key(dno) references department(deptno);

"
Table altered.
"

-- #4
insert into department values(1, 'CSE', 'MIT');

"
1 row created.
"

-- Inserting Departments
insert into department values(2, 'CCE', 'MIT');

"
1 row created.
"

-- 
insert into department values(3, 'EEE', 'NIIT');

"
1 row created.
"

-- 
insert into department values(4, 'MECH', 'IIT');

"
1 row created.
"

--
insert into employee values(1, 'abcde', 'M', 3000000, 'Manipal', 1);

"
1 row created.
"

--
insert into employee values(2, 'bcdef', 'F', 2000000, 'Manipal', 2);

"
1 row created.
"

--
insert into employee values(3, 'cdefg', 'M', 2500000, 'Bombay', 3);

"
1 row created.
"

--
insert into employee values(4, 'defgh', 'F', 2500000, 'Bombay', 4);

"
1 row created.
"

-- #5
-- Invalid Insertions
insert into employee values(1, 'Jack', 'M', 10000, 'Bangalore', 4);
insert into employee values(1, 'Jack', 'M', 10000, 'Bangalore', 4)

"
ERROR at line 1:
ORA-00001: unique constraint (RAJAT.SYS_C007105) violated 
"

-- 
insert into employee values(5, 'Jack', 'C', 10000, 'Bangalore', 4);
insert into employee values(5, 'Jack', 'C', 10000, 'Bangalore', 4)

"
ERROR at line 1:
ORA-02290: check constraint (RAJAT.SYS_C007104) violated 
"

-- 
insert into department values(1, 'IT', 'MIT');
insert into department values(1, 'IT', 'MIT')

"
ERROR at line 1:
ORA-00001: unique constraint (RAJAT.SYS_C007106) violated 
"

-- 
insert into department values(5, 'CSE', 'MIT');
insert into department values(5, 'CSE', 'MIT')

"
ERROR at line 1:
ORA-00001: unique constraint (RAJAT.SYS_C007107) violated 
"

-- #6
-- Invalid Updation
update employee set gender='C' where EmpNo=2;
update employee set gender='C' where EmpNo=2

"
ERROR at line 1:
ORA-02290: check constraint (RAJAT.SYS_C007104) violated 
"

-- Invalid Deletion
delete from department where deptno=1;
delete from department where deptno=1

"
ERROR at line 1:
ORA-02292: integrity constraint (RAJAT.SYS_C007108) violated - child record 
found 
"

-- #7
select constraint_name from user_constraints where table_name='EMPLOYEE' and constraint_type='R';

"
CONSTRAINT_NAME                                                                 
------------------------------                                                  
SYS_C007108 
"                                                                    

-- Remoing Prev Constraint
alter table employee drop constraint SYS_C007108;

"
Table altered.
"

-- Adding New Constraint
alter table employee add constraint DC_DNo foreign key(dno) references Department(deptno) on delete cascade;

"
Table altered.
"

-- Displaying Employee Table
select * from employee;

"
     EMPNO EMPNAME              GENDER         SALARY ADDRESS                               DNO                                                                                                                                                                                                             
---------- -------------------- ---------- ---------- ------------------------------ ----------                                                                                                                                                                                                             
         1 abcde                M             3000000 Manipal                                 1                                                                                                                                                                                                             
         2 bcdef                F             2000000 Manipal                                 2                                                                                                                                                                                                             
         3 cdefg                M             2500000 Suratkal                                3                                                                                                                                                                                                             
         4 defgh                F             2500000 Bombay                                  4      
"                                                                                                                                                                                                       

-- Displaying Department Table
select * from department;

"
    DEPTNO DEPTNAME             LOCATION                                                                                                                                                                                                                                                                    
---------- -------------------- --------------------                                                                                                                                                                                                                                                        
         1 CSE                  MIT                                                                                                                                                                                                                                                                         
         2 CCE                  MIT                                                                                                                                                                                                                                                                         
         3 EEE                  NIIT                                                                                                                                                                                                                                                                       
         4 MECH                 IIT  
"                                                                                                                                                                                                                                                                  

-- 
delete from department where deptno=3;

"
1 row deleted.
"

-- Displaying Data
select * from employee;

"
     EMPNO EMPNAME              GENDER         SALARY ADDRESS                               DNO                                                                                                                                                                                                             
---------- -------------------- ---------- ---------- ------------------------------ ----------                                                                                                                                                                                                             
         1 abcde                M             3000000 Manipal                                 1                                                                                                                                                                                                             
         2 bcdef                F             2000000 Manipal                                 2                                                                                                                                                                                                             
         4 defgh                F             2500000 Bombay                                  4    
"                                                                                                                                                                                                         

-- 
select * from department;

"
    DEPTNO DEPTNAME             LOCATION                                                                                                                                                                                                                                                                    
---------- -------------------- --------------------                                                                                                                                                                                                                                                        
         1 CSE                  MIT                                                                                                                                                                                                                                                                         
         2 CCE                  MIT                                                                                                                                                                                                                                                                         
         4 MECH                 IIT      
" 