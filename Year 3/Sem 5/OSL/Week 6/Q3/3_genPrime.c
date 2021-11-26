/*
Write a multithreaded program for generating prime numbers from 
a given starting number to the given ending number.
*/

#include<stdio.h>
#include <stdlib.h>
#include<pthread.h>
 
#define N 30
#define MAX_THREADS 4
 
int prime_arr[N]={0};
 
void *printprime(void *ptr)
{
    // initializing values
    int  j,flag;
    int i=(int)(long long int)ptr;
    
    // finding prime numbers
    while(i<N)
    {
        printf("Thread id[%d] checking [%d]\n",pthread_self(),i);
        flag=0;
        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
 
        if(flag==0 && (i>1))
        {
            prime_arr[i]=1;
        }
        i+=MAX_THREADS;
  }
}
 
int main()
{
    // initializing values and threads
    pthread_t tid[MAX_THREADS]={0};
    long count=0;

    // enterning min and max values
    printf("Enter starting and ending\n");
    int st,en;
    scanf("%d %d",&st,&en);
    
    for(count=0;count<MAX_THREADS;count++)
    {
        printf("\r\n CREATING THREADS %d",count);
        // running routine and passing array
        pthread_create(&tid[count],NULL,printprime,(void*)count);
    }
    printf("\n");

    for(count=0;count<MAX_THREADS;count++)
    {
        // joining child threads to the main thread
        pthread_join(tid[count],NULL);
    }
 
    int c=0;
    
    // printing solution
    for(count=st;count<en;count++)
        if(prime_arr[count]==1)
            printf("%ld ",count);
    printf("\n");
 
    return 0;
}