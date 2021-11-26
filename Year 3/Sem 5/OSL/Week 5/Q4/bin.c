/*
Write a C program reading and writing a binary file in C.
*/

#include<stdio.h>
#include<stdlib.h>
 
int main()
{
 
    FILE* fptr;
    int num=0;
    fptr=fopen("demo.bin","wb+");
 
    printf("Enter some numbers : \n");
 
    for(int i=0;i<4;i++)
    {
 
        scanf("%d",&num);
        fwrite(&num,sizeof(int),1,fptr);
    }
 
    printf("Writing done!\n");
    fclose(fptr);
 
    fptr=fopen("demo.bin","rb");
 
    for(int i=0;i<4;i++)
    {
 
        fread(&num,sizeof(int),1,fptr);
        printf("%d\n",num);
    }
 
}