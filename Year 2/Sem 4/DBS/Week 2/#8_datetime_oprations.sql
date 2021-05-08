-- Adding DOBs to the Database
select * from employee;

"
    EMP_NO EMP_NAME             GENDER         SALARY ADDRESS                                                   DNO                                                                                                                                                                                         
---------- -------------------- ---------- ---------- -------------------------------------------------- ----------                                                                                                                                                                                         
         2 bcdef                  F             2000000 Manipal                                                 2                                                                                                                                                                                         
         3 cdefg                  M             2500000 Bombay                                                  3                                                                                                                                                                                         
         1 abcde                  M             3000000 Manipal                                                 1                                                                                                                                                                                         
         4 defgh                  F             2500000 Bombay                                                  4       
"                                                                                                                                                                                  

-- 
alter table employee add(dob date);

Table altered.

-- 
update employee set dob='20-OCT-2000' where emp_no=2;

1 row updated.

-- 
update employee set dob='17-MAY-2001' where emp_no=3;

1 row updated.

-- 
update employee set dob='18-MAY-2001' where emp_no=1;

1 row updated.

-- 
update employee set dob='28-NOV-2001' where emp_no=4;

1 row updated.

-- #24
select emp_name, to_char(dob, 'DD-MON-YYYY') from employee;

"
EMP_NAME             TO_CHAR(DOB,'DD-MON-YYYY')                                                                                                                                                                                                                                                                   
-------------------- --------------------                                                                                                                                                                                                                                                                   
bcdef              20-OCT-2000                                                                                                                                                                                                                                                                            
cdefg             17-MAY-2001                                                                                                                                                                                                                                                                            
abcde                18-MAY-2001                                                                                                                                                                                                                                                                            
defgh             28-NOV-2001 
"
                                                                                                                                                                                                                                                                           


select emp_name, to_char(dob, 'DD-MON-YY') from employee;

"
EMP_NAME             TO_CHAR(DOB,'DD-MON-YY')                                                                                                                                                                                                                                                          
-------------------- ------------------                                                                                                                                                                                                                                                                     
bcdef                    20-OCT-00                                                                                                                                                                                                                                                                              
cdefg                    17-MAY-01                                                                                                                                                                                                                                                                              
abcde                    18-MAY-01                                                                                                                                                                                                                                                                              
defgh                    28-NOV-01   
"                                                                                                                                                                                                                                                                           

-- 
select emp_name, to_char(dob, 'DD-MM-YY') from employee;

"
EMP_NAME             TO_CHAR(                                                                                                                                                                                                                                                                               
-------------------- --------                                                                                                                                                                                                                                                                               
bcdef               20-10-00                                                                                                                                                                                                                                                                               
cdefg               17-05-01                                                                                                                                                                                                                                                                               
abcde               18-05-01                                                                                                                                                                                                                                                                               
defgh               28-11-01  
"                                                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                                        
-- #25
 select emp_name, to_char(to_date(to_char(dob, 'YYYY'),'j'),'jsp') from dual, employee;

"
EMP_NAME             TO_CHAR(TO_DATE(TO_CHAR(DOB,'YYYY'),'J'),'JSP')                                                                                                                                                                                                                                        
-------------------- ------------------------------------------------------------------------------                                                                                                                                                                                                         
bcdef                          two thousand                                                                                                                                                                                                                                                                           
cdefg                        two thousand one                                                                                                                                                                                                                                                                       
abcde                        two thousand one                                                                                                                                                                                                                                                                       
defgh                        two thousand one  
"                                                                                                                                                                                                                                                                     

-- #26
select emp_name, to_char(dob, 'DAY') from employee;

"
EMP_NAME             TO_CHAR(DOB,'DAY')                                                                                                                                                                                                                                                                     
-------------------- ------------------------------------                                                                                                                                                                                                                                                   
bcdef                     FRIDAY                                                                                                                                                                                                                                                                                 
cdefg                    THURSDAY                                                                                                                                                                                                                                                                               
abcde                     FRIDAY                                                                                                                                                                                                                                                                                 
defgh                    WEDNESDAY     
"                                                                                                                                                                                                                                                                         

-- #27
select emp_name, to_char(dob, 'MONTH') from employee;

"
EMP_NAME             TO_CHAR(DOB,'MONTH')                                                                                                                                                                                                                                                                   
-------------------- ------------------------------------                                                                                                                                                                                                                                                   
bcdef                     OCTOBER                                                                                                                                                                                                                                                                                
cdefg                       MAY                                                                                                                                                                                                                                                                                    
abcde                       MAY                                                                                                                                                                                                                                                                                    
defgh                     NOVEMBER  
"

-- #28
select emp_name, last_day(dob), to_char(last_day(dob), 'DAY') from employee where emp_name='&employee_name';

"
Enter value for employee_name: abcde
old   1: select emp_name, last_day(dob), to_char(last_day(dob), 'DAY') from employee where emp_name='&employee_name'
new   1: select emp_name, last_day(dob), to_char(last_day(dob), 'DAY') from employee where emp_name='abcde'

EMP_NAME             LAST_DAY( TO_CHAR(LAST_DAY(DOB),'DAY')                                                                                                                                                                                                                                                 
-------------------- --------- ------------------------------------                                                                                                                                                                                                                                         
abcde                31-MAY-01 THURSDAY    
"                                                                                                                                                                                                                                                                 

-- #29
select emp_name, trunc((sysdate - dob)/365.25) as age from dual, employee;

"
EMP_NAME                    AGE                                                                                                                                                                                                                                                                             
-------------------- ----------                                                                                                                                                                                                                                                                             
bcdef                       20                                                                                                                                                                                                                                                                             
cdefg                       19                                                                                                                                                                                                                                                                             
abcde                       19                                                                                                                                                                                                                                                                             
defgh                       19      
"                                                                                                                                                                                                                                                                       

-- #30
select emp_name, next_day(add_months(dob, 720), 'SATURDAY') from employee where emp_name='&employee_name';

"
Enter value for employee_name: bcdef

old   1: select emp_name, next_day(add_months(dob, 720), 'SATURDAY') from employee where emp_name='&employee_name'
new   1: select emp_name, next_day(add_months(dob, 720), 'SATURDAY') from employee where emp_name='bcdef'

EMP_NAME             NEXT_DAY(                                                                                                                                                                                                                                                                              
-------------------- ---------                                                                                                                                                                                                                                                                              
bcdef              23-OCT-60                                                                                                                                                                                                                                                                              

"

-- #31
select emp_name from employee where extract(year from dob) = '&year';

"
Enter value for year: 2001

old   1: select emp_name from employee where extract(year from dob) = '&year'
new   1: select emp_name from employee where extract(year from dob) = '2001'

EMP_NAME                                                                                                                                                                                                                                                                                                    
--------------------                                                                                                                                                                                                                                                                                        
cdefg                                                                                                                                                                                                                                                                                                    
abcde                                                                                                                                                                                                                                                                                                       
defgh 
"                                                                                                                                                                                                                                                                                               

-- #32
select emp_name from employee where extract(year from dob) between '&start_year' and '&end_year';

"
Enter value for start_year: 2000
Enter value for end_year: 2001

old   1: select emp_name from employee where extract(year from dob) between '&start_year' and '&end_year'
new   1: select emp_name from employee where extract(year from dob) between '2000' and '2001'

EMP_NAME                                                                                                                                                                                                                                                                                                    
--------------------                                                                                                                                                                                                                                                                                        
bcdef                                                                                                                                                                                                                                                                                                     
cdefg                                                                                                                                                                                                                                                                                                    
abcde                                                                                                                                                                                                                                                                                                       
defgh  
"                                                                                                                                                                                                                                                                                                  

-- #33
select emp_name from employee where extract(year from dob) + 58 = '&year';

"
Enter value for year: 2058

old   1: select emp_name from employee where extract(year from dob) + 58 = '&year'
new   1: select emp_name from employee where extract(year from dob) + 58 = '2058'

EMP_NAME                                                                                                                                                                                                                                                                                                    
--------------------                                                                                                                                                                                                                                                                                        
bcdef   
"