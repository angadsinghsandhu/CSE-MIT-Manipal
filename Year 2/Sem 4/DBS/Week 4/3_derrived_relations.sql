-- 8.
Find the maximum total salary across the departments.
SELECT MAX(total_salary) FROM (SELECT SUM(salary) AS total_salary FROM instructor GROUP BY dept_name);
 
-- 9. 
Find the average instructors’ salaries of those departments where the average salary is greater than 42000.
SELECT AVG(T) FROM (SELECT AVG(salary) AS T FROM instructor GROUP BY dept_name HAVING AVG(salary) > 42000);
 
-- 10. 
Find the sections that had the maximum enrolment in Spring 2010.
SELECT MAX(total_student) FROM (SELECT COUNT(ID) AS total_student FROM TAKES GROUP BY sec_id, semester, year HAVING semester='Spring' and year=2010);
 
-- 11. 
Find the names of all instructors who teach all students that belong to ‘CSE’ department.
SELECT DISTINCT name FROM teaches, instructor WHERE teaches.id = instructor.id AND course_id IN (SELECT DISTINCT course_id FROM takes,student WHERE dept_name='Comp. Sci.' AND student.id = takes.id);
 
-- 12. 
Find the average salary of those department where the average salary is greater than 50000 and total number of instructors in the department are more than 5
//considered 2
SELECT dept_name, AVG(salary) FROM instructor GROUP BY dept_name HAVING AVG(salary)>50000 AND COUNT(ID)>=2;
