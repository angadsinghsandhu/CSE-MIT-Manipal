-- Set Membership (in / not in)

-- #5 
SELECT s1.course_id FROM section s1 WHERE semester = 'Fall' AND year = 2009 AND s1.course_id IN (SELECT s2.course_id FROM section s2 WHERE semester = 'Spring' and year = 2010 ); 

-- #6 
SELECT COUNT(UNIQUE takes.id) FROM takes WHERE takes.course_id IN (SELECT teaches.course_id FROM teaches WHERE teaches.ID = '10101'); 

-- #7 
SELECT s1.course_id FROM section s1 WHERE semester = 'Fall' AND year = 2009 AND s1.course_id NOT IN (SELECT s2.course_id FROM section s2 WHERE semester = 'Spring' and year = 2010 ); 

-- #8 
SELECT UNIQUE student.name FROM student WHERE student.name IN (SELECT instructor.name FROM instructor); 
