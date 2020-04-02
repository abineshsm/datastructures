#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 3

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
    if (isEmpty())
    {
        head++;
        queue[++tail] = data;
        return;
    }
    tail = ++tail % MAX_SIZE;
    if (head == tail)
    {
        printf("\nQueue is full!\n");
        tail = (tail + MAX_SIZE - 1) % MAX_SIZE;
        return;
    }
    queue[tail] = data;
}

char dequeue()
{
    char data;
    if (isEmpty())
    {
        printf("\nQueue is empty!\n");
        return ' ';
    }
    data = queue[head];
    if (head == tail)
    {
        head = -1;
        tail = -1;
    }
    else
        head = ++head % MAX_SIZE;
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
    enqueue('c');
    enqueue('d');
    enqueue('e');
    printf("%c ", dequeue());
    printf("%c ", dequeue());
    printf("%c ", dequeue());
    printf("%c ", dequeue());
}
