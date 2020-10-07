#include <stdio.h>

struct NODE{
    int data; // type of data that is stored in linked list
    struct NODE* link; // link to the next node
};

// variable to first node
struct NODE* head;

// insert function
void Insert(int x){
    // creating a NODE
    struct NODE* temp = (struct NODE*) malloc(sizeof(struct NODE));
    temp -> data = x;
    temp -> link = head;
    
    // inserting next to head
    head = temp;
}

// printing linked list
void PrintList(){
    // setting temporary variable to head
    struct NODE* temp = head;
    
    // traversing the list
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    int i,n,x;
    
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
    
    PrintList();
    return 0;
}
