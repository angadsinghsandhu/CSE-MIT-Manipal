/*
Write a multithreaded program that calculates the summation 
of non-negative integers in a separate thread and passes the 
result to the main thread.
*/


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* summation(void *param)
{	
	// initializing array
	int* arr = (int*)param;
	long sum = 0;
	int n = arr[0];
	
	// summing and returning
	for(int i = 1;i <= n;i++) {
		if(arr[i] > 0)
			sum += arr[i];
	}
	 
	return (void*)sum;
}
 
int main(int argc, char const *argv[])
{
	// initializing and getting the numbers
	int n;
	printf("Enter the no. of numbers : \n");
	scanf("%d",&n);
	
	// dynamically initializing our array
	int* arr = (int*)malloc((n+1)*sizeof(int));
	arr[0] = n;
	
	// entering values
	printf("Enter the numbers : \n");
	for(int i= 1;i <= n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int answer = 0;
	
	// creating thread
	pthread_t thread;

	// running routine and passing array
	pthread_create(&thread,0,&summation,(void*)arr);
	
	// joining child threads to the main thread
	pthread_join(thread,(void**)&answer);
	
	// printing answer
	printf("Summation of non-negative numbers = %d\n",answer);
	 
	return 0;
}