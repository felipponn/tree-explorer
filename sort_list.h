#ifndef SORT_LIST_H
#define SORT_LIST_H
#include <iostream>
#include <fstream>
using namespace std;

// Estrutura para um nó da lista duplamente encadeada
struct NodeList {
    int nData;
    NodeList* ptrPrev;
    NodeList* ptrNext;
};

// Cria um novo nó
struct NodeList* createNode(int nData);

// Insere um novo nó no final da lista
void insertBack(NodeList** ptrptrHead, NodeList** ptrptrTail, int nData);

// Printa a lista
void printList(NodeList* ptrHead);

// Converte uma árvore binária em uma lista duplamente encadeada
void treeToDoublyLinkedList(struct Node* ptrRoot, struct NodeList** ptrHead, struct NodeList** ptrTail);

// Troca dois nós de lugar
void swapNode(NodeList** ptrptrHead, NodeList** ptrptrTail, NodeList* ptrNode1, NodeList* ptrNode2);

// Ordena uma lista duplamente encadeada usando o algoritmo Bubble Sort
void bubbleSort(NodeList** ptrptrHead, NodeList** ptrptrTail);

// Ordena uma lista duplamente encadeada usando o algoritmo Selection Sort
void selectionSort(NodeList** ptrptrHead, NodeList** ptrptrTail);

// Ordena uma lista duplamente encadeada usando o algoritmo Insertion Sort
void insertionSort(NodeList** ptrptrHead, NodeList** ptrptrTail);

// Ordena uma lista duplamente encadeada usando o algoritmo Shell Sort
void shellSort(NodeList** ptrptrHead, NodeList** ptrptrTail);


#endif