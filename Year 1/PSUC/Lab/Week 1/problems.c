#include<stdio.h>
#include<math.h>
int main()
{
int a=30.0,b=10.0,c=5.0,d=15.0;
int prob1,prob2,prob3,prob4;
prob1=(a+b)*c/d;
prob2=((a+b)*c)/d;
prob3=a+(b*c)/d;
prob4=(a+b)*(c/d);
printf("sol1 is %d\n",prob1);
printf("sol2 is %d\n",prob2);
printf("sol3 is %d\n",prob3);
printf("sol4 is %d\n",prob4);
return 0;
}
