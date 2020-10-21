/******************************************************************************

                #5 : Infix to postfix conversion in C 

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//
/*   == Please import Functions from : "#2 Linked List implementation of stacks.c"  ==   */
//

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
    int i;

    string postfix = ""; // Initialize postfix as empty string.

    // looping through the string
    for (i = 0; i < expression.length(); i++)
    {

        // Scanning each character from left.
        // If character is a delimitter, move on.
        if (expression[i] == ' ' || expression[i] == ',')
            continue;

        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if (IsOperator(expression[i]))
        {
            while (!empty() && top() != '(' && HasHigherPrecedence(top(), expression[i]))
            {
                postfix += top();
                pop();
            }
            push(expression[i]);
        }
        // Else if character is an operand
        else if (IsOperand(expression[i]))
        {
            postfix += expression[i];
        }

        else if (expression[i] == '(')
        {
            push(expression[i]);
        }

        else if (expression[i] == ')')
        {
            while (!empty() && top() != '(')
            {
                postfix += top();
                pop();
            }
            pop();
        }
    }

    while (!empty())
    {
        postfix += top();
        pop();
    }

    return postfix;
}

// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
    if (C >= '0' && C <= '9')
        return 1;
    if (C >= 'a' && C <= 'z')
        return 1;
    if (C >= 'A' && C <= 'Z')
        return 1;
    return 0;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
        return 1;

    return 0;
}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
    if (op == '$')
        return 1;
    return 0;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
    int weight = -1;
    switch (op)
    {
    case '+':
    case '-':
        weight = 1;
    case '*':
    case '/':
        weight = 2;
    case '$':
        weight = 3;
    }
    return weight;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if (op1Weight == op2Weight)
    {
        if (IsRightAssociative(op1))
            return 0;
        else
            return 1;
    }
    return op1Weight > op2Weight ? 1 : 0;
}

// driver function
int main()
{
    // defining variable
    string expression;

    // printing and scanning
    printf("Enter Postfix Expression \n");
    gets(expression);

    // getting result and outputting
    string postfix = InfixToPostfix(expression);
    printf("Output = %s\n", postfix);
}
