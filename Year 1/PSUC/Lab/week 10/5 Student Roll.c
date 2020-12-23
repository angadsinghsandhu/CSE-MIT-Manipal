#include<stdio.h>
struct employee
{
    char name[20];
    int empno;
    int age;
    int doj;
    int salary;
    int yor;
};
int main()
{
    struct employee e[10];
    int i,n,t,k;
    printf("enter no of employee");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("enter name of employee ");
        scanf("%s",&e[i].name);
        printf("enter employee no ");
        scanf("%d",&e[i].empno);
        printf("enter date of joining(year) ");
        scanf("%d",&e[i].doj);
        printf("enter salary of employee ");
        scanf("%d",&e[i].salary);
        printf("enter age of employee ");
        scanf("%d",&e[i].age);
        t=55-e[i].age;
        for (k=0;k<t;k++)
            e[i].salary=e[i].salary+.2*e[i].salary;
        e[i].yor=2019+t;
        printf("\n");
    }
    printf("name \t salary \t year of retirement \n");
    for(i=0;i<n;i++)

        printf("%s \t %d \t\t %d \n",e[i].name,e[i].salary,e[i].yor);
}
