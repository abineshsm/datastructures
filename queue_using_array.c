#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 101

char queue[MAX_SIZE];
int head = -1, tail = -1;

bool isEmpty()
{
    if (head == -1 && tail == -1)
        return true;
    return false;
}

void enqueue(char data)
{
    if (tail == MAX_SIZE - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    if (head == -1 && tail == -1)
        head++;
    queue[++tail] = data;
}

char dequeue()
{
    char data;
    if (isEmpty())
    {
        printf("Queue is empty!\n");
    }
    else if (head == tail)
    {
        data = queue[head];
        head = tail = -1;
    }
    else
    {
        data = queue[head++];
    }
    return data;
}

char gethead()
{
    if (!isEmpty())
        return queue[head];
}

int main()
{
    enqueue('a');
    enqueue('b');
    printf("%c ", dequeue());
    printf("%c ", dequeue());
}
