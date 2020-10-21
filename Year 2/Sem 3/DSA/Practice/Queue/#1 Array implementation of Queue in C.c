/******************************************************************************

                #1 : Array implementation of Queue

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101 //maximum size of the array that will store Queue.

int front;       // global variable - front value.
int rear;        // global variable - rear value.
int A[MAX_SIZE]; // creating array of Queue with MAX_SIZE

// To check wheter Queue is empty or not
int IsEmpty()
{
    return (front == -1 && rear == -1);
}

// To check whether Queue is full or not
int IsFull()
{
    return (rear + 1) % MAX_SIZE == front ? 1 : 0;
}

// Inserts an element in queue at rear end
void Enqueue(int x)
{
    printf("Enqueuing Value : %d \n", x);

    // check to see if queue is full
    if (IsFull())
    {
        printf("Error: Queue is Full\n");
        return;
    }

    //  initializing variables if queue is empty
    if (IsEmpty())
    {
        front = rear = 0;
    }

    // adding integer to end of queue
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }
    A[rear] = x;
}

// Removes an element in Queue from front end.
void Dequeue()
{
    printf("Denqueuing\n");

    // To check wheter Queue is empty
    if (IsEmpty())
    {
        printf("Error: Queue is Empty\n");
        return;
    }

    //  reverting variables if queue has been emptied
    else if (front == rear)
    {
        rear = front = -1;
    }

    // removing integer from start of queue
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
}

// Returns element at front of queue.
int Front()
{
    // checking for null condition
    if (front == -1)
    {
        printf("Error: cannot return front from empty queue\n");
        return -1;
    }

    // returning front element
    return A[front];
}

// Printing the elements in queue from front to rear.
void Print()
{
    int i;

    // Finding number of elements in queue
    int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;

    // looping and printing out the queue
    printf("Queue       : ");
    for (i = 0; i < count; i++)
    {
        int index = (front + i) % MAX_SIZE; // Index of element while travesing circularly from front
        printf("%d ", A[index]);
    }
    printf("\n\n");
}

// driver function
int main()
{
    // instantiating global variables
    front = -1;
    rear = -1;

    // operations
    Enqueue(2);
    Print();

    Enqueue(4);
    Print();

    Enqueue(6);
    Print();

    Dequeue();
    Print();

    Enqueue(8);
    Print();
}