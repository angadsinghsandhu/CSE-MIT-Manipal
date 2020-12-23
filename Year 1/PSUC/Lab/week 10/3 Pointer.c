#include<stdio.h>
void main()
{
    char *ptr,str[80];
    int ctr=0;
    printf("\nEnter the string: ");
    gets(str);
    ptr=&str;
    while(*ptr!='\0')
    {
        ctr++;
        ptr++;
    }
    printf("\nThe length of the string is: %d",ctr);
}
