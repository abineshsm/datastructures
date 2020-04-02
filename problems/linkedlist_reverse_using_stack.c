#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
struct Node *stack;

void insert(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    struct Node *trav = head;
    while (trav->next != NULL)
        trav = trav->next;
    trav->next = temp;
}

void print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = stack;
    stack = temp;
}

int pop()
{
    struct Node *temp = stack;
    int data = temp->data;
    stack = temp->next;
    free(temp);
    return data;
}

void reverse()
{
    int count = 0;
    while (head != NULL)
    {
        push(head->data);
        struct Node *temp = head;
        head = head->next;
        free(temp);
        count++;
    }
    while (count > 0)
    {
        insert(pop());
        count--;
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    print();
    reverse(head);
    print();
}