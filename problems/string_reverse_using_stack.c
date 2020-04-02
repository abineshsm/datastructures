#include<stdio.h>
#include<string.h>
#define MAX_SIZE 101

char stack[MAX_SIZE];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

void reverse(char *str, int n)
{
    for(int i=0; i < n; i++)
        push(str[i]);

    for(int i = 0; i < n; i++)
        str[i] = pop();
}

int main()
{
    char str[MAX_SIZE];
    printf("Enter the string to be reversed.\n");
    gets(str);
    reverse(str, strlen(str));
    printf("%s", str);
}
