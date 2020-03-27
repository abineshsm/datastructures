#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void push(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

int pop()
{
    int data = head->data;
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return data;
}

void print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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
    printf("\n");
    print();
}