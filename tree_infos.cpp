# include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

int height(Node* root)
{
    if (root == nullptr)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}