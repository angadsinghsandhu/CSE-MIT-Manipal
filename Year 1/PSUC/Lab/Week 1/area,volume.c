#include<stdio.h>
#include<math.h>
void main()
{
int surface,volume;
float radius;
printf("enter radius of sphere");
scanf("%f",&radius);
surface=4*3.1416*pow(radius,2);
volume=(4*3.1416*pow(radius,3))/3;
printf("surface area of sphere is%d\n",surface);
printf("volume of sphere is%d",volume);
}
