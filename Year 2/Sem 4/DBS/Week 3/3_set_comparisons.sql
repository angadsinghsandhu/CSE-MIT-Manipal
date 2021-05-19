-- Set Comparison (>=some/all)

-- #9 
SELECT i1.name FROM instructor i1 WHERE i1.salary > SOME(SELECT i2.salary FROM instructor i2 WHERE i2.dept_name = 'Biology'); 

-- #10 
SELECT i1.name FROM instructor i1 WHERE i1.salary > ALL(SELECT i2.salary FROM instructor i2 WHERE i2.dept_name = 'Biology' ); 

-- #11 
SELECT dept_name FROM(SELECT dept_name, avg(salary) avgsal FROM instructor GROUP BY dept_name) WHERE avgsal = (SELECT MAX(avgsal) FROM (SELECT dept_name, AVG(salary) avgsal FROM instructor GROUP BY dept_name)); 

-- #12 
SELECT department.dept_name FROM department WHERE department.budget < (SELECT avg(salary) avgsal FROM instructor); 
