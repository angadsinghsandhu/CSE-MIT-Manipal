-- #14
select id from instructor where id not in (select distinct id from teaches);

"
ID                                                                                                                                                                                                                                                                                                          
-----                                                                                                                                                                                                                                                                                                       
33456                                                                                                                                                                                                                                                                                                       
58583                                                                                                                                                                                                                                                                                                       
76543   
"                                                                                                                                                                                                                                                                                                    

-- #15
select name, title, takes.year from student, section, course, takes where room_number=3128 and course.course_id = section.course_id and course.course_id = takes.course_id and takes.id = student.id and takes.year = section.year and takes.sec_id = section.sec_id and section.semester = takes.semester;

"
NAME                 TITLE                                                    YEAR                                                                                                                                                                                                                          
-------------------- -------------------------------------------------- ----------                                                                                                                                                                                                                          
Zhang                Database System Concepts                                 2009                                                                                                                                                                                                                          
Shankar              Game Design                                              2009                                                                                                                                                                                                                          
Shankar              Database System Concepts                                 2009                                                                                                                                                                                                                          
Williams             Game Design                                              2009                                                                                                                                                                                                                          
Brown                Image Processing                                         2010                                                                                                                                                                                                                          
Aoi                  Intro. to Digital Systems                                2009                                                                                                                                                                                                                          

6 rows selected.
"