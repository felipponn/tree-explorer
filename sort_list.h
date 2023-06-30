#include <iostream>
#include <fstream>
using namespace std;

// Estrutura para um nó da lista duplamente encadeada
struct NodeList {
    int nData;
    NodeList* pPrev;
    NodeList* pNext;
};

// Cria um novo nó
struct NodeList* createNode(int nData);

// Insere um novo nó no final da lista
void insertBack(NodeList** ppHead, NodeList** ppTail, int nData);

// Printa a lista
void printList(NodeList* pHead);

// Converte uma árvore binária em uma lista duplamente encadeada
void treeToDoublyLinkedList(struct Node* pRoot, struct NodeList** pHead, struct NodeList** pTail);

// Troca dois nós de lugar
void swapNode(NodeList** ppHead, NodeList** ppTail, NodeList* pNode1, NodeList* pNode2);

// Ordena uma lista duplamente encadeada usando o algoritmo Bubble Sort
void bubbleSort(NodeList** ppHead, NodeList** ppTail);

// Ordena uma lista duplamente encadeada usando o algoritmo Selection Sort
void selectionSort(NodeList** ppHead, NodeList** ppTail);

// Ordena uma lista duplamente encadeada usando o algoritmo Insertion Sort
void insertionSort(NodeList** ppHead, NodeList** ppTail);

// Ordena uma lista duplamente encadeada usando o algoritmo Shell Sort
void shellSort(NodeList** ppHead, NodeList** ppTail);

