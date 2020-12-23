#include<stdio.h>
struct emp
{
    int empno;
    char name[20];
    int age;
    int doj;
    int salary;
}e;
int main()
{
    int i,s;
    printf("enter the details of the employee");
    scanf("%d%s%d%d%d",&e.empno,e.name,&e.age,&e.doj,&e.salary);
    s=e.salary;
    for (i=0;i<(55-e.age);i++)
        e.salary+=e.salary*0.2;
    printf("employee number:%d\n employee name:%s\nemployee age%d\ndate of joining(ddmmyyyy):%d\nsalary:%d\n",e.empno,e.name,e.age,e.doj,s);
    printf("his salary during retirement is %d",e.salary);
}
