-- Set Operatiions

-- #1 
SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 
UNION ALL SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010;

-- #2
SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 
INTERSECT SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010;                    

-- #3
SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 
MINUS SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010; 

-- #4 
SELECT course.course_id FROM course WHERE course.course_id NOT IN (SELECT takes.course_id FROM takes); 
