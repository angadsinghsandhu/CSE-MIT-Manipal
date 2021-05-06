-- #1: Selecting from Depositor
SELECT * FROM DEPOSITOR

-- #2: Selecting from Branch
SELECT BRANCH_NAME, ASSETS FROM BRANCH;

-- #3: Selecting from Account
SELECT *FROM ACCOUNT WHERE BRANCH_NAME= ‘BROOKLYN’;

-- #4: Selecting from Loan
SELECT *FROM LOAN WHERE AMOUNT > 1000;

-- #5: Selecting from Branch
UPDATE BRANCH SET ASSETS = 340000000 WHERE BRANCH_NAME = ‘Perryridge’;