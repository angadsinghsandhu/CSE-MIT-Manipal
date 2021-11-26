/*
Write a multithreaded program that performs the sum of 
even numbers and odd numbers in an input array. Create 
a separate thread to perform the sum of even numbers 
and odd numbers. The parent thread has to wait until 
both the threads are done.
*/


#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>


void *even(void *brr)
{
    // initializing array and values
    int *arr = (int *)brr;
    int size = arr[0];
    long sum = 0;

    // finding even sum
    for (int i = 1; i <= size; i++)
        if (arr[i] % 2 == 0)
            sum += arr[i];
    return (void *)sum;
}
void *odd(void *brr)
{
    // initializing array and values
    int *arr = (int *)brr;
    int size = arr[0];
    long sum = 0;

    // finding odd sum
    for (int i = 1; i <= size; i++)
        if (arr[i] % 2 != 0)
            sum += arr[i];
    return (void *)sum;
}


int main()
{
    // initializing values
    int n, evenSum, oddSum;
    
    // getting array information
    printf("Enter The Number of Elements of the Array: \n");
    scanf("%d", &n);
    int arr[n + 1];
    arr[0] = n;
    printf("Enter The Elements in the Array:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    // creating thread
    pthread_t t1, t2;

    // running routine and passing array
    pthread_create(&t1, 0, &even, (void *)arr);
    pthread_create(&t2, 0, &odd, (void *)arr);

    // joining child threads to the main thread
    pthread_join(t1, (void *)&evenSum);
    pthread_join(t2, (void *)&oddSum);

    // showing outputs
    printf("The Sum of Even Numbers of the Array is: %d\n", (int)evenSum);
    printf("The Sum of Odd Numbers of the Array is: %d\n", (int)oddSum);
}
