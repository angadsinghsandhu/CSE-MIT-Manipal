#include<stdio.h>
int main()
{
int nu1,nu2,nu3;
printf("enter 3 numbers");
scanf("%d%d%d",&nu1,&nu2,&nu3);
if(nu1>nu3&&nu1>nu2)
{
printf("%d is largest number",nu1);
}
if(nu2>nu3&&nu2>nu1)
{
printf("%d is largest number",nu2);
}
else
{
printf("%d is the largest number",nu3);
}
return 0;
}
