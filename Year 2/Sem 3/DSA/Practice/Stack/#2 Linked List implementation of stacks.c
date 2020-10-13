/******************************************************************************

                #2 : Linked List implementation of stacks

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// defining node structure
struct Node {
    int data;
    struct Node* next;
};

// defining head (as top)
struct Node* top = NULL;

// pushing elements into the stack and incrementing
void push(int x){
    
    // defining temporary node
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node*));
    
    // assigning value to Node
    temp->data = x;
    temp->next = top;
    top = temp;
    
    return;
}

// pushing elements out of the stack and decrementing
void pop(){
    
    // defining temporary node
    struct Node* temp;
    
    // exit condition if stack is empty
    if (top==NULL) return;
    
    // popping
    temp = top; // pointing temp to the node that is to be pooped
    top = temp->next; // creating new link to the 2nd node 
    free(temp); // freeing memory
    
    return;
    
}

// getting value of element at the top
int getTop(){
    return top->data;
}

// returning wheather or not the stack is empty
int isEmpty(){
    // condition
    if(top==NULL){
        return 1;
    } else {
        return 0;
    }
}

// printitng Stack
void printStackRec(struct Node* nodePtr){ 
    
    // defining exit condition
    if(nodePtr==NULL) return;
    
    // recursive call
    printStackRec(nodePtr->next);
    
    // printitng value
    printf("%d  ", nodePtr->data);
    
    return;
    
}

void printStackRev(){
    // error condition
    if(top == NULL){
        printf("The Stack is empty");
        return;
    }
    
    printf("Stack : [  ");
    
    // calling recuesive function
    printStackRec(top);
    
    printf("]\n");
}

// driver function
int main()
{
    printf("Stack Code\n\n");
    
    push(2); printStackRev();
    push(5); printStackRev();
    push(10); printStackRev();
    pop();  printStackRev();
    push(12); printStackRev();

    return 0;
}
