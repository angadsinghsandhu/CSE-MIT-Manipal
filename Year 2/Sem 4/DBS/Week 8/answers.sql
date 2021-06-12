-- LAB #8

-- 1
-- Based on the University Database Schema in Lab 2, write a procedure which takes
-- the dept_name as input parameter and lists all the instructors associated with 
-- the department as well as list all the courses offered by the department. Also,
-- write an anonymous block with the procedure call.
CREATE OR REPLACE PROCEDURE p1 (dept IN instructor.dept_name%TYPE) IS
CURSOR s1 IS SELECT title FROM course WHERE dept_name = dept;
CURSOR s2 IS SELECT name FROM instructor WHERE dept_name = dept;
BEGIN
 DBMS_OUTPUT.PUT_LINE('Instructors in the ' || dept || ' department are as follows');
 FOR s IN s2
 LOOP
 DBMS_OUTPUT.PUT_LINE(s.name);
 END LOOP;
 DBMS_OUTPUT.PUT_LINE('Courses offered in the ' || dept || ' department are as follows');
 FOR s IN s1
 LOOP
 DBMS_OUTPUT.PUT_LINE(s.title);
 END LOOP;
END;
DECLARE
 dept instructor.dept_name%TYPE;
 ins_name instructor.name%TYPE;
BEGIN
 dept := '&deptname';
 p1(dept);
END;


-- 2 
-- Based on the University Database Schema in Lab 2, write a Pl/Sql block of code
--  that lists the most popular course (highest number of students take it) for 
-- each of the departments. It should make use of a procedure course_popular which 
-- finds the most popular course in the given department.
CREATE OR REPLACE PROCEDURE course_popular IS
CURSOR c1 IS WITH temp(cid, c_count) AS(
SELECT t.course_id, COUNT(DISTINCT ID) AS stu_count
FROM takes t, course
WHERE t.course_id = course.course_id
GROUP BY t.course_id
)
SELECT dept_name, MAX(c_count) AS max_count
FROM temp t, course c
WHERE t.cid = c.course_id
GROUP BY dept_name;
BEGIN
 FOR c IN c1
 LOOP
 DBMS_OUTPUT.PUT_LINE('Department ' || c.dept_name || ' and number of students ' ||
c.max_count);
 END LOOP;
END;
DECLARE
BEGIN
 COURSE_POPULAR;
END;



FUNCTIONS
-- 3
-- Write a function to return the Square of a given number and call it from an 
-- anonymous block.
CREATE OR REPLACE FUNCTION square(num INTEGER)
RETURN INTEGER
AS
 sq INTEGER;
BEGIN
 sq := num * num;
RETURN sq;
END;
DECLARE
 num INTEGER;
BEGIN
 num := '&number';
 DBMS_OUTPUT.PUT_LINE('Square of ' || num || ' is ' || square(num));
END;


-- 4
-- Based on the University Database Schema in Lab 2, write a Pl/Sql block of 
-- code that lists the highest paid Instructor in each of the Department. It 
-- should make use of a function department_highest which returns the highest 
-- paid Instructor for the given branch. 
CREATE OR REPLACE FUNCTION department_highest
RETURN VARCHAR
AS
CURSOR c1 IS
WITH temp(max_sal, dept) AS
(SELECT MAX(salary) as max_sal, dept_name
FROM instructor
GROUP BY dept_name
)
SELECT name, max_sal, dept
FROM temp, instructor
WHERE salary = max_sal;
BEGIN
 FOR c IN c1
 LOOP
 DBMS_OUTPUT.PUT_LINE(c.name || ' from ' || c.dept || ' department has highest salary of
' || c.max_sal);
 END LOOP;
RETURN '';
END;
DECLARE
 dumm VARCHAR(10);
BEGIN
 dumm := department_highest;
END;




TRIGGERS
-- 1
-- Based on the University database Schema in Lab 2, write a row trigger that 
-- records along with the time any change made in the Takes (ID, course-id, sec-id,
-- semester, year, grade) table in log_change_Takes (Time_Of_Change, ID, courseid,
-- sec-id, semester, year, grade
CREATE TABLE log_change_takes(
 time_of_change TIMESTAMP(2),
 ID varchar(5),
 course_id varchar(8),
 sec_id varchar(8),
 semester varchar(6),
 year number(4, 0),
 grade varchar(2)
);
CREATE OR REPLACE TRIGGER log_takes
AFTER UPDATE ON takes
FOR EACH ROW
BEGIN
 INSERT INTO log_change_takes VALUES(CURRENT_TIMESTAMP, :OLD.ID, :OLD.course_id,
:OLD.sec_id, :OLD.semester, :OLD.year, :OLD.grade);
END;


-- 2 
-- Based on the University database schema in Lab: 2, write a row trigger to insert 
-- the existing values of the Instructor (ID, name, dept-name, salary) table into a new
-- table Old_ Data_Instructor (ID, name, dept-name, salary) when the salary table is updated. 
CREATE TABLE old_data_instructor(
 ID varchar(5),
 name varchar(20),
 dept_name varchar(20),
 salary numeric(8, 2), check (salary > 29000)
);
CREATE OR REPLACE TRIGGER sal_trigger
AFTER UPDATE ON instructor
FOR EACH ROW
BEGIN
 INSERT INTO old_data_instructor VALUES(:OLD.ID, :OLD.name, :OLD.dept_name,
:OLD.salary);
END;
