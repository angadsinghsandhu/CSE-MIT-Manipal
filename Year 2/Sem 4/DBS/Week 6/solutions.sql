-- 0 (Creating Table to be used)
create table studentTable(
	roll number(2),
	gpa numeric(4,2));
insert into studentTable values(1,5.8);
insert into studentTable values(2,6.5);
insert into studentTable values(3,3.4);
insert into studentTable values(4,7.8);
insert into studentTable values(5,9.5);
insert into studentTable values(6,11);

alter table studentTable 
add  grade varchar2(2);

-- 1
declare 
gpa1 numeric(2,1);
begin
    select gpa into gpa1 from studentTable where roll=1; 
    dbms_output.put_line('GPA:'||gpa1);
end;
 
-- 2
declare
score numeric(2,1);
grade varchar(2);
begin
    select gpa into score from studentTable where roll=1; 
    if score<=4 then
        grade:='F';
    elsif score<=5 then
        grade:='E';
    elsif score<=6 then
        grade:='D';
    elsif score<=7 then
        grade:='C';
    elsif score<=8 then
        grade:='B';
    elsif score<=9 then
        grade:='A';
    else
        grade:='A+';
    end if;
    dbms_output.put_line('Grade is:'||grade);
end;

 
-- 3
declare  
issue date:='28-mar-2021';
return date:='15-apr-2021';
days number(5);
begin 
    days:=return-issue;
    if days<=7 then
        dbms_output.put_line('Fine:'||0);
    elsif days<=15 then
        dbms_output.put_line('Fine:'||(days-7));
    elsif days<=30 then
        dbms_output.put_line('Fine:'||(8+(days-15)*2));
    else
        dbms_output.put_line('Fine:'||(38+(days-30)*5));
    end if;
end;

 
-- 4
declare
score numeric(2,1);
grade varchar(2);
i integer:=1;
begin
loop
    select gpa into score from studentTable where roll=i;
    if score<=4 then
        grade:='F';
    elsif score<=5 then
        grade:='E';
    elsif score<=6 then
        grade:='D';
    elsif score<=7 then
        grade:='C';
    elsif score<=8 then
        grade:='B';
    elsif score<=9 then
        grade:='A';
    else
        grade:='A+';
    end if;
    dbms_output.put_line('Grade is:'||grade);
    i:=i+1;
    if i>5 then exit;
    end if;
end loop;
end;
 
-- 5
alter table studentTable 
add  lettergrade varchar2(2);
declare
score numeric(2,1);
grade varchar(2);
i integer:=1;
begin
while i<=5 loop
    select gpa into score from studentTable where roll=i;
    if score<=4 then
        grade:='F';
    elsif score<=5 then
        grade:='E';
    elsif score<=6 then
        grade:='D';
    elsif score<=7 then
        grade:='C';
    elsif score<=8 then
        grade:='B';
    elsif score<=9 then
        grade:='A';
    else
        grade:='A+';
    end if;
    update studentTable set lettergrade=grade where roll=i;
    i:=i+1;
end loop;
end;
/
Select * from studenttable;
 
 
-- 6
declare
temp studenttable.gpa%type:=0;
max_score studenttable.gpa%type:=0;
max_roll studenttable.roll%type;
begin
for i in 1..5 loop
select gpa into temp from studenttable where roll=i;
if temp>max_score then
    max_score:=temp;
    max_roll:=i;
end if;
end loop;
dbms_output.put_line('Student Roll Number='||max_roll||'and GPA='||max_score);
end;
/
select * from studenttable

 
-- 7
declare
score numeric(2,1);
grade varchar(2);
i integer:=1;
begin
<<start_here>>
    select gpa into score from studentTable where roll=i;
    if score<=4 then
        grade:='F';
    elsif score<=5 then
        grade:='E';
    elsif score<=6 then
        grade:='D';
    elsif score<=7 then
        grade:='C';
    elsif score<=8 then
        grade:='B';
    elsif score<=9 then
        grade:='A';
    else
        grade:='A+';
    end if;
    dbms_output.put_line('Grade is:'||grade);
    i:=i+1;
    if i<6 then goto start_here;
    end if;
end;
 
-- 8
declare
in_name varchar(20):='Srinivasan';
multiple_instructor exception;
no_instructor exception;
counts integer;
details instructor%rowtype;
begin
select count(*) into counts from instructor where name=in_name;
if counts<1 then raise no_instructor;
elsif counts>1 then raise multiple_instructor;
else
select * into details from instructor where name=in_name;
dbms_output.put_line(details.salary||details.name);
end if;
exception 
    when no_instructor then
    dbms_output.put_line('NO instructor');
    when multiple_instructor then
    dbms_output.put_line('multiple instructor');
end;
/
 
-- 9
declare
score numeric(4,1);
grade varchar(2);
i integer:=1;
incorrect_range exception;
begin
while i<7 loop
    select gpa into score from studentTable where roll=i;
    if score<0 or score>10 then
        raise incorrect_range;
    elsif score<=4 then
        grade:='F';
    elsif score<=5 then
        grade:='E';
    elsif score<=6 then
        grade:='D';
    elsif score<=7 then
        grade:='C';
    elsif score<=8 then
        grade:='B';
    elsif score<=9 then
        grade:='A';
    else
        grade:='A+';
    end if;
    update studentTable set lettergrade=grade where roll=i;
    i:=i+1;
end loop;
exception
    when incorrect_range then
    dbms_output.put_line('OUT OF RANGE');
end;
/
Select * from studenttable;
 
