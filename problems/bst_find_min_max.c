#include "../binary_search_tree.c"

int findMin(struct Node *root)
{
    if(root == NULL)
    {
        printf("Tree is empty!\n");
        return -1;
    }
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct Node *root)
{
    if(root == NULL)
    {
        printf("Tree is empty!\n");
        return -1;
    }
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 15);
    root = insert(root, 10);
    // printf("%d\n", search(root, 10));
    printf("min - %d\n", findMin(root));
    printf("max - %d\n", findMax(root));
}