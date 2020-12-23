#include<stdio.h>
void main()
{
char string[30];
int i,n=0;
printf("Enter the string\n");
gets(string);
for(i=0;string[i]!='\0';i++)
{
if(string[i]>=97 && string[i]<=122)
string[i]=string[i]-32;
else if(string[i]>=65 && string[i]<=90)
string[i]=string[i]+32;
}
puts(string);
}
