/******************************************************************************

                #2 : Linked List implementation of Queue

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// defining node structure
struct Node
{
	int data;
	struct Node *next;
};

// Two glboal variables to store address of front and rear nodes.
struct Node *front = NULL;
struct Node *rear = NULL;

//Creates a new Node and returns pointer to it.
struct Node *GetNewNode(int x)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

// Function To Enqueue an integer
void Enqueue(int x)
{
	printf("Enqueuing Value : %d \n", x);

	// creating new node
	struct Node *temp = GetNewNode(x);

	// handling null condition
	if (front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}

	// assigning new value to rear
	rear->next = temp;
	rear = temp;
}

// To Dequeue an integer.
void Dequeue()
{
	printf("Dequeuing Value\n");

	// defining temporary variable
	struct Node *temp = front;

	// handle null condition
	if (front == NULL)
	{
		printf("Queue is Empty\n");
		return;
	}

	// handle initial condition
	if (front == rear)
	{
		front = rear = NULL;
	}
	// assigning front as next node
	else
	{
		front = front->next;
	}

	// freeing up memory
	free(temp);
}

int Front()
{
	// handling null condition
	if (front == NULL)
	{
		printf("Queue is empty\n");
		return -1;
	}

	// returning front value
	return front->data;
}

void Print()
{
	// defining temporary variable
	struct Node *temp = front;

	// looping and printing
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue
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