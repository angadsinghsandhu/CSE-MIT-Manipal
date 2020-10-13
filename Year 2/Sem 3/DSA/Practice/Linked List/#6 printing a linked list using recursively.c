/******************************************************************************

                #6 : printing a linked list using recursively

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// defining node structure
struct NODE {
    int data;
    struct NODE* next;
};

// initalizing global variables
struct NODE* head;

// node inserting function
void Insert(int x){
    
    //creating and initializing temporary variable for holding node
    struct NODE* temp1 = (struct NODE*) malloc(sizeof(struct NODE));
    temp1 -> data = x;
    temp1 -> next = NULL;
    
    // special case : [first node insert]
    if(head == NULL){
        temp1 -> next = head;
        head = temp1;
        return;
    }
    
    //creating and initializing temporary variable for iterating list
    struct NODE* temp2 = head;
    
    // iterating to the last position of the list
    while(temp2 -> next != NULL){
        temp2 = temp2->next;
    }
    
    // assgning new node to the end
    temp1 -> next = temp2 -> next; // assigns null
    temp2 -> next = temp1; // connects new node to the end
    
    return;
}

// printing the entire list
void PrintList(){
    //creating and initializing temporary variable for iterating list
    struct NODE* temp = head;
    
    // iterating and printing to the last position of the list
    while(temp != NULL){
        printf("%d  ", temp -> data);
        temp = temp->next;
    }
    
    return;
}

// printing using recusion
void PrintListRec(struct NODE* nodePtr){
    
    // exit condition
    if(nodePtr == NULL){
        return;
    } else {
        
        // printing node value
        printf("%d ", nodePtr->data);
        
        // recursive call
        PrintListRec(nodePtr->next);
    }
    
}

// reverse linked list using recusion
void PrintListRecRev(struct NODE* nodePtr){
    // exit condition
    if(nodePtr == NULL){
        return;
    }
        
        // recursive call
        PrintListRecRev(nodePtr->next);
        
        // printing node value
        printf("%d ", nodePtr->data);

}

// main function
int main()
{
    // initialzing variables
    int i,x,n;
    
    // initializing head as null
    head = NULL;
    
    // taking length of list as input
    printf("enter number of elements : ");
    scanf("%d",&n);
    
    // taking data of the linked list
    printf("\nEnter data : \n");
    for (i=0; i<n; i++) {
        scanf("%d", &x);
        Insert(x);
    }
    
    // printing created list
    printf("\nThe list is : ");
    PrintList();
    printf("\n");
    
    // printing created list recursively
    printf("\nThe list is (recursively) : ");
    PrintListRec(head);
    printf("\n");
    
    // reverse printing created list recursively
    printf("\nThe reversed list is (recursively) : ");
    PrintListRecRev(head);
    printf("\n");
    
    return 0;
}
