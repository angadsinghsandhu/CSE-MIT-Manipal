-- #9
select name, dept_name from student;

"
NAME                 DEPT_NAME                                                                                                                                                                                                                                                                              
-------------------- --------------------                                                                                                                                                                                                                                                                   
Zhang                Comp. Sci.                                                                                                                                                                                                                                                                             
Shankar              Comp. Sci.                                                                                                                                                                                                                                                                             
Brandt               History                                                                                                                                                                                                                                                                                
Chavez               Finance                                                                                                                                                                                                                                                                                
Peltier              Physics                                                                                                                                                                                                                                                                                
Levy                 Physics                                                                                                                                                                                                                                                                                
Williams             Comp. Sci.                                                                                                                                                                                                                                                                             
Sanchez              Music                                                                                                                                                                                                                                                                                  
Snow                 Physics                                                                                                                                                                                                                                                                                
Brown                Comp. Sci.                                                                                                                                                                                                                                                                             
Aoi                  Elec. Eng.                                                                                                                                                                                                                                                                             
Bourikas             Elec. Eng.                                                                                                                                                                                                                                                                             
Tanaka               Biology                                                                                                                                                                                                                                                                                

13 rows selected.
"

-- #10
select * from instructor where dept_name='Comp. Sci.';

"
ID    NAME                 DEPT_NAME                SALARY                                                                                                                                                                                                                                                  
----- -------------------- -------------------- ----------                                                                                                                                                                                                                                                  
10101 Srinivasan           Comp. Sci.                65000                                                                                                                                                                                                                                                  
45565 Katz                 Comp. Sci.                75000                                                                                                                                                                                                                                                  
83821 Brandt               Comp. Sci.                92000   
"                                                                                                                                                                                                                                               

-- #11
select title from course where dept_name='Comp. Sci.' and credits=3;

"
TITLE                                                                                                                                                                                                                                                                                                       
--------------------------------------------------                                                                                                                                                                                                                                                          
Robotics                                                                                                                                                                                                                                                                                                    
Image Processing                                                                                                                                                                                                                                                                                            
Database System Concepts   
"                                                                                                                                                                                                                                                                                 

-- #12
select title, course_id from course natural join takes where ID=12345;

"
TITLE                                              COURSE_ID                                                                                                                                                                                                                                                
-------------------------------------------------- ------------------------------                                                                                                                                                                                                                           
Intro. to Computer Science                         CS-101                                                                                                                                                                                                                                                   
Game Design                                        CS-190                                                                                                                                                                                                                                                   
Robotics                                           CS-315                                                                                                                                                                                                                                                   
Database System Concepts                           CS-347                                                                                                                                                                                                                                                   
"

-- #13
select * from instructor where salary between 40000 and 90000;

"
ID    NAME                 DEPT_NAME                SALARY                                                                                                                                                                                                                                                  
----- -------------------- -------------------- ----------                                                                                                                                                                                                                                                  
10101 Srinivasan           Comp. Sci.                65000                                                                                                                                                                                                                                                  
12121 Wu                   Finance                   90000                                                                                                                                                                                                                                                  
15151 Mozart               Music                     40000                                                                                                                                                                                                                                                  
32343 El Said              History                   60000                                                                                                                                                                                                                                                  
33456 Gold                 Physics                   87000                                                                                                                                                                                                                                                  
45565 Katz                 Comp. Sci.                75000                                                                                                                                                                                                                                                  
58583 Califieri            History                   62000                                                                                                                                                                                                                                                  
76543 Singh                Finance                   80000                                                                                                                                                                                                                                                  
76766 Crick                Biology                   72000                                                                                                                                                                                                                                                  
98345 Kim                  Elec. Eng.                80000                                                                                                                                                                                                                                                  

10 rows selected.
"