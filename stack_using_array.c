#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 101

char stack[MAX_SIZE];
int stackTop = -1;

void push(char data)
{
    stackTop = stackTop + 1;
    stack[stackTop] = data;
}

bool isEmpty()
{
    if (stackTop == -1)
        return true;
    return false;
}

char top()
{
    if (!isEmpty())
        return stack[stackTop];
}

char pop()
{
    if (!isEmpty())
    {
        char data = stack[stackTop];
        stackTop = stackTop - 1;
        return data;
    }
}

void print()
{
    for (int i = 0; i <= stackTop; i++)
    {
        printf("%d ", stack[i]);
    }
}

// int main()
// {
//     push('a');
//     push('b');
//     push('c');
//     printf("%c ", pop());
//     printf("%c ", pop());
//     printf("%c ", top());
// }