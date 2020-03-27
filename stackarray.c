#include<stdio.h>
#define MAX_SIZE 101

int stack[MAX_SIZE];
int top = -1;

void push(int data)
{
    top = top + 1;
    stack[top] = data;
}

int pop()
{
    int data = stack[top];
    top = top - 1;
    return data;
}

void print()
{
    for(int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
}

int main()
{
    push(3);
    push(2);
    push(1);
    printf("%d ", pop());
    printf("%d ", pop());
    printf("%d ", pop());
}