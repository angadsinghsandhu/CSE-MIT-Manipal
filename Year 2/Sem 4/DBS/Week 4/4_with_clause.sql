-- 13.
Find all departments with the maximum budget.
WITH temp AS (SELECT max(budget) AS temp FROM department) SELECT * FROM department,temp WHERE temp = department.budget;
 
-- 14.
Find all departments where the total salary is greater than the average of the total salary at all departments
WITH temp AS (SELECT avg(sum(salary)) AS T FROM instructor group by dept_name) SELECT distinct dept_name FROM instructor,temp group by dept_name,T having sum(salary)>T;
 
-- 15.
Find the sections that had the maximum enrolment in Fall 2009
WITH temp AS (SELECT max(count(id)) AS T FROM takes WHERE semester='Fall' and year=2009 group by sec_id) SELECT sec_id FROM temp,takes WHERE semester='Fall' and year=2009 group by sec_id,temp.T having count(id) = temp.T;
 
-- 16.
Select the names of those departments where the total credits earned by all the students is greater than the total credits earned by all the students in the Finance Department
WITH temp AS (SELECT sum(tot_cred) AS T FROM student WHERE dept_name='Finance') SELECT dept_name FROM student,temp group by dept_name,temp.T having sum(tot_cred) > temp.T;
