-- 17. 
savepoint s1;
delete FROM instructor WHERE dept_name='Finance';
rollback to s1;
 
-- 18. 
savepoint s2;
delete FROM course WHERE dept_name='Comp. Sci.';
rollback to s2;

-- 19. 
update student set dept_name="Physics" where dept_name="Comp. Sci.";

-- 20. 
update instructor set salary=case
where salary <= 100000 then
salary * 1.05
else 
salary *1.03
end;

-- 21. 
insert into student select id, name, dept_name, from instructor;

-- 22. 
delete from instructor where salary < (select avg(salary) from instructor)