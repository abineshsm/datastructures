#include <iostream>
#include "./binary_search_tree.c"
using namespace std;

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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
    cout << "Preorder traversal\n";
    preorder(root);
    cout << "\nInorder traversal\n";
    inorder(root);
    cout << "\nPostorder traversal\n";
    postorder(root);
}