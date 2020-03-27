#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head;

struct Node *getNewNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void insertAtHead(int data)
{
    struct Node *node = getNewNode(data);
    if (head == NULL)
    {
        head = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}

void insertAtTail(int data)
{
    struct Node *node = getNewNode(data);
    if (head == NULL)
    {
        head = node;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node->prev = temp;
    temp->next = node;
}

void insert(int data, int pos)
{
    struct Node *node = getNewNode(data);
    if (pos == 1)
    {
        if (head != NULL)
        {
            node->next = head;
            head->prev = node;
        }
        head = node;
        return;
    }
    struct Node *temp = head;
    while (pos > 2 && temp->next != NULL)
    {
        temp = temp->next;
        pos--;
    }
    node->prev = temp;
    if (temp->next != NULL)
    {
        node->next = temp->next;
        (temp->next)->prev = node;
    }
    temp->next = node;
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

int main()
{
    // insertAtHead(2);
    // insertAtHead(1);
    // insertAtTail(4);
    insert(2, 1);
    insert(4, 2);
    insert(1, 1);
    insert(3, 3);
    insert(5, 5);
    print();
}