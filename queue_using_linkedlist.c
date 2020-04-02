#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
struct Node *tail;

bool isEmpty()
{
    if (head == NULL)
        return true;
    return false;
}

void enqueue(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if (isEmpty())
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
    }
    else
    {
        int data = head->data;
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return data;
    }
}

int gethead()
{
    if (!isEmpty())
        return head->data;
}

int main()
{
    enqueue(2);
    enqueue(4);
    enqueue(10);
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
}