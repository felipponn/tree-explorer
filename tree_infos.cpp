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

int size(Node* root)
{
    if (root == nullptr)
        return 0;
    else
        return 1 + size(root->left) + size(root->right);
}

bool complete(Node* root)
{
    if (root->right == nullptr || root->left == nullptr)
        if (root->right == nullptr && root->left == nullptr)
            return true;
        else
            return false;
    return complete(root->left) && complete(root->right);
}

bool perfect(Node* root)
{
    if (root == nullptr)
        return true;
    else if (height(root->left) == height(root->right))
        return perfect(root->left) && perfect(root->right);
    else
        return false;
}