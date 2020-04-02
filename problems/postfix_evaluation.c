#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../stack_using_linkedlist.c"

bool isOperand(char digit)
{
    if (digit > '0' && digit < '9')
        return true;
    return false;
}

bool isOperator(char operator)
{
    if (operator== '+' || operator== '-' || operator== '*' || operator== '/')
        return true;
    return false;
}

int performOperation(char operator, int operand1, int operand2)
{
    if (operator== '+')
        return operand1 + operand2;
    else if (operator== '-')
        return operand1 - operand2;
    else if (operator== '*')
        return operand1 * operand2;
    else if (operator== '/')
        return operand1 / operand2;
}

int evaluate(char *exp, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (exp[i] == ' ')
            continue;
        else if (isOperand(exp[i]))
        {
            int operand = 0;
            while (i < len && isOperand(exp[i]))
            {
                operand = 10 * operand + (exp[i] - '0');
                i++;
            }
            i--;
            push(operand);
        }
        else if (isOperator(exp[i]))
        {
            int operand1 = pop();
            int operand2 = pop();
            int result = performOperation(exp[i], operand2, operand1);
            push(result);
        }
    }
    return pop();
}

int main()
{
    printf("Enter the expression.\n"); // 10 2 5 * +
    char exp[50];
    gets(exp);
    int result = evaluate(exp, strlen(exp));
    printf("%d", result);
}