#include "../linkedlist.c"

struct Node *middleNode(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return slow;
}

int main()
{
    // insertOnTail(1);
    // insertOnTail(2);
    // insertOnTail(3);
    // insertOnTail(4);
    // insertOnTail(5);
    // insertOnTail(6);
    // print();
    struct Node *temp = middleNode(head);
    printf("%d\n", temp->data);
}