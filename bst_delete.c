#include "./binary_search_tree.c"

struct Node *findMin(struct Node *root)
{
    if (root == NULL)
        return root;
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node *delete (struct Node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = delete (root->left, data);
    else if (data > root->data)
        root->right = delete (root->right, data);
    else
    {
        // case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // case 2: single child - left
        else if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        // case 2: single child - right
        else if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        // case 3: both children
        else
        {
            struct Node *temp = findMin(root);
            root->data = temp->data;
            root->right = delete (root->right, root->data);
        }
    }
    return root;
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
    printf("%d\n", search(root, 17));
    root = delete (root, 17);
    printf("%d\n", search(root, 17));
}