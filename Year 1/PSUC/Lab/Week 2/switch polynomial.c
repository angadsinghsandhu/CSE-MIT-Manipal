#include<stdio.h>
void main()
{
int d;
float disc,a,b,c,re,im;
printf("enter the value of coefficients");
scanf("%f%f%f",&a,&b,&c);
disc=(b*b)-(4*a*c);
if(disc<0)d=1;
if(disc==0)d=2;
if(disc>0)d=3;
switch(d)
{
case 1:
printf("imaginary roots");
re=-b/(2*a);
im=sqrt(-disc)/(2.0*a);
printf("root1=%f+i%f and root2=%f-i%f",re,im,re,im);
break;

case 2:
printf("real and equal roots");
re=-b/(2.0*a);
printf("%.2f is the root",re);
break;

case 3:
    printf("real roots");
    re=-b/(2.0*a);
    im=pow(fabs(disc),0.5)/2*a;
    re=re+im;
    im=re-(2*im);
    printf("%f and %f",re,im);
    break;
}
}
