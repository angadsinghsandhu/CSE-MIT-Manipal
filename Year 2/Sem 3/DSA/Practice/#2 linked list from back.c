#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data; // type of data that is stored in linked list
    struct NODE* next; // link to the next node
};

// variable to first and last node
struct NODE* head;

// insert function
void Insert(int x){
    // creating a NODE in storage and initializing fileds
    struct NODE* temp1 = (struct NODE*) malloc(sizeof(struct NODE));
    temp1 -> data = x;
    temp1 -> next = NULL;
    
    // for special case : (first Insert)
    if(head == NULL){
        temp1 -> next = head;
        head = temp1;
        return;
    }
    
    // creating tail pointer to n-1 Node
    struct NODE* temp2 = head;
    
    // looping to get to the end
    while(temp2 -> next != NULL){
        temp2 = temp2 -> next;
    }
    
    // assigning newly created node to nth position
    temp1 -> next = temp2 -> next;  // assigns null
    temp2 -> next = temp1;  // connects new node to the end
    
    return;
}

// printing linked list
void PrintList(){
    // setting temporary variable to head
    struct NODE* temp = head;
    printf("head: %d %p \n", (head->data), (head->next));
    
    // traversing the list
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int i,n,x;
    
    // initializing head
    head = NULL;
    
    // instantiationg head as empty list
    head = NULL;
    
    // getting length of list
    printf("Enter the length of list : ");
    scanf("%d", &n);
    printf("\nEnter array elements : \n");
    
    // running loop
    for(i=0; i<n; i++){
        scanf("%d", &x);
        Insert(x);
        
    }
    
    printf("\n");
    PrintList();
    
    
    return 0;
}
