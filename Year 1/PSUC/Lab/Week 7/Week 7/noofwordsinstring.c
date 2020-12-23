#include<stdio.h>
void main()
{
char str[100];
int cnt=1,i=0;
printf("Enter the string\n");
gets(str);
while(str[i]!='\0')
{
if(str[i]==' ' && str[i+1]!=' ')
cnt++;
i++;
}
printf("number of words = %d",cnt);
}
