-- 1
CREATE TABLE salary_raise(
  Instructor_ID NUMBER(5),
  Raise_date DATE,
  Raise_amt NUMERIC(10,2)
);

DECLARE
  CURSOR raise_cursor IS
    SELECT * FROM Instructor WHERE dept_name = 'Biology' FOR UPDATE;
  raise_amt NUMERIC(8, 2);

BEGIN
    FOR i IN raise_cursor
    LOOP
		raise_amt := i.salary * 1.05;
		UPDATE Instructor
        SET salary = salary * 1.05;
		INSERT INTO salary_raise VALUES (i.ID, CURRENT_DATE, raise_amt);
	END LOOP;
END;
/

SELECT * FROM salary_raise;

-- 2
DECLARE
	CURSOR curs is select * from student order by tot_cred;
	stud_name student.name%type;
	stud_id student.id%type;
	stud_dept_name student.dept_name%type;
	stud_cred student.tot_cred%type;
BEGIN
	OPEN curs;
	LOOP
   	EXIT WHEN (curs%ROWCOUNT > 9) OR (curs%NOTFOUND);
   	fetch curs into stud_id, stud_name, stud_dept_name, stud_cred;
   	dbms_output.put_line(stud_id || ' ' || stud_name || ' ' || stud_dept_name
   	|| ' ' || stud_cred);
   	END LOOP;
   	CLOSE curs;
END;
/

-- 3
declare
    cursor disp_curs is with stud as (select * from (student natural join takes natural join section)),ins as (select * from (instructor natural join teaches natural join section))
                select course_id,title,ins.dept_name,credits,ins.name,ins.building,ins.room_number,ins.time_slot_id,count(*) as no_of_students from stud inner join  ins using(course_id,sec_id,semester,year) natural join course
                group by (course_id,title,ins.dept_name,credits,ins.name,ins.building,ins.room_number,ins.time_slot_id);
begin
    for temp in disp_curs
        loop
            dbms_output.put_line('Course ID : '|| temp.course_id);
            dbms_output.put_line('Title : '|| temp.title);
            dbms_output.put_line('Department : '|| temp.dept_name);
            dbms_output.put_line('Credits : '|| temp.credits);
            dbms_output.put_line('Instructor Name : '|| temp.name);
            dbms_output.put_line('Building : '|| temp.building);
            dbms_output.put_line('Room Number : '|| temp.room_number);
            dbms_output.put_line('Time Slot ID : '|| temp.time_slot_id);
            dbms_output.put_line('Total Students : '|| temp.no_of_students);
        end loop;
end;
/

-- 4
declare
cursor curs is select * from Student natural join takes where course_id='CS-101' ;

begin
	for stud in curs
    loop
    if stud.tot_cred < 30 then
      delete from takes where id=stud.id and course_id='CS-101';
    end if;
    end loop;
end;
/


-- 5
declare
cursor curs is select * from studenttable for update;
begin
    for stud in curs
    loop
    if stud.gpa between 0 and 4 then
        update student1 set LetterGrade='F' where current of curs;
    elsif stud.gpa between 4 and 5 then
        update student1 set LetterGrade='E' where current of curs;
    elsif stud.gpa between 5 and 6 then
        update student1 set LetterGrade='D' where current of curs;
    elsif stud.gpa between 6 and 7 then
        update student1 set LetterGrade='C' where current of curs;
    elsif stud.gpa between 7 and 8 then
        update student1 set LetterGrade='B' where current of curs;
    elsif stud.gpa between 8 and 9 then
        update student1 set LetterGrade='A' where current of curs;
    else
        update student1 set LetterGrade='A+' where current of curs;
    end if;
    end loop;
end;
/

-- 6
declare
cursor curs(cid teaches.course_id%TYPE) is select * from instructor natural join teaches where course_id=cid;

begin
for temp in curs('CS-101')
loop
    dbms_output.put_line('Instructor ID:'||temp.id);
    dbms_output.put_line('Instructor Name:'||temp.name);
    dbms_output.put_line('---------------------------');
end loop;
end;
/

-- 7
declare
    cursor curs_1(a_id advisor.i_id%type,c_id takes.course_id%type) is
    select * from ((student s natural join takes t) inner join advisor a
    on (id=a.s_id)) where course_id = c_id and a_id=i_id;
    cursor curs_2 is select * from (instructor natural join teaches);
begin
    for ins_info in curs_2
        loop
            for info in curs_1(ins_info.id,ins_info.course_id)
                loop
                    dbms_output.put_line(info.name);
                end loop;
        end loop;
end;
/

-- 8
declare
assigned_money department.budget%TYPE;
budget department.budget%TYPE;
begin
    Savepoint no_raise;
    update instructor set salary = 1.2*salary where dept_name='Biology';
    select sum(salary) into assigned_money from instructor where dept_name='Biology';
    select budget into budget from department where dept_name='Biology';
    if(assigned_money > budget) then
        Rollback to Savepoint no_raise;
    end if;
    commit;
end;
/
