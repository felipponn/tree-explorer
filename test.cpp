#include <iostream>
#include "create_tree.h"

using namespace std;

int main()
{
    struct Node* ptrRoot = newNode(10);
    ptrRoot->ptrLeft = newNode(5);
    ptrRoot->ptrRight = newNode(15);
    ptrRoot->ptrLeft->ptrLeft = newNode(3);
    ptrRoot->ptrLeft->ptrRight = newNode(7);
    ptrRoot->ptrRight->ptrLeft = newNode(13);
    ptrRoot->ptrRight->ptrRight = newNode(17);

    cout << "traversePreOrder:";
    traversePreOrder(ptrRoot);
    cout << "\n" << endl;

    cout << "traverseInOrder:";
    traverseInOrder(ptrRoot);
    cout << "\n" << endl;
     
    cout << "traversePostOrder:";
    traversePostOrder(ptrRoot);
    cout << "\n" << endl;

    cout << "deleteNode:";
    ptrRoot = deleteNode(ptrRoot, 10);
    traverseInOrder(ptrRoot);
    cout << "\n" << endl;

    cout << "searchNode: ";
    struct Node* ptrNode = searchNode(ptrRoot, 15);
    if (ptrNode != nullptr) cout << ptrNode->iPayload << " -> " << ptrNode;
    else cout << "Nó não encontrado";
    cout << "\n" << endl;

    string strFileName = "create_tree.txt";
    cout << "constructTreeFromFile(" << strFileName << "):";
    ptrRoot = constructTreeFromFile(strFileName);
    traverseInOrder(ptrRoot);
    cout << "\n" << endl;

    ptrRoot = constructTreeFromUserInput();
    traverseInOrder(ptrRoot);

    return 0;
}