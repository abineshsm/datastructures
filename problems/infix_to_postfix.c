#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../stack_using_array.c"

bool isOperand(char var)
{
    if (var >= 'a' && var <= 'z')
        return true;
    if (var >= 'A' && var <= 'Z')
        return true;
    if (var >= '0' && var <= '9')
        return true;
    return false;
}

bool isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
        return true;
    return false;
}

bool isOpenParantheses(char param)
{
    if (param == '(')
        return true;
    return false;
}

bool isCloseParantheses(char param)
{
    if (param == ')')
        return true;
    return false;
}

int getOperatorWeight(char op)
{
    int weight = -1;
    switch (op)
    {
    case '+':
    case '-':
        weight = 1;
        break;
    case '*':
    case '/':
        weight = 2;
    }
    return weight;
}

bool isHigherPrecedence(char op1, char op2)
{
    int op1weight = getOperatorWeight(op1);
    int op2weight = getOperatorWeight(op2);
    if (op1weight >= op2weight)
        return true;
    return false;
}

void convertToPostfix(char *exp, int len)
{
    char result[50];
    int pos = 0;
    for (int i = 0; i < len; i++)
    {
        if (isOperand(exp[i]))
        {
            result[pos++] = exp[i];
        }
        else if (isOperator(exp[i]))
        {
            while (!isEmpty() && isOperator(top()) && isHigherPrecedence(top(), exp[i]))
            {
                result[pos++] = pop();
            }
            push(exp[i]);
        }
        else if (isOpenParantheses(exp[i]))
            push(exp[i]);
        else if (isCloseParantheses(exp[i]))
        {
            while (!isEmpty() && !isOpenParantheses(top()))
            {
                result[pos++] = pop();
            }
            pop();
        }
    }
    while (!isEmpty() && isOperator(top()))
    {
        result[pos++] = pop();
    }

    printf("%s", result);
    // return result;
}

int main()
{
    char exp[50];
    printf("Enter the infix expression.\n");
    gets(exp);
    convertToPostfix(exp, strlen(exp));
}