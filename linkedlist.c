#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void insertOnHead(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertOnTail(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        struct Node *trav = head;
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = temp;
    }
}

void insert(int data, int pos)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        struct Node *trav = head;
        while (pos > 2)
        {
            trav = trav->next;
            pos--;
        }
        temp->next = trav->next;
        trav->next = temp;
    }
}

void delete (int pos)
{
    struct Node *temp1 = head;
    if (pos == 1)
    {
        head = head->next;
        free(temp1);
        return;
    }
    while (pos > 2)
    {
        temp1 = temp1->next;
        pos--;
    }
    struct Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void reverse()
{
    struct Node *current, *prev, *next;
    prev = NULL;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void printRecursion(struct Node *current)
{
    if (current == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d, ", current->data);
    printRecursion(current->next);
}

void printReverseRecursion(struct Node *current)
{
    if (current == NULL)
    {
        printf("\n");
        return;
    }
    printReverseRecursion(current->next);
    printf("%d, ", current->data);
}

void reverseRecursion(struct Node *current)
{
    if (current->next == NULL)
    {
        head = current;
        return;
    }
    reverseRecursion(current->next);
    (current->next)->next = current;
    current->next = NULL;
}

void print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// int main()
// {
//     head = NULL;
//     int data[] = {2, 3, 5};
//     int n = sizeof(data) / sizeof(data[0]);
//     for (int i = 0; i < n; i++)
//     {
//         // insertOnHead(data[i]);
//         insertOnTail(data[i]);
//     }
//     // print();
//     insert(1, 1);
//     insert(4, 4);
//     insert(6, 6);
//     print();
//     // delete(6);
//     // delete(4);
//     // delete(1);
//     // print();
//     // reverse();
//     // reverseRecursion(head);
//     // print();
//     // printRecursion(head);
//     printReverseRecursion(head);
// }