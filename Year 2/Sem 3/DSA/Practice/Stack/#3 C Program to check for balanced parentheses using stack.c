/******************************************************************************

        #3 : C Program to check for balanced parentheses using stack.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*   == Please import Functions from : "#2 Linked List implementation of stacks.c"  ==   */

// Function to check whether two characters are opening
// and closing of same type.
int ArePair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return 1;
    else if (opening == '{' && closing == '}')
        return 1;
    else if (opening == '[' && closing == ']')
        return 1;
    return 0;
}

int AreParanthesesBalanced(string exp)
{
    int i;

    // looping through String
    for (i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (empty() || !ArePair(top(), exp[i]))
                return false;
            else
                pop();
        }
    }
    return empty() ? 1 : 0;
}

// driver function
int main()
{
    string expression;
    printf("Enter an expression:  "); // input expression from STDIN/Console
    gets(expression);
    if (AreParanthesesBalanced(expression))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
}