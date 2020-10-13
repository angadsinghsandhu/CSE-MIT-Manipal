/******************************************************************************

                #4 : Program to delete NODE in Linked list

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
    
    // creating tail pointer to n-1 Node
    struct Node* temp2 = head;
    
    // looping to get to the last pos
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    
    temp2->next = temp1;
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

// function to delete element in list
void Delete(int n){
    int i; 
    
    struct Node* temp1 = head; // getting temp var
    
    // special condotion for
    if(n==1){
        head = temp1->next; // pointing head to second node
        free(temp1);
        return;
    }
    
    // looping through list
    for(i=0; i<n-2; i++){
        temp1 = temp1->next;
    }
    
    struct Node* temp2 = temp1->next; // getting another temp var
    
    // reconfiguring the links
    temp1->next = temp2->next;
    
    // freeing up space occupied by deleted node
    free(temp2);
    return;
}

void main ()
{
    int n; // variable of the delete position
    
    head = NULL; // defining empty list
    
    Insert(2, 1); // first element [2]
    Insert(3, 2); // second element [2, 3]
    Insert(6, 3); // first element [4, 2, 3]
    Insert(5, 4); // second element [4, 5, 2, 3]
    
    printf("the list is : \n");
    Print(); // printing entire list
    
    printf("\nenter position of element to be deleted : ");
    scanf("%d", &n);
    
    Delete(n);
    
    printf("\nthe new linked list is : ");
    Print();
    
    return;
}
