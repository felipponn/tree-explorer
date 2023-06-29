#include <iostream>
#include "create_tree.h"

using namespace std;

int main()
{
    struct Node* ptrRoot = nullptr;
    ptrRoot = insertNode(ptrRoot, 10);
    ptrRoot = insertNode(ptrRoot, 5);
    ptrRoot = insertNode(ptrRoot, 15);
    ptrRoot = insertNode(ptrRoot, 3);
    ptrRoot = insertNode(ptrRoot, 7);
    ptrRoot = insertNode(ptrRoot, 13);
    ptrRoot = insertNode(ptrRoot, 17);

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