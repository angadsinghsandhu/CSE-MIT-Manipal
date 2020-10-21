/******************************************************************************

                #4 : Evaluation Of postfix Expression in C 

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//
/*   == Please import Functions from : "#2 Linked List implementation of stacks.c"  ==   */
//

// Function to evaluate Postfix expression and return output
int EvaluatePostfix(string expression)
{
    int i;

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
            // Pop two operands.
            int operand2 = top();
            pop();
            int operand1 = top();
            pop();
            // Perform operation
            int result = PerformOperation(expression[i], operand1, operand2);
            //Push back result of operation on stack.
            push(result);
        }
        else if (IsNumericDigit(expression[i]))
        {
            // Extract the numeric operand from the string
            // Keep incrementing i as long as you are getting a numeric digit.
            int operand = 0;
            while (i < expression.length() && IsNumericDigit(expression[i]))
            {
                // For a number with more than one digits, as we are scanning from left to right.
                // Everytime , we get a digit towards right, we can multiply current total in operand by 10
                // and add the new digit.
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            // Finally, you will come out of while loop with i set to a non-numeric character or end of string
            // decrement i because it will be incremented in increment section of loop once again.
            // We do not want to skip the non-numeric character by incrementing i twice.
            i--;

            // Push operand on stack.
            push(operand);
        }
    }
    // If expression is in correct format, Stack will finally have one element. This will be the output.
    return top();
}

// Function to verify whether a character is numeric digit.
int IsNumericDigit(char C)
{
    if (C >= '0' && C <= '9')
        return 1;
    return 0;
}

// Function to verify whether a character is operator symbol or not.
int IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/')
        return 1;

    return 0;
}

// Function to perform an operation and return output.
int PerformOperation(char operation, int operand1, int operand2)
{
    if (operation == '+')
        return operand1 + operand2;
    else if (operation == '-')
        return operand1 - operand2;
    else if (operation == '*')
        return operand1 * operand2;
    else if (operation == '/')
        return operand1 / operand2;

    else
        printf("Unexpected Error \n");
    return -1;
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
    int result = EvaluatePostfix(expression);
    printf("Output = %d\n", result);
}