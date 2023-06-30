#include <iostream>
#include <fstream>
#include "struct_node.h"

using namespace std;

// ================================================================================= //
// ------------------------------ Primeira Parte -----------------------------------
// Funções para criar a lista, inserir elementos e imprimir a lista
// Notação seguida: https://pt.wikipedia.org/wiki/Nota%C3%A7%C3%A3o_h%C3%BAngara
// ================================================================================= //


// Estrutura para um nó da lista duplamente encadeada
struct NodeList {
    int iData;
    NodeList* ptrPrev;
    NodeList* ptrNext;
};

// Função para criar um novo nó
NodeList* createNode(int iData) {
    NodeList* ptrNewNode = new NodeList;
    ptrNewNode->iData = iData;
    ptrNewNode->ptrPrev = nullptr;
    ptrNewNode->ptrNext = nullptr;
    return ptrNewNode;
}

// Função para inserir um novo nó no final da lista
void insertBack(NodeList** ptrHead, NodeList** ptrTail, int iData) {
    NodeList* ptrNewNode = createNode(iData);
    if (*ptrHead == nullptr) {
        *ptrHead = ptrNewNode;
    } else {
        (*ptrTail)->ptrNext = ptrNewNode;
        ptrNewNode->ptrPrev = *ptrTail;
    }
    *ptrTail = ptrNewNode;
}

// Função para imprimir a lista
void printList(NodeList* ptrHead) {
    NodeList* ptrCurrent = ptrHead;
    while (ptrCurrent != nullptr) {
        cout << ptrCurrent->iData << " ";
        ptrCurrent = ptrCurrent->ptrNext;
    }
    cout << endl << endl;
}


// ================================================================================= //
// ------------------------------- Segunda Parte -----------------------------------
// Função para converter uma árvore binária em uma lista duplamente encadeada
// ================================================================================= //


// Percorre a árvore com pré-ordem e insere os nós na lista
void treeToDoublyLinkedList(struct Node* ptrRoot, NodeList** ptrHead, NodeList** ptrTail) {
    if (ptrRoot == nullptr) return;
    
    // Inserir o nó atual no final da lista
    insertBack(ptrHead, ptrTail, ptrRoot->iPayload);

    // Converter a subárvore esquerda em uma lista duplamente encadeada
    treeToDoublyLinkedList(ptrRoot->ptrLeft, ptrHead, ptrTail);
    
    // Converter a subárvore direita em uma lista duplamente encadeada
    treeToDoublyLinkedList(ptrRoot->ptrRight, ptrHead, ptrTail);
}

// ================================================================================= //
// ------------------------------- Terceira Parte ----------------------------------
// Função para trocar dois nós de lugar
// Funções de ordenação de lista duplamente encadeada
// Funções: bubbleSort, selectionSort, insertionSort, mergeSort
// ================================================================================= //

// Função swap para lista duplamente encadeada
void swapNode(NodeList** ptrptrHead, NodeList** ptrptrTail, NodeList* ptrNode1, NodeList* ptrNode2) {
    // Lista vazia, não há nada para trocar
    if (*ptrptrHead == nullptr || *ptrptrTail == nullptr) {
        return;
    }
    
    // Verifica se os nós são os mesmos
    if (ptrNode1 == ptrNode2) {
        return;
    }

    // Verifica se os nós são adjacentes (ptrNode1 -> ptrNode2)
    if (ptrNode1->ptrNext == ptrNode2) {
        // Troca os nós adjacentes
        NodeList* ptrPrev1 = ptrNode1->ptrPrev;
        NodeList* ptrNext2 = ptrNode2->ptrNext;

        // Nó anterior ao ptrNode1 apontará para o ptrNode2
        if (ptrPrev1 != nullptr) {
            ptrPrev1->ptrNext = ptrNode2;
        } else {
            *ptrptrHead = ptrNode2;
        }

        // Nó posterior ao ptrNode2 apontará para o ptrNode1
        if (ptrNext2 != nullptr) {
            ptrNext2->ptrPrev = ptrNode1;
        } else {
            *ptrptrTail = ptrNode1;
        }

        ptrNode2->ptrPrev = ptrPrev1;
        ptrNode2->ptrNext = ptrNode1;
        ptrNode1->ptrPrev = ptrNode2;
        ptrNode1->ptrNext = ptrNext2;

    // Verifica se os nós são adjacentes (ptrNode2 -> ptrNode1)
    } else if (ptrNode2->ptrNext == ptrNode1) {
        // Troca os nós adjacentes
        NodeList* ptrPrev2 = ptrNode2->ptrPrev;
        NodeList* ptrNext1 = ptrNode1->ptrNext;

        // Nó anterior ao ptrNode2 apontará para o ptrNode1
        if (ptrPrev2 != nullptr) {
            ptrPrev2->ptrNext = ptrNode1;
        } else {
            *ptrptrHead = ptrNode1;
        }
        
        // Nó posterior ao ptrNode1 apontará para o ptrNode2
        if (ptrNext1 != nullptr) {
            ptrNext1->ptrPrev = ptrNode2;
        } else {
            *ptrptrTail = ptrNode2;
        }

        ptrNode1->ptrPrev = ptrPrev2;
        ptrNode1->ptrNext = ptrNode2;
        ptrNode2->ptrPrev = ptrNode1;
        ptrNode2->ptrNext = ptrNext1;

    // Os nós não são adjacentes
    } else {
        NodeList* ptrPrev1 = ptrNode1->ptrPrev;
        NodeList* ptrNext1 = ptrNode1->ptrNext;
        NodeList* ptrPrev2 = ptrNode2->ptrPrev;
        NodeList* ptrNext2 = ptrNode2->ptrNext;

        // Etapa 1: Nó anterior ao ptrNode1 apontará para o ptrNode2 (Next)
        if (ptrPrev1 != nullptr) {
            ptrPrev1->ptrNext = ptrNode2;
        } else {
            *ptrptrHead = ptrNode2;
        }

        // Etapa 2: Nó posterior ao ptrNode1 apontará para o ptrNode2 (Prev)
        if (ptrNext1 != nullptr) {
            ptrNext1->ptrPrev = ptrNode2;
        } else {
            *ptrptrTail = ptrNode2;
        }

        // Etapa 3: Nó anterior ao ptrNode2 apontará para o ptrNode1 (Next)
        if (ptrPrev2 != nullptr) {
            ptrPrev2->ptrNext = ptrNode1;
        } else {
            *ptrptrHead = ptrNode1;
        }

        // Etapa 4: Nó posterior ao ptrNode2 apontará para o ptrNode1 (Prev)
        if (ptrNext2 != nullptr) {
            ptrNext2->ptrPrev = ptrNode1;
        } else {
            *ptrptrTail = ptrNode1;
        }

        ptrNode1->ptrPrev = ptrPrev2;
        ptrNode1->ptrNext = ptrNext2;
        ptrNode2->ptrPrev = ptrPrev1;
        ptrNode2->ptrNext = ptrNext1;
    }
}

// ================================================================================= //
//13. Uma das opções deve converter a árvore em uma lista e ordenar com bublesort
// ================================================================================= //


void bubbleSort(NodeList** ptrptrHead, NodeList** ptrptrTail) {
    // Lista vazia ou com apenas um elemento, não precisa ordenar
    if (*ptrptrHead == nullptr || (*ptrptrHead)->ptrNext == nullptr) {
        return;
    }
    bool bSwaptrptred = true;
        NodeList* ptrCurrent;
        while (bSwaptrptred) {
            bSwaptrptred = false;
            ptrCurrent = *ptrptrHead;
            // Percorre a lista trocando os nós adjacentes
            while (ptrCurrent->ptrNext != nullptr) {
                if (ptrCurrent->iData > ptrCurrent->ptrNext->iData) {
                    // Troca os nós
                    // Ao trocar os nós, não é necessário atualizar o ponteiro
                    swapNode(ptrptrHead, ptrptrTail, ptrCurrent, ptrCurrent->ptrNext);
                    bSwaptrptred = true;
                } else {
                    ptrCurrent = ptrCurrent->ptrNext;
                }
            }
}

}

// =================================================================================== //
//14. Uma das opções deve converter a árvore em uma lista e ordenar com Selection Sort
// =================================================================================== //

void selectionSort(NodeList** ptrptrHead, NodeList** ptrptrTail) {
    // Lista vazia ou com apenas um elemento, não precisa ordenar
    if (*ptrptrHead == nullptr || (*ptrptrHead)->ptrNext == nullptr) {
        return;
    }

    NodeList* ptrCurrent = *ptrptrHead;

    while (ptrCurrent->ptrNext != nullptr) {
        NodeList* pMinNode = ptrCurrent;
        NodeList* pTemp = ptrCurrent->ptrNext;

        // Encontra o nó com o menor valor
        while (pTemp != nullptr) {
            if (pTemp->iData < pMinNode->iData) {
                pMinNode = pTemp;
            }

            pTemp = pTemp->ptrNext;
        }

        // Verifica se o nó mínimo é diferente do nó atual
        if (pMinNode != ptrCurrent) {
            // Troca os nós
            swapNode(ptrptrHead, ptrptrTail, ptrCurrent, pMinNode);

            // Atualiza o ponteiro tail, se necessário
            if (pMinNode == *ptrptrTail) {
                *ptrptrTail = ptrCurrent;
            }
        }

        ptrCurrent = pMinNode->ptrNext;
    }
}

// ================================================================================= //
//15. Uma das opções deve converter a árvore em uma lista e ordenar com insertion Sort
// ================================================================================= //

void insertionSort(NodeList** ptrptrHead, NodeList** ptrptrTail) {
    if (*ptrptrHead == nullptr || *ptrptrTail == nullptr) {
        // Lista vazia ou contém apenas um elemento, já está ordenada
        return;
    }

    NodeList* ptrSorted = nullptr; // Lista de nós ordenados

    NodeList* ptrCurrent = *ptrptrHead;
    while (ptrCurrent != nullptr) {
        NodeList* ptrNextNode = ptrCurrent->ptrNext;

        // Encontra a posição correta para inserir o nó atual na lista ordenada
        // Pega o elemento ptrCurrent e busca onde deve ser insere na sublista ordenada
        NodeList* ptrSortedCurrent = ptrSorted;
        while (ptrSortedCurrent != nullptr && ptrSortedCurrent->iData < ptrCurrent->iData) {
            ptrSortedCurrent = ptrSortedCurrent->ptrNext;
        }

        if (ptrSortedCurrent == nullptr) {
            // O nó atual deve ser inserido no final da lista ordenada
            if (ptrSorted == nullptr) {
                // A lista ordenada está vazia
                ptrSorted = ptrCurrent;
                ptrSorted->ptrPrev = nullptr;
                ptrSorted->ptrNext = nullptr;
            } else {
                NodeList* ptrLastNode = ptrSorted;
                while (ptrLastNode->ptrNext != nullptr) {
                    ptrLastNode = ptrLastNode->ptrNext;
                }
                ptrLastNode->ptrNext = ptrCurrent;
                ptrCurrent->ptrPrev = ptrLastNode;
                ptrCurrent->ptrNext = nullptr;
            }
        } else {
            // O nó atual deve ser inserido antes de pSortedCurrent
            NodeList* ptrPrevNode = ptrSortedCurrent->ptrPrev;

            if (ptrPrevNode != nullptr) {
                ptrPrevNode->ptrNext = ptrCurrent;
            } else {
                ptrSorted = ptrCurrent;
            }

            ptrSortedCurrent->ptrPrev = ptrCurrent;
            ptrCurrent->ptrPrev = ptrPrevNode;
            ptrCurrent->ptrNext = ptrSortedCurrent;
        }

        ptrCurrent = ptrNextNode;
    }

    // Atualiza a cabeça e a cauda da lista original
    *ptrptrHead = ptrSorted;
    NodeList* ptrLastNode = ptrSorted;
    while (ptrLastNode->ptrNext != nullptr) {
        ptrLastNode = ptrLastNode->ptrNext;
    }
    *ptrptrTail = ptrLastNode;
}

// ================================================================================= //
//16. Uma das opções deve converter a árvore em uma lista e ordenar com Shell Sort
// ================================================================================= //

void shellSort(NodeList** ptrptrHead, NodeList** ptrptrTail) {
    int nSize = 0; // Tamanho da lista
    NodeList* ptrCurrent = *ptrptrHead;

    // Conta o tamanho da lista
    while (ptrCurrent != nullptr) {
        ptrCurrent = ptrCurrent->ptrNext;
        nSize++;
    }

    // Calcula o intervalo inicial que é dado por n/2
    int nInterval = nSize / 2;

    while (nInterval > 0) {
        // Percorre a lista com o intervalo atual
        for (int i = nInterval; i < nSize; i++) {
            NodeList* ptrCurrent = *ptrptrHead;

            // Vai até o nó na posição i
            for (int j = 0; j < i; j++) {
                ptrCurrent = ptrCurrent->ptrNext;
            }
            NodeList* ptrPrev = ptrCurrent->ptrPrev;

            // Realiza a comparação e troca dos nós conforme necessário
            while (ptrPrev != nullptr && ptrCurrent != nullptr && ptrPrev->iData > ptrCurrent->iData) {
                swapNode(ptrptrHead, ptrptrTail, ptrPrev, ptrCurrent);

                // Atualiza os ponteiros ptrPrev e ptrCurrent
                NodeList* ptrTemp = ptrPrev;
                ptrPrev = ptrCurrent;
                ptrCurrent = ptrTemp;
                ptrCurrent = ptrCurrent->ptrPrev;

                // Retrocede para trás pelo intervalo
                if (ptrPrev != nullptr)
                    ptrPrev = ptrPrev->ptrPrev;
            }
        }

        // Atualiza o intervalo para a próxima iteração
        nInterval /= 2;
    }
}