#include <iostream>
#include <fstream>
#include "create_tree.h"
#include "sort_list.h"

using namespace std;

// ========================================================================= //
// -------------------------------  TESTE ----------------------------------
// Arquivo para testar a função de ordenação de listas
// As principais funções da sort_list.h são:
// - treeToDoublyLinkedList: converte uma árvore binária em uma lista duplamente encadeada
// - swap: troca dois nós de lugar
// - bubbleSort: ordena uma lista duplamente encadeada
// - selectionSort: ordena uma lista duplamente encadeada
// - insertionSort: ordena uma lista duplamente encadeada
// - shellSort: ordena uma lista duplamente encadeada
// ========================================================================= //


int main() {
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando funcao de criar uma arvore e converter em lista: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    // lista com números repetidos, negativos e zero
    struct Node* pRoot = nullptr;
    pRoot = insertNode(pRoot, 4);
    pRoot = insertNode(pRoot, 7);
    pRoot = insertNode(pRoot, -1);
    pRoot = insertNode(pRoot, 2);
    pRoot = insertNode(pRoot, 9);
    pRoot = insertNode(pRoot, 5);
    pRoot = insertNode(pRoot, 6);
    pRoot = insertNode(pRoot, 0);
    pRoot = insertNode(pRoot, 1);
    pRoot = insertNode(pRoot, -2);
    pRoot = insertNode(pRoot, 1);
    pRoot = insertNode(pRoot, 8);
    pRoot = insertNode(pRoot, 3);

    cout << "Arvore: ";
    traversePreOrder(pRoot);
    cout << endl;

    struct NodeList* pHead = nullptr;
    struct NodeList* pTail = nullptr;
    treeToDoublyLinkedList(pRoot, &pHead, &pTail);

    cout << "Lista: ";
    printList(pHead);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando funcao swap: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    NodeList* pHead2 = nullptr;
    NodeList* pTail2 = nullptr;
    treeToDoublyLinkedList(pRoot, &pHead2, &pTail2);
    printList(pHead2);
    swapNode(&pHead2, &pTail2, pTail2, pTail2->pPrev);
    printList(pHead2);

    swapNode(&pHead2, &pTail2, pHead2, pHead2->pNext);
    printList(pHead2);

    swapNode(&pHead2, &pTail2, pHead2->pNext, pTail2->pPrev);
    printList(pHead2);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando funcao bubbleSort: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    NodeList* pHead3 = nullptr;
    NodeList* pTail3 = nullptr;

    treeToDoublyLinkedList(pRoot, &pHead3, &pTail3);
    cout << "Lista: ";
    printList(pHead3);
    bubbleSort(&pHead3, &pTail3);
    cout << "Lista ordenada: ";
    printList(pHead3);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando funcao selectionSort: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    NodeList* pHead4 = nullptr;
    NodeList* pTail4 = nullptr;

    treeToDoublyLinkedList(pRoot, &pHead4, &pTail4);
    cout << "Lista: ";
    printList(pHead4);
    selectionSort(&pHead4, &pTail4);
    cout << "Lista ordenada: ";
    printList(pHead4);
    
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando funcao insertionSort: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    
    NodeList* pHead5 = nullptr;
    NodeList* pTail5 = nullptr;

    treeToDoublyLinkedList(pRoot, &pHead5, &pTail5);
    cout << "Lista: ";
    printList(pHead5);
    insertionSort(&pHead5, &pTail5);
    cout << "Lista ordenada: ";
    printList(pHead5);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando funcao shellSort: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    NodeList* pHead6 = nullptr;
    NodeList* pTail6 = nullptr;

    treeToDoublyLinkedList(pRoot, &pHead6, &pTail6);
    cout << "Lista: ";
    printList(pHead6);
    shellSort(&pHead6, &pTail6);
    cout << "Lista ordenada: ";
    printList(pHead6);

    return 0;
}