#include<stdio.h>
void main()
{
char str[30];
int i,n=0,flag=1;
printf("Enter the string\n");
gets(str);
for(i=0;str[i]!='\0';i++)
n++;
for(i=0;i<n/2;i++)
{
if(str[i]!=str[n-i-1])
{
flag=0;
break;
}
}
if(flag==1)
printf("It is a palindrome");
else
printf("It is not a palindrome");
}
