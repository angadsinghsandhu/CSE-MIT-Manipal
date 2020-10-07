/******************************************************************************

            #3 : Prgram to insert NODE at position in Linked list

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// defining Node structure
struct Node
{
  int data;
  struct Node *next;
};

// creating global Head
struct Node* head;

// function for inserting a Node
void Insert(int data, int n){
    int i;
    
    // creating a Node storage
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    
    // initializing fields of Node
    temp1 -> data = data;
    temp1 -> next = NULL;
    
    // hadling special case of adding next to Head
    if(n==1){
        temp1 -> next = head;
        head = temp1;
        return;
    }
    printf("...\n");
    
    // creating tail pointer to n-1 Node
    struct Node* temp2 = head;
    
    // looping to get to the end
    for(i = 0; i<n-2; i++){
        temp2 = temp2 -> next;
    }
    
    // assigning newly created node to nth position
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
    
    return;
}

// printing funtion for linked list
void Print(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void main ()
{
    head = NULL; // defining empty list
    
    Insert(2, 1); // first element [2]
    Insert(3, 2); // second element [2, 3]
    Insert(6, 1); // first element [4, 2, 3]
    Insert(5, 2); // second element [4, 5, 2, 3]
    
    Print(); // printing entire list
    
    return;
}
