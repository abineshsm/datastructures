#include "../binary_search_tree.c"

int maximum(int left, int right)
{
    if (left >= right)
        return left;
    else
        return right;
}

int findHeight(struct Node *root)
{
    if (root == NULL)
        return -1;
    return maximum(findHeight(root->left), findHeight(root->right)) + 1;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 9);
    root = insert(root, 8);
    printf("%d\n", findHeight(root));
}