//stack_utils.h
//stack_utils.h
// #include <stdio.h>
// #include <stdlib.h>

#define MAX (100)
#define TRUE (1)
#define FALSE (0)
#define SUCCESS (1)
#define FAILED (0)

typedef struct stack
{
    char item[MAX];
    int top;
} stack;

int isEmpty(stack *);
int isFull(stack *);
int push(stack *, char);
char pop(stack *);
void display(stack *);
stack *new_stack();

int isEmpty(stack *s)
{
    if (s->top == -1)
        return TRUE;
    return FALSE;
}

int isFull(stack *s)
{
    if (s->top == MAX - 1)
        return TRUE;
    return FALSE;
}

int push(stack *s, char elem)
{
    if (isFull(s))
        return FAILED;
    s->item[++s->top] = elem;
    return SUCCESS;
}

char pop(stack *s)
{
    if (isEmpty(s))
        return FAILED;
    return (s->item[s->top--]);
}

void display(stack *s)
{
    if (isEmpty(s))
        return;
    int i;
    for (i = 0; i <= s->top; i++)
        printf("%c ", s->item[i]);
    printf("\n");
}

stack *new_stack()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    return s;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_utils.h"

int eval(char *);

int eval(char *exp)
{
    int i;
    stack *s = new_stack();

    for (i = strlen(exp) - 1; i > -1; i--)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%')
        {
            int op1, op2;
            op1 = pop(s) - '0';
            op2 = pop(s) - '0';

            int res;
            if (exp[i] == '+')
                res = op1 + op2;
            else if (exp[i] == '-')
                res = op1 - op2;
            else if (exp[i] == '*')
                res = op1 * op2;
            else if (exp[i] == '/')
                res = op1 / op2;
            else if (exp[i] == '%')
                res = op1 % op2;
            push(s, res + '0');
        }
    }
    int res = pop(s) + '0';
    free(s);
    return (res);
}

int main(int argc, char const *argv[])
{
    char *exp = (char *)calloc(20, sizeof(char));
    printf("This method WILL only work on operands between 0-9\n");
    printf("Enter an expression (in prefix): ");
    scanf("%s", exp);
    printf("Evaluated: %d\n", eval(exp));
    return 0;
}
