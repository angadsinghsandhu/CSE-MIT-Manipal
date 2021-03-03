#include <stdio.h>
#include <stdlib.h>

#define MAX 20;

typedef struct stack
{
    char item[MAX];
    int max;
    int top;
} stack;

char[] * convPre(char[] str)
{
    int i, j = 0;
    int len = strlen(str);
    char prefArr[MAX];
    stack *s = new_stack();

    for (i = len - 1; i >= 0; i--)
    {
        if ('a' <= str[i] || str[i] = > 'z' || 'A' <= str[i] || str[i] = > 'Z')
        {
        }
        else if (str[i] == '+')
        {
        }
        else if (str[i] == '-')
        {
        }
        else if (str[i] == '/')
        {
        }
        else if (str[i] == '*')
        {
        }
        else if (str[i] == '^')
        {
        }
        else if (str[i] == '(')
        {
        }
        else if (str[i] == ')')
        {
            push(s, str[i]);
        }
        else
        {
            print("Unrecognized Symbol, ERROR...\n");
        }
    }
}

void main()
{
    char infix[MAX];

    printf("Enter Infix Expression : ");
    scanf("%s", infix);

    printf("Converted Prefix Expression : %s", *convPre(infix));
}























// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "stack_utils.h"

void Inf2Pref(char *, char *);
void Inf2Post(char *, char *);

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

// void Inf2Pref(char *src, char *dest)
// {
//     char *inf_rev = (char *)calloc(MAX, sizeof(char));
//     char *post_rev = (char *)calloc(MAX, sizeof(char));
//     int i;
//     int j = 0;
//     for (i = strlen(src) - 1; i > -1; i--)
//     {
//         if (src[i] == '(')
//             inf_rev[j] = ')';
//         else if (src[i] == ')')
//             inf_rev[j] = '(';
//         else
//             inf_rev[j] = src[i];
//         j++;
//     }
//     inf_rev[j] = '\0';
//     char *post = (char *)calloc(MAX, sizeof(char));
//     Inf2Post(inf_rev, post);
//     j = 0;
//     for (i = strlen(post) - 1; i > -1; i--)
//     {
//         post_rev[j] = post[i];
//         j++;
//     }
//     post_rev[j] = '\0';
//     strcpy(dest, post_rev);
// }

void Inf2Post(char *src, char *dest) {
    char *exp = (char *)calloc(MAX, sizeof(char));
    stack *s = new_stack();
    int i;
    int j = 0;

    for (i = 0; i < strlen(src); i++) {

        if (isOperand(src[i])) {
            exp[j] = src[i];
            j++;
        } else if (src[i] == '(') {
            push(s, src[i]);
        } else if (src[i] == ')') {
            while (isEmpty(s) == FALSE && s->item[s->top] != '(') {
                exp[j] = pop(s);
                j++;
            }
            pop(s);
        } else {
            while (isEmpty(s) == FALSE && precedence(src[i]) <= precedence(s->item[s->top])) {
                exp[j] = pop(s);
                j++;
            }

            push(s, src[i]);
        }
    }
    
    while (isEmpty(s) == FALSE) {
        exp[j] = pop(s);
        j++;
    }

    exp[j] == '\0';
     // printf("%s", exp);
    strcpy(dest, exp);
}

int main(int argc, char const *argv[])
{
    char *exp = (char *)calloc(MAX, sizeof(char));
    char *pref = (char *)calloc(MAX, sizeof(char));
    printf("This WILL only work on operands between A-Z\n");
    printf("Enter an expression (in infix): ");
    scanf("%s", exp);
    Inf2Pref(exp, pref);
    printf("The prefix expression is: %s\n", pref);
    return 0;
}
