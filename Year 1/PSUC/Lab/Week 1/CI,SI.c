#include<stdio.h>
#include<math.h>
void main()
{
float p,r;
int n,SI,CI;
printf("put p and n and r respectively");
scanf("%f%d%f",&p,&n,&r);
SI=p*r*n/100;
CI=p*pow((1+r/100),n)-p;
printf("simple intrest of p,n,r is %d\n",SI);
printf("compound intrest of p,n,r is %d",CI);
}
