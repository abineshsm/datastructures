#include "../binary_search_tree.c"
#include <stdbool.h>
#include <limits.h>

bool isBinarySearchTree(struct Node *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->data > min &&
        root->data < max &&
        isBinarySearchTree(root->left, min, root->data) &&
        isBinarySearchTree(root->right, root->data, max))
    {
        return true;
    }
    else
        return false;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 17);
    root = insert(root, 22);
    root = insert(root, 15);
    root = insert(root, 18);
    root = insert(root, 21);
    root = insert(root, 23);
    printf("%d\n", isBinarySearchTree(root, INT_MIN, INT_MAX));
}