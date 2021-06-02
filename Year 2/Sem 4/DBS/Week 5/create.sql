-- Database Creation
drop table prereq;
drop table time_slot;
drop table advisor;
drop table takes;
drop table student;
drop table teaches;
drop table section;
drop table instructor;
drop table course;
drop table department;
drop table classroom;

-- EMPLOYEE; foreign key referencing department is added later
create table employee (
 fname char(10),
 minit char,
 lname char(10),
 ssn numeric not null primary key,
 bdate date,
address char(30),
 sex char,
 salary numeric,
 superssn numeric references employee (ssn),
 dno numeric);

-- DEPARTMENT
create table department (
 dname char(20),
 dnumber numeric not null primary key,
 mgrssn numeric references employee (ssn),
 mgrstartdate date);

-- Foreign key from EMPLOYEE to DEPARTMENT
alter table employee add foreign key (dno) references department (dnumber);

-- DEPT_LOCATIONS
create table dept_locations (
 dnumber numeric not null references department (dnumber),
 dlocation char(15) not null);
alter table dept_locations add primary key (dnumber, dlocation);

-- PROJECT
create table project (
 pname char(20),
 pnumber numeric not null primary key,
 plocation char(15),
 dnum numeric);
alter table project add foreign key (dnum, plocation) references
 dept_locations (dnumber, dlocation);

-- WORKS_ON
create table works_on (
 essn numeric not null references employee (ssn),
 pno numeric not null references project (pnumber),
 hours numeric(18,1));
alter table works_on add primary key (essn, pno);

-- DEPENDENT
create table dependent (
 essn numeric not null references employee (ssn),
 dependent_name char(10) not null,
 sex char,
 bdate date,
 relationship char(10));
alter table dependent add primary key (essn, dependent_name);

-- add all the employees, initially without superssn and dno info.
insert into employee values ('John', 'B', 'Smith', 123456789, '09-JAN-1955',
'731 Fondren, Houston, TX', 'M', 30000, NULL, NULL);
insert into employee values ('Franklin', 'T', 'Wong', 333445555, '08-DEC-1945',
'638 Voss, Houston, TX', 'M', 40000, NULL, NULL);
insert into employee values ('Alicia', 'J', 'Zelaya', 999887777, '19-JUL-1958',
'3321 Castle, Spring, TX', 'F', 25000, NULL, NULL);
insert into employee values ('Jennifer', 'S', 'Wallace', 987654321, '20-JUN-1931',
'291 Berry, Bellaire, TX', 'F', 43000, NULL, NULL);
insert into employee values ('Ramesh', 'D', 'Narayan', 666884444, '15-SEP-1952',
'975 Fire Oak, Humble, TX', 'M', 38000, NULL, NULL);
insert into employee values ('Joyce', 'A', 'English', 453453453, '31-JUL-1962',
'5631 Rice, Houston, TX', 'F', 25000, NULL, NULL);
insert into employee values ('Ahmad', 'V', 'Jabbar', 987987987, '29-MAR-1959',
'980 Dallas, Houston, TX', 'M', 25000, NULL, NULL);
insert into employee values ('James', 'E', 'Borg', 888665555, '10-NOV-1927',
'450 Stone, Houston, TX', 'M', 55000, NULL, NULL);

-- add all departments
insert into department values ('Research', 5, 333445555, '22-MAY-1978');
insert into department values ('Administration', 4, 987654321, '01-JAN-1985');
insert into department values ('Headquarters', 1, 888665555, '19-JUN-1971');

-- update employees to include superssn, dno info.
update employee set superssn = 333445555 where ssn = 123456789;
update employee set dno = 5 where ssn = 123456789;
update employee set superssn = 333445555 where ssn = 666884444;
update employee set dno = 5 where ssn = 666884444;
update employee set superssn = 333445555 where ssn = 453453453;
update employee set dno = 5 where ssn = 453453453;
update employee set superssn = 888665555 where ssn = 333445555;
update employee set dno = 5 where ssn = 333445555;
update employee set superssn = 987654321 where ssn = 999887777;
update employee set dno = 4 where ssn = 999887777;
update employee set superssn = 888665555 where ssn = 987654321;
update employee set dno = 4 where ssn = 987654321;
update employee set superssn = 987654321 where ssn = 987987987;
update employee set dno = 4 where ssn = 987987987;
update employee set dno = 1 where ssn = 888665555;

-- add all dept_locations
insert into dept_locations values (1, 'Houston');
insert into dept_locations values (4, 'Stafford');
insert into dept_locations values (5, 'Houston');
insert into dept_locations values (5, 'Bellaire');
insert into dept_locations values (5, 'Sugarland');

-- add all projects
insert into project values ('ProductX', 1, 'Bellaire', 5);
insert into project values ('ProductY', 2, 'Sugarland', 5);
insert into project values ('ProductZ', 3, 'Houston', 5);
insert into project values ('Computerization', 10, 'Stafford', 4);
insert into project values ('Reorganization', 20, 'Houston', 1);
insert into project values ('Newbenefits', 30, 'Stafford', 4);

-- add all works_on tuples
insert into works_on values (123456789, 1, 32.5);
insert into works_on values (123456789, 2, 7.5);
insert into works_on values (666884444, 3, 40);
insert into works_on values (453453453, 1, 20);
insert into works_on values (453453453, 2, 20);
insert into works_on values (333445555, 2, 10);
insert into works_on values (333445555, 3, 10);
insert into works_on values (333445555, 10, 10);
insert into works_on values (333445555, 20, 10);
insert into works_on values (999887777, 30, 30);
insert into works_on values (999887777, 10, 10);
insert into works_on values (987987987, 10, 35);
insert into works_on values (987987987, 30, 5);
insert into works_on values (987654321, 30, 20);
insert into works_on values (987654321, 20, 15);

-- add all dependents
insert into dependent values (333445555, 'Alice', 'F', '05-APR-1976',
'DAUGHTER');
insert into dependent values (333445555, 'Theodore', 'M', '25-OCT-1973',
'SON');
insert into dependent values (333445555, 'Joy', 'F', '03-MAY-1948',
'SPOUSE');
insert into dependent values (987654321, 'Abner', 'M', '29-FEB-1932',
'SPOUSE');
insert into dependent values (123456789, 'Michael', 'M', '01-JAN-1978',
'SON');
insert into dependent values (123456789, 'Alice', 'F', '31-DEC-1978',
'DAUGHTER');
insert into dependent values (123456789, 'Elizabeth', 'F', '05-MAY-1951',
'SPOUSE');
insert into dependent values (123456789, 'John', 'M', '15-JUN-1971',
'SON');

alter table department rename column dnumber to dno;
alter table dept_locations rename column dnumber to dno;
alter table project rename column pnumber to pno;
alter table project rename column dnum to dno;