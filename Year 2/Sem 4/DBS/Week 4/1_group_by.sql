-- 1. 
Find the number of students in each course
SELECT dept_name,count(DISTINCT ID) FROM student GROUP BY dept_name;
 
-- 2. 
Find those departments where the average number of students are greater than 10
SELECT dept_name,count(DISTINCT ID) FROM (student NATURAL JOIN TAKES) GROUP BY dept_name HAVING COUNT(DISTINCT ID) >= 2;
 
-- 3. 
Find the total number of courses in each department
SELECT dept_name,COUNT(distinct course_id) FROM course GROUP BY dept_name;
 
-- 4. 
Find the names and average salaries of all departments whose average salary is greater than 42000.
SELECT dept_name,AVG(salary) FROM instructor GROUP BY dept_name HAVING AVG(salary) > 42000;
 
-- 5. 
Find the enrolment of each section that was offered in Spring 2009.
SELECT sec_id,COUNT(DISTINCT ID) FROM (TAKES NATURAL JOIN section) WHERE semester='Spring' AND year=2009 GROUP BY sec_id;
 