-- #8
alter table employee modify salary default 10000;

"
Table altered.
"

-- 
insert into employee(empno, empname, gender, address, dno) values(8, 'Test', 'M', 'Bangalore', 1);

"
1 row created.
"

-- 
select * from employee;

"
     EMPNO EMPNAME              GENDER         SALARY ADDRESS                               DNO                                                                                                                                                                                                             
---------- -------------------- ---------- ---------- ------------------------------ ----------                                                                                                                                                                                                             
         1 abcde                M             3000000 Manipal                                 1                                                                                                                                                                                                             
         2 bcdef                F             2000000 Manipal                                 2                                                                                                                                                                                                             
         4 defgh                F             2500000 Bombay                                  4                                                                                                                                                                                                             
         8 Test                 M               10000 Bangalore                               1       
"  