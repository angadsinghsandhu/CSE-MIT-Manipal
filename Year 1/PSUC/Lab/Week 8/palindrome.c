#include<stdio.h>
void palin()
{
    int i,x=0,n;
    char a[10];
    gets(a);
    n=count(a);
    for(i=0;i<n/2;i++)
        if(a[i]!=a[n-i-1])
        {
            x = 1;
            break;
        }
    if(x==1)
        printf("the string is not a palindrome");
    else
        printf("the string is a palindrome");
}
int count(char a[])
{
        int i,coun=0;
        for(i=0;a[i]!='\0';i++)
            coun++;
        return coun;
}
/*char scanstr(char a[])
    {
        int i;
        for(i=0;a[i]!='\0';i++)
        {
            scanf("%c",&a[i]);
        }
        return a[];
    }*/
int main()
    {
        printf("enter string\n");
        palin();
        return 0;
    }
