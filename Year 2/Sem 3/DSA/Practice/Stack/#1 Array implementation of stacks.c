/******************************************************************************

                    #1 : Array implementation of stacks

*******************************************************************************/

#include <stdio.h>

// defining global variables
#define MAX_SIZE 100
int A[MAX_SIZE];
int top = -1;

// pushing elements into the stack and incrementing
void push(int x){
    
    // handling overflow
    if (top == MAX_SIZE-1){
        printf("Error : Stack Overflow");
        return;
    }
    
    // incrementing top and assigning new value
    A[++top] = x;
    return;
}

// pushing elements out of the stack and decrementing
void pop(){
    
    // handling underflow
    if (top == -1){
        printf("Error : Stack Underflow");
        return;
    }
    
    // incrementing top and assigning new value
    --top;
    return;
    
}

// getting value of element at the top
int getTop(){
    return A[top];
}

// printitng Stack
void printStack(){
    
    // instatiating variables
    int i;
    
    // error condition
    if(top == -1){
        printf("The Stack is empty");
        return;
    }
    
    printf("Stack : [  ");
    // looping through and printitng
    for(i=0;i<=top;i++){
        printf("%d  ", A[i]);
    }
    printf("]\n");
    return;
    
}

// driver function
int main()
{
    printf("Stack Code\n\n");
    
    push(2); printStack();
    push(5); printStack();
    push(10); printStack();
    pop();  printStack();
    push(12); printStack();

    return 0;
}
