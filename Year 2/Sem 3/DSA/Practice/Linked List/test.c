/******************************************************************************

                        #8 : circular linked list

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// defining Node Structure
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head; // global variable - pointer to head node.
struct Node *tail; // global variable - pointer to tail node.

//Creates a new Node and returns pointer to it.
struct Node *GetNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(int x)
{
    // create a new node in memory
    struct Node *newNode = GetNewNode(x);

    // special case : [first node insert]
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    // assigning the new node
    tail->next = newNode;
    newNode->next = head;
    head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x)
{
    // create a new node in memory
    struct Node *newNode = GetNewNode(x);

    // special case : [first node insert]
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    // assigning new node
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

//Prints all the elements in linked list in forward traversal order
void Print()
{
    struct Node *temp = head;
    printf("Forward: ");

    // special case : [first node Print]
    if (head == tail)
    {
        printf("%d ", temp->data);
    }
    else
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

//Prints all elements in linked list in reverse traversal order.
void ReversePrint(struct Node *nodePtr)
{
    // exit condition
    if (nodePtr == NULL)
    {
        return;
    }

    // recursive call
    ReversePrint(nodePtr->next);

    // printing node value
    printf("%d ", nodePtr->data);
}

// reverse the links of the LL
void reverse(struct Node *list_pointer)
{
    // create a new node in memory
    struct Node *temp = list_pointer;
    struct Node *nextPtr = list_pointer;

    // special case : [first node reverse]
    if (head == tail)
    {
        return;
    }
    else
    {
        do
        {
            nextPtr = temp->next->next;
            temp->next->next = temp;
            temp->next = null;
            temp = nextPtr;

        } while (temp != head);
    }
}

int main()
{

    /*Driver code to test the implementation*/
    head = NULL; // empty list. set head as NULL.

    // Calling an Insert and printing list both in forward as well as reverse direction.
    InsertAtHead(2);
    Print();

    InsertAtHead(4);
    Print();

    InsertAtHead(6);
    Print();

    InsertAtHead(8);
    Print();

    printf("Backward Linked: ");
    reverse(head);
    Print();
}