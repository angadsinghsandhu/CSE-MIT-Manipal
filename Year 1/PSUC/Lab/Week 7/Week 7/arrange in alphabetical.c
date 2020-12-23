#include<stdio.h>
#include<string.h>
int main()
{
    char string[100][100],temp[30];
    int no,i,j;
    printf("Enter no. of strings\n");
    scanf("%d",&no);
    fflush(stdin);
    printf("Enter the strings\n");
    for(i=0;i<no;i++)
        gets(string[i]);
    for(i=0;i<no-1;i++)
    for(j=i+1;j<no;j++)
    {
        if (strcmp(string[i],string[j])>0)
        {
            strcpy(temp,string[i]);
            strcpy(string[i],string[j]);
            strcpy(string[j],temp);
        }
    }
    printf("The sorted array is:\n");
    for(i=0;i<no;i++)
    puts(string[i]);
}




