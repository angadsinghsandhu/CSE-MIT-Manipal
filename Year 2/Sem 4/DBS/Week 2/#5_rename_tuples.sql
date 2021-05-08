-- #16
Select name,course_id,title as c_name from (student natural join takes) join course using(course_id) where year=2015;

"
NAME                 COURSE_ID                      C_NAME                                                                                                                                                                                                                                                  
-------------------- ------------------------------ --------------------------------------------------                                                                                                                                                                                                      
Tanaka               BIO-301                        Genetics                                                                                                                                                                                                                                                
Levy                 CS-101                         Intro. to Computer Science                                                                                                                                                                                                                              
Bourikas             CS-315                         Robotics                                                                                                                                                                                                                                                
Shankar              CS-315                         Robotics                                                                                                                                                                                                                                                
Brown                CS-319                         Image Processing                                                                                                                                                                                                                                        
Levy                 CS-319                         Image Processing                                                                                                                                                                                                                                        
Chavez               FIN-201                        Investment Banking                                                                                                                                                                                                                                      
Brandt               HIS-351                        World History                                                                                                                                                                                                                                           
Sanchez              MU-199                         Music Video Production                                                                                                                                                                                                                                  

9 rows selected.
"

-- #17
select distinct a.name, a.salary as inst_salary from instructor a, instructor b where a.salary > b.salary and b.dept_name='Comp. Sci.';

"
NAME                 INST_SALARY                                                                                                                                                                                                                                                                            
-------------------- -----------                                                                                                                                                                                                                                                                            
Crick                      72000                                                                                                                                                                                                                                                                            
Katz                       75000                                                                                                                                                                                                                                                                            
Gold                       87000                                                                                                                                                                                                                                                                            
Einstein                   95000                                                                                                                                                                                                                                                                            
Wu                         90000                                                                                                                                                                                                                                                                            
Brandt                     92000                                                                                                                                                                                                                                                                            
Singh                      80000                                                                                                                                                                                                                                                                            
Kim                        80000                                                                                                                                                                                                                                                                            

8 rows selected.
"
