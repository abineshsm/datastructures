#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* getNewNode(int data)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node *root, int data)
{
    if(root == NULL)
    {
        root = getNewNode(data);
    }
    else if(data <= root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    return root;
}

bool search(struct Node *root, int data)
{
    if(root == NULL)
        return false;
    else if(data == root->data)
        return true;
    else if(data < root->data)
        return search(root->left, data);
    else if(data > root->data)
        return search(root->right, data);
}

// int main()
// {
//     struct Node *root = NULL;
//     root = insert(root, 20);
//     root = insert(root, 25);
//     root = insert(root, 15);
//     root = insert(root, 10);
//     printf("%d\n", search(root, 10));
// }