#include<stdio.h>
int gcd(int x, int y)
 {
    if (x == 0)
        return (y);
    if (y==0)
        return (x);
   return gcd(y, x % y);
  }
main()
{
    int x,y;
    printf("Enter two numbers to find gcd");
    scanf("%d%d",&x,&y);
    printf("The gcd is %d",gcd(x,y));
}
