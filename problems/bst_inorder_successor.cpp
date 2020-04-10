#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

Node *getNewNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return getNewNode(data);
    if (data <= root->data)
    {
        root->left = insert(root->left, data);
        (root->left)->parent = root;
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
        (root->right)->parent = root;
    }
    return root;
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int inorderSuccessor(Node *root, int data)
{
    if(root == NULL)
        return -1;
    if(data < root->data)
        inorderSuccessor(root->left, data);
    else if(data > root->data)
        inorderSuccessor(root->right, data);
    else
    {
        if(root->right == NULL)
            return (root->parent)->data;
        else 
            return (root->right)->data;
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 17);
    root = insert(root, 22);
    root = insert(root, 15);
    root = insert(root, 18);
    root = insert(root, 21);
    root = insert(root, 23);
    // inorderTraversal(root);
    cout << inorderSuccessor(root, 17);
}
