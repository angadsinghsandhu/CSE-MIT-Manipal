#include<stdio.h>
int main()
{
    int i,x,n=1;
    char a[40];
    printf("enter string\n");
    gets(a);
    for(i=0;i!='\0';i++)
        n++;
    for(i=0;i<=n/2;i++)
    {
        if(a[i]==a[n-i-1])
            x=1;
        else
            x=0;
    }
    if(x==1)
        printf("the string is a palindrome");
    if(x==0)
        printf("the string is not a palindrome");
    return 0;
}
