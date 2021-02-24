// #include <stdio.h>
// #include <stdlib.h>

#define MAX 30

typedef struct stack2{
    int data[MAX];
    int max2;
    int top2;
    int max1;
    int top1;
} stack2;

stack2* create_2stack(){
    stack2* s = (stack*) malloc(sizeof(stack));
    s -> max2 = MAX-1;
    s -> top2 = MAX/2-1;
    s -> max1 = MAX/2-1;
    s -> top1 = -1;
}

int isFull1(stack2* s){
    if(s->top1 == s->max1)
        return 1;
    else
        return 0;
}

int isFull2(stack2* s){
    if(s->top2 == s->max2)
        return 1;
    else
        return 0;
}

int isEmpty1(stack2* s){
    if(s->top1 == -1)
        return 1;
    else
        return 0;
}

int isEmpty2(stack2* s){
    if(s->top2 == s->max1)
        return 1;
    else
        return 0;
}

int push1(stack2* s, int ele){
    if(isFull1(s)==1){
        printf("OverFlow Occured");
        return 0;
    } else {
        s->data[++s->top1] = ele;
        return 1;
    }
    return 0;
}

int push2(stack2* s, int ele){
    if(isFull2(s)==1){
        printf("OverFlow Occured");
        return 0;
    } else {
        s->data[++s->top2] = ele;
        return 1;
    }
    return 0;
}

int pop1(stack* s){
    // check underflow
    if(isEmpty1(s)==1){
        printf("UnderFlow Occured");
        return -1;
    } else {
        int elem = s->data[s -> max1--];
        return elem;
    }
    return -1;
}

int pop2(stack* s){
    // check underflow
    if(isEmpty2(s)==1){
        printf("UnderFlow Occured");
        return -1;
    } else {
        int elem = s->data[s -> max2--];
        return elem;
    }
    return -1;
}

int display1(stack* s){
    int i=0;
    printf("Stack1 is : ");
    while (i != s ->top1+1)
        printf("%d ", s -> item[i++]);
    printf("\n\n");
    return 1;
}

int display1(stack* s){
    int i= s ->max1+1;
    printf("Stack1 is : ");
    while (i != s ->top2+1)
        printf("%d ", s -> item[i++]);
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
        printf("=== Enter Choice for Stack 1 ===\n");
        printf("(Option - 1) Push to Stack\n");
        printf("(Option - 2) Pop from Stack\n");
        printf("(Option - 3) Display Stack\n");
        printf("=== Enter Choice for Stack 2 ===\n");
        printf("(Option - 4) Push to Stack\n");
        printf("(Option - 5) Pop from Stack\n");
        printf("(Option - 6) Display Stack\n");
        printf("(Option - 7) Exit\n");
        printf("### Enter Option : ");
        scanf(" %d", &ch);

        // implementing options
        switch(ch){
            case 1:
                printf("\nEnter Integer to be Pushed : ");
                scanf(" %d", &x);
                out = push1(s, x);
                if(out==1)
                    printf("** Element Pushed **\n\n");
                else
                    printf("\nERROR : element not pushed into stack\n\n");
                break;
            case 2:
                elem = pop1(s);
                printf("The Pushed out element is : %d\n\n", x);
                break;
            case 3:
                out = display1(s);
                if(out==0)
                    printf("\nERROR : element not pushed into stack\n\n");
                break;

            case 4:
                printf("\nEnter Integer to be Pushed : ");
                scanf(" %d", &x);
                out = push2(s, x);
                if(out==1)
                    printf("** Element Pushed **\n\n");
                else
                    printf("\nERROR : element not pushed into stack\n\n");
                break;
            case 5:
                elem = pop2(s);
                printf("The Pushed out element is : %d\n\n", x);
                break;
            case 6:
                out = display2(s);
                if(out==0)
                    printf("\nERROR : element not pushed into stack\n\n");
                break;

            case 7:
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










