#include<iostream>
#include"create_tree.h"
#include"tree_infos.h"

using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

int main()
{
    struct Node* root = new Node;
    root->iPayload = 10;
    root->ptrLeft = nullptr;
    root->ptrRight = nullptr;

    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 12);
    insertNode(root, 17);
    insertNode(root, 1);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);
    insertNode(root, 11);
    insertNode(root, 13);

    cout << "é completa? " << complete(root) << endl; // sim
    cout << "é perfeita? " << perfect(root) << endl; // não
    cout << "altura: " << height(root) << endl; // 4
    cout << "tamanho: " << size(root) << endl; // 13
    return 0;
}