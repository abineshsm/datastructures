#include <iostream>
// breafth first traversal or level order traversal
#include "./binary_search_tree.c"
#include <queue>
using namespace std;

void levelOrder(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty!\n");
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct Node *node = q.front();
        cout << node->data << " ";
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
        q.pop();
    }
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
    levelOrder(root);
}