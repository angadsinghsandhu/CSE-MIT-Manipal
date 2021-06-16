-- Table Creation
-- Here we create our part table
create table part(
    PartNo integer primary key not null,
    PartName varchar(20),
    VehicleType char(2),
    UnitPrice numeric(8,2),
    SalesPrice numeric(8,2),
    check(VehicleType in ('V1','V2','V3','V4','V5')),
    check(UnitPrice > 0),
    check(SalesPrice > 0)
);

//

-- Here we create our service table
create table Service(
    ServiceNo integer,
    PartNo integer,
    ServiceDate Date,
    CustomerNo varchar(10),
    Qty number(4),
    primary key(ServiceNo,PartNo),
    foreign key(PartNo) references Part
);

//



-- Insertion
-- Inserting a value into our table
insert into part values (1,'P1', 'V1', '10','12');

//

-- Inserting Further values
insert into part values (2,'P2', 'V2', '100','110');
insert into part values (3,'P3', 'V1', '150','175');
insert into part values (4,'P4', 'V3', '200','250');
insert into part values (5,'P5', 'V2', '75','90');

insert into service values ( 1, 1, '01-Jan-17', 'C1','5');
insert into service values ( 1, 3, '01-Jan-17', 'C1','4');
insert into service values ( 2, 3, '05-Feb-18', 'C2','10');
insert into service values ( 3, 1, '15-May-18', 'C3','9');
insert into service values ( 4, 1, '03-Jun-19', 'C1','5');

//

//

-- A - 1
-- Listing Part Names
select partname
from part
where partno not in
(
   select partno
   from Service
);

//

-- A - 2
-- Listing Customer Numbers
with custcnt as 
(
    select customerno,count(*) as cnt 
    from service 
    group by customerno
) 
select customerno 
from custcnt 
where cnt >= all(select cnt from custcnt);



-- A - 3
-- Listing Customer Numbers
select distinct customerno from service s1 
where not exists 
(
    (select partno from part where vehicletype = 'V1') 
    minus 
    (select distinct partno from Service s2 where s1.customerno = s2.customerno)
);


-- B
declare 
	cursor c(partnumber part.partno %type) is
	select unitprice,
	salesprice,
	qty from part natural join service
	where partno = partnumber;
	
	cursor d is
	select * from service;
	
	i integer := 1;
	invalid_part_no exception;
	profit part.unitprice %type := 0;
	profittemp part.unitprice %type;

begin 
	for temp in c(& part) 
	loop profittemp := (temp.salesprice - temp.unitprice) * temp.qty;
		if c %notfound then 
			raise invalid_part_no;
		end if;
		profit := profit + profittemp;
	end loop;
	dbms_output.put_line('total profit: ' || profit);

exception
	when invalid_part_no then dbms_output.put_line('not present');
end;
/
