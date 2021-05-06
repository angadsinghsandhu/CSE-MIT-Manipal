-- #1: Create employee table
CREATE TABLE EMPLOYEE(
    emp_no number(10) NOT NULL, 
    emp_name varchar2(20) NOT NULL, 
    emp_address varchar2(20)
);

-- #2: Insert five employees information.
INSERT INTO EMPLOYEE VALUES (100, 'Person 1', 'BANGALORE');
INSERT INTO EMPLOYEE VALUES (200, 'Person 2', 'MANIPAL');
INSERT INTO EMPLOYEE VALUES (300, 'Person 3', 'DELHI');
INSERT INTO EMPLOYEE VALUES (400, 'Person 4', 'MANIPAL');
INSERT INTO EMPLOYEE VALUES (500, 'Person 5', 'MANGALORE');

-- #3: Display employee names.
SELECT emp_name FROM EMPLOYEE;

-- #4: Display employees from ‘MANIPAL’.
SELECT * FROM EMPLOYEE WHERE emp_address = 'MANIPAL';

-- #5: Add a column named salary to employee table.
ALTER TABLE EMPLOYEE ADD salary number(5);

-- #6: Assign the salary for all employees.
UPDATE EMPLOYEE SET salary = 6000 WHERE emp_no = 500;
UPDATE EMPLOYEE SET salary = 7000 WHERE emp_no = 400;
UPDATE EMPLOYEE SET salary = 8000 WHERE emp_no = 300;
UPDATE EMPLOYEE SET salary = 9000 WHERE emp_no = 200;
UPDATE EMPLOYEE SET salary = 10000 WHERE emp_no = 100;
-- Alternatively...
UPDATE EMPLOYEE SET salary = 10000;

-- Queston #7: View the structure of the table employee using describe.
DESCRIBE EMPLOYEE;

-- #8: Delete all the employees from ‘MANGALORE’
DELETE FROM EMPLOYEE WHERE emp_address='MANGALORE';

-- #9: Rename employee as employee1.
RENAME EMPLOYEE TO EMPLOYEE1;

-- #10: Drop the table employee1.
DROP TABLE EMPLOYEE1;