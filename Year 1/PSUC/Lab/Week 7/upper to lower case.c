#include<stdio.h>
int main()
{
    char a[40];
    int i,k;
    printf("enter string\n");
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]<=90 && a[i]>=65)
            a[i]=a[i]+32;
        else if(a[i]<=122 && a[i]>=97)
            a[i]=a[i]-32;
    }
    puts(a);
    return 0;
}
