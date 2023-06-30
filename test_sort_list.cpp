#include <iostream>
#include <fstream>
#include "create_tree.h"
#include "sort_list.h"
#include "struct_node.h"

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
    struct Node* ptrRoot = nullptr;
    ptrRoot = insertNode(ptrRoot, 4);
    ptrRoot = insertNode(ptrRoot, 7);
    ptrRoot = insertNode(ptrRoot, -1);
    ptrRoot = insertNode(ptrRoot, 2);
    ptrRoot = insertNode(ptrRoot, 9);
    ptrRoot = insertNode(ptrRoot, 5);
    ptrRoot = insertNode(ptrRoot, 6);
    ptrRoot = insertNode(ptrRoot, 0);
    ptrRoot = insertNode(ptrRoot, 1);
    ptrRoot = insertNode(ptrRoot, -2);
    ptrRoot = insertNode(ptrRoot, 1);
    ptrRoot = insertNode(ptrRoot, 8);
    ptrRoot = insertNode(ptrRoot, 3);

    cout << "Arvore: ";
    traversePreOrder(ptrRoot);
    cout << endl;

    struct NodeList* ptrHead = nullptr;
    struct NodeList* ptrTail = nullptr;
    treeToDoublyLinkedList(ptrRoot, &ptrHead, &ptrTail);

    cout << "Lista: ";
    printList(ptrHead);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando funcao swap: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    NodeList* ptrHead2 = nullptr;
    NodeList* ptrTail2 = nullptr;
    treeToDoublyLinkedList(ptrRoot, &ptrHead2, &ptrTail2);
    printList(ptrHead2);
    swapNode(&ptrHead2, &ptrTail2, ptrTail2, ptrTail2->ptrPrev);
    printList(ptrHead2);

    swapNode(&ptrHead2, &ptrTail2, ptrHead2, ptrHead2->ptrNext);
    printList(ptrHead2);

    swapNode(&ptrHead2, &ptrTail2, ptrHead2->ptrNext, ptrTail2->ptrPrev);
    printList(ptrHead2);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando funcao bubbleSort: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    NodeList* ptrHead3 = nullptr;
    NodeList* ptrTail3 = nullptr;

    treeToDoublyLinkedList(ptrRoot, &ptrHead3, &ptrTail3);
    cout << "Lista: ";
    printList(ptrHead3);
    bubbleSort(&ptrHead3, &ptrTail3);
    cout << "Lista ordenada: ";
    printList(ptrHead3);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando funcao selectionSort: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    NodeList* ptrHead4 = nullptr;
    NodeList* ptrTail4 = nullptr;

    treeToDoublyLinkedList(ptrRoot, &ptrHead4, &ptrTail4);
    cout << "Lista: ";
    printList(ptrHead4);
    selectionSort(&ptrHead4, &ptrTail4);
    cout << "Lista ordenada: ";
    printList(ptrHead4);
    
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando funcao insertionSort: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    
    NodeList* ptrHead5 = nullptr;
    NodeList* ptrTail5 = nullptr;

    treeToDoublyLinkedList(ptrRoot, &ptrHead5, &ptrTail5);
    cout << "Lista: ";
    printList(ptrHead5);
    insertionSort(&ptrHead5, &ptrTail5);
    cout << "Lista ordenada: ";
    printList(ptrHead5);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando funcao shellSort: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    NodeList* ptrHead6 = nullptr;
    NodeList* ptrTail6 = nullptr;

    treeToDoublyLinkedList(ptrRoot, &ptrHead6, &ptrTail6);
    cout << "Lista: ";
    printList(ptrHead6);
    shellSort(&ptrHead6, &ptrTail6);
    cout << "Lista ordenada: ";
    printList(ptrHead6);

    return 0;
}