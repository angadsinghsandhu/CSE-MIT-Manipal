-- 1.Retrieve the birth date and address of the employee(s) whose name is 
-- ‘John B. Smith’. Retrieve the name and address of all employees who 
-- work for the ‘Research’ department.
Select bdate, address from employee where fname='John' and minit='B' and lname='Smith';
Select fname, minit, lname, address from employee natural join department where dname='Research';


-- 2.For every project located in ‘Stanford’, list the project number, the controlling department number, and the
-- department manager’s last name, address, and birth date.
select pno, Project.dno, lname, address, bdate from Project, Employee, Department where plocation='Stafford' and
Project.dno=Department.dno and Department.mgrssn=Employee.ssn;


-- 3.Find all distinct salaries of employees.
Select distinct(salary) from employee;


-- 4.For each employee, retrieve the employee’s first and last name and the first and last name of his or her
-- immediate supervisor.
Select T.lname as supervisor_lname, T.fname as supervisor_fname, S.lname as employee_lname, S.fname as
employee_fname from employee T,employee S where T.ssn=S.superssn;


-- 5.Make a list of all project numbers for projects that involve an employee whose last name is ‘Smith’, either as a
-- worker or as a manager of the department that controls the project.
select pno from Project where dno in (select dno from Department where mgrssn in (select ssn from Employee
where lname='Smith')) or pno in (select pno from works_on where essn in (select ssn from Employee where
lname='Smith'));


-- 6.Retrieve all employees who reside is in Houston, Texas.
Select * from employee where address like '%Houston, TX%';


-- 7.Show the resulting salaries if every employee working on the ‘ProductX’ project is given a 10 percent raise.
Update employee set salary=1.1*salary where employee.ssn in (Select essn from works_on natural join project where pname='ProductX');
select * from employee where ssn in (Select essn from works_on natural join project where pname='ProductX');


-- 8.Retrieve all employees in department 5 whose salary is between 30,000 and 40,000.
Select fname, lname from department,employee where employee.dno=5 and salary between 30000 and 40000 and
employee.dno=department.dno;


-- 9.Retrieve a list of employees and the projects they are working on, ordered by department and, within each
-- department, ordered alphabetically by last name, then first name.
Select fname, lname, employee.dno, pname, project.pno from employee, project, works_on where
works_on.pno=project.pno and works_on.essn=employee.ssn order by employee.dno, fname, lname;


-- 10.Retrieve the names of all employees who do not have supervisors.
Select fname, lname from employee where superssn is NULL;


-- 11.Retrieve the name of each employee who has a dependent with the same first name and is the same sex as the
-- employee.
select fname, lname from Employee, Dependent where Employee.ssn = Dependent.essn and Employee.sex =
Dependent.sex and Employee.fname = Dependent.dependent_name;


-- 12.Retrieve the names of employees who have no dependents.
select fname, lname from employee where ssn not in (select essn from dependent);


-- 13.List the names of managers who have at least one dependent.
select fname, lname from Employee where ssn in (select essn from Dependent) and ssn in (select mgrssn from
Department);


-- 14.Retrieve the Social Security numbers of all employees who work on project numbers 1, 2, or 3.
select ssn from Employee where ssn in (select essn from works_on where pno between 1 and 3);


-- 15.Find the sum of the salaries of all employees, the maximum salary, the minimum salary, and the average
-- salary.
Select max(salary), sum(salary), min(salary), avg(salary) from employee;


-- 16.Find the sum of the salaries of all employees of the ‘Research’ department, as well as the maximum salary, the
-- minimum salary, and the average salary in this department.
Select sum(salary), max(salary), min(salary), avg(salary) from employee natural join department where
dname='Research';


-- 17.For each project, retrieve the project number, the project name, and the number of employees who work on
-- that project.
select Project.pno, pname, count (*) from Project, Works_on where Project.pno = Works_on.pno group by
project.pno, pname order by project.pno;


-- 18.For each project on which more than two employees work, retrieve the project number, the project name, and
-- the number of employees who work on the project.
select Project.pno, pname, count (*) from Project, Works_on where Project.pno = Works_on.pno group by
project.pno, pname having count(*)>2 order by project.pno;


-- 19.For each department that has more than five employees, retrieve the department number and the number of
-- its employees who are making more than 40,000.
select dname, count(*) from Department, employee where Department.dno = employee.dno and salary >40000 and
department.dno in (select dno from employee group by dno having count(*) > 5) group by dname;