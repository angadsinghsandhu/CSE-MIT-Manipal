-- Test for Empty Relations (exists/ not exists)

-- #13 
SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 AND EXISTS(SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010); 

-- #14 
SELECT DISTINCT S.ID, S.name FROM student S WHERE NOT EXISTS((SELECT course_id FROM course WHERE dept_name = 'Biology') 
EXCEPT(SELECT T.course_id FROM takes T WHERE S.ID = T.ID));


-- Test for Absence of Duplicate Tuples

-- #15
SELECT course_id from (SELECT course_id, count (*) count FROM section WHERE section.year=2009 group by course_id) WHERE count=1;

-- #16
SELECT id FROM (select id,count(*) count FROM takes WHERE takes.course_id like 'CS%' group by id) WHERE count>=2;