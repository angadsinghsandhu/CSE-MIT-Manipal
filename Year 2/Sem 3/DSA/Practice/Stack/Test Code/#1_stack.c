#include <stdio.h>
#include <stdlib.h>
// #include <stack_utils.h>

// predefining stack utils
// int pop(int);
// int push(int);
// int isOverflow(int);
// int isUnderflow(int);

#define MAX 5

typedef struct stack{
    int item[MAX];
    int max;
    int top;
} stack;


stack* new_stack(){
    stack* s = (stack *) malloc(sizeof(stack));
    s -> max = MAX;
    s -> top = -1;
}

int isEmpty(stack* s){
    if(s -> top == -1)
        return 1; 
    else
        return 0;
}

int isFull(stack* s){
    if(s -> top == s -> max-1)
        return 1; 
    else
        return 0;
}

int push(stack* s, char ele){
    // check for overflow
    if(isFull(s) == 1){
        printf("OverFlow Occured");
        return 0;
    } else {
        s -> item[++s -> top] = ele;
        return 1;
    }
    return 0;
}

char pop(stack* s){
    // check for underflow
    if(isEmpty(s) == 1){
        printf("UnderFlow Occured");
        return 0;
    } else {
        char popped = s -> item[0];
        int i=0;
        while (i != s ->top+1){
            s -> item[i] = s -> item[i+1];
            i++;
        }
        s ->top--;
        return popped;
    }
    return 0;
}

int display(stack* s){
    int i=0;
    printf("Stack is : ");
    while (i != s ->top+1)
        printf("%c ", s -> item[i++]);
    printf("\n\n");
    return 1;
}


// main function
int main(){
    stack* s = new_stack();
    int ch, x, out, flag=0;
    char elem;

    // implemnting menu
    for(;;){
        out = 0;
        printf("=== Enter Choice ===\n");
        printf("(Option - 1) Push to Stack\n");
        printf("(Option - 2) Pop from Stack\n");
        printf("(Option - 3) Display Stack\n");
        printf("(Option - 4) Exit\n");
        printf("### Enter Option : ");
        scanf(" %d", &ch);

        // implementing options
        switch(ch){
            case 1:
                printf("\nEnter Character to be Pushed : ");
                scanf(" %c", &elem);
                out = push(s, elem);
                if(out==1)
                    printf("** Element Pushed **\n\n");
                else
                    printf("\nERROR : element not pushed into stack\n\n");
                break;
            case 2:
                elem = pop(s);
                printf("The Pushed out element is : %c\n\n", elem);
                break;
            case 3:
                out = display(s);
                if(out==0)
                    printf("\nERROR : element not pushed into stack\n\n");
                break;
            case 4:
                flag=1;
                break;

            default:
                printf("### Wrong Option ###\n\n");
                break;
        }
        if(flag==1){
            printf("\nExiting...");
            break;
        }
    }


    return 0;
}


