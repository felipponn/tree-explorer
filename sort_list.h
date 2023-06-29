#include <iostream>
#include <fstream>

using namespace std;

// ================================================================================= //
// ------------------------------ Primeira Parte -----------------------------------
// Funções para criar a lista, inserir elementos e imprimir a lista
// Notação seguida: https://pt.wikipedia.org/wiki/Nota%C3%A7%C3%A3o_h%C3%BAngara
// ================================================================================= //


// Estrutura para um nó da lista duplamente encadeada
struct NodeList {
    int nData;
    NodeList* pPrev;
    NodeList* pNext;
};

// Função para criar um novo nó
NodeList* createNode(int nData) {
    NodeList* pNewNode = new NodeList;
    pNewNode->nData = nData;
    pNewNode->pPrev = nullptr;
    pNewNode->pNext = nullptr;
    return pNewNode;
}

// Função para inserir um novo nó no final da lista
void insertBack(NodeList** ppHead, NodeList** ppTail, int nData) {
    NodeList* pNewNode = createNode(nData);
    if (*ppHead == nullptr) {
        *ppHead = pNewNode;
    } else {
        (*ppTail)->pNext = pNewNode;
        pNewNode->pPrev = *ppTail;
    }
    *ppTail = pNewNode;
}

// Função para imprimir a lista
void printList(NodeList* pHead) {
    NodeList* pCurrent = pHead;
    while (pCurrent != nullptr) {
        cout << pCurrent->nData << " ";
        pCurrent = pCurrent->pNext;
    }
    cout << endl << endl;
}


// ================================================================================= //
// ------------------------------- Segunda Parte -----------------------------------
// Função para converter uma árvore binária em uma lista duplamente encadeada
// ================================================================================= //


// Percorre a árvore com pré-ordem e insere os nós na lista
void treeToDoublyLinkedList(struct Node* pRoot, NodeList** ppHead, NodeList** ppTail) {
    if (pRoot == nullptr) return;
    
    // Inserir o nó atual no final da lista
    insertBack(ppHead, ppTail, pRoot->iPayload);

    // Converter a subárvore esquerda em uma lista duplamente encadeada
    treeToDoublyLinkedList(pRoot->ptrLeft, ppHead, ppTail);
    
    // Converter a subárvore direita em uma lista duplamente encadeada
    treeToDoublyLinkedList(pRoot->ptrRight, ppHead, ppTail);
}

// ================================================================================= //
// ------------------------------- Terceira Parte ----------------------------------
// Função para trocar dois nós de lugar
// Funções de ordenação de lista duplamente encadeada
// Funções: bubbleSort, selectionSort, insertionSort, mergeSort
// ================================================================================= //

// Função swap para lista duplamente encadeada
void swapNode(NodeList** ppHead, NodeList** ppTail, NodeList* pNode1, NodeList* pNode2) {
    if (*ppHead == nullptr || *ppTail == nullptr) {
        // Lista vazia, não há nada para trocar
        return;
    }
    
    // Verifica se os nós são os mesmos
    if (pNode1 == pNode2) {
        return;
    }

    // Verifica se os nós são adjacentes (pNode1 -> pNode2)
    if (pNode1->pNext == pNode2) {
        // Troca os nós adjacentes
        NodeList* pPrev1 = pNode1->pPrev;
        NodeList* pNext2 = pNode2->pNext;

        // Nó anterior ao pNode1 apontará para o pNode2
        if (pPrev1 != nullptr) {
            pPrev1->pNext = pNode2;
        } else {
            *ppHead = pNode2;
        }

        // Nó posterior ao pNode2 apontará para o pNode1
        if (pNext2 != nullptr) {
            pNext2->pPrev = pNode1;
        } else {
            *ppTail = pNode1;
        }

        pNode2->pPrev = pPrev1;
        pNode2->pNext = pNode1;
        pNode1->pPrev = pNode2;
        pNode1->pNext = pNext2;

    // Verifica se os nós são adjacentes (pNode2 -> pNode1)
    } else if (pNode2->pNext == pNode1) {
        // Troca os nós adjacentes
        NodeList* pPrev2 = pNode2->pPrev;
        NodeList* pNext1 = pNode1->pNext;

        // Nó anterior ao pNode2 apontará para o pNode1
        if (pPrev2 != nullptr) {
            pPrev2->pNext = pNode1;
        } else {
            *ppHead = pNode1;
        }
        
        // Nó posterior ao pNode1 apontará para o pNode2
        if (pNext1 != nullptr) {
            pNext1->pPrev = pNode2;
        } else {
            *ppTail = pNode2;
        }

        pNode1->pPrev = pPrev2;
        pNode1->pNext = pNode2;
        pNode2->pPrev = pNode1;
        pNode2->pNext = pNext1;

    // Os nós não são adjacentes
    } else {
        NodeList* pPrev1 = pNode1->pPrev;
        NodeList* pNext1 = pNode1->pNext;
        NodeList* pPrev2 = pNode2->pPrev;
        NodeList* pNext2 = pNode2->pNext;

        // Etapa 1: Nó anterior ao pNode1 apontará para o pNode2 (Next)
        if (pPrev1 != nullptr) {
            pPrev1->pNext = pNode2;
        } else {
            *ppHead = pNode2;
        }

        // Etapa 2: Nó posterior ao pNode1 apontará para o pNode2 (Prev)
        if (pNext1 != nullptr) {
            pNext1->pPrev = pNode2;
        } else {
            *ppTail = pNode2;
        }

        // Etapa 3: Nó anterior ao pNode2 apontará para o pNode1 (Next)
        if (pPrev2 != nullptr) {
            pPrev2->pNext = pNode1;
        } else {
            *ppHead = pNode1;
        }

        // Etapa 4: Nó posterior ao pNode2 apontará para o pNode1 (Prev)
        if (pNext2 != nullptr) {
            pNext2->pPrev = pNode1;
        } else {
            *ppTail = pNode1;
        }

        pNode1->pPrev = pPrev2;
        pNode1->pNext = pNext2;
        pNode2->pPrev = pPrev1;
        pNode2->pNext = pNext1;
    }
}

// ================================================================================= //
//13. Uma das opções deve converter a árvore em uma lista e ordenar com bublesort
// ================================================================================= //


void bubbleSort(NodeList** ppHead, NodeList** ppTail) {
    // Lista vazia ou com apenas um elemento, não precisa ordenar
    if (*ppHead == nullptr || (*ppHead)->pNext == nullptr) {
        return; 
    }
    
    bool bSwapped = true;
    NodeList* pCurrent;
    while (bSwapped) {
        bSwapped = false;
        pCurrent = *ppHead;
        // Percorre a lista trocando os nós adjacentes
        while (pCurrent->pNext != nullptr) {
            if (pCurrent->nData > pCurrent->pNext->nData) {
                // Troca os nós
                // Ao trocar os nós, não é necessário atualizar o ponteiro
                swapNode(ppHead, ppTail, pCurrent, pCurrent->pNext);
                bSwapped = true;
            } else {
                pCurrent = pCurrent->pNext;
            }
        }
    }
}

// =================================================================================== //
//14. Uma das opções deve converter a árvore em uma lista e ordenar com Selection Sort
// =================================================================================== //

void selectionSort(NodeList** ppHead, NodeList** ppTail) {
    // Lista vazia ou com apenas um elemento, não precisa ordenar
    if (*ppHead == nullptr || (*ppHead)->pNext == nullptr) {
        return;
    }

    NodeList* pCurrent = *ppHead;

    while (pCurrent->pNext != nullptr) {
        NodeList* pMinNode = pCurrent;
        NodeList* pTemp = pCurrent->pNext;

        // Encontra o nó com o menor valor
        while (pTemp != nullptr) {
            if (pTemp->nData < pMinNode->nData) {
                pMinNode = pTemp;
            }

            pTemp = pTemp->pNext;
        }

        // Verifica se o nó mínimo é diferente do nó atual
        if (pMinNode != pCurrent) {
            // Troca os nós
            swapNode(ppHead, ppTail, pCurrent, pMinNode);

            // Atualiza o ponteiro tail, se necessário
            if (pMinNode == *ppTail) {
                *ppTail = pCurrent;
            }
        }

        pCurrent = pMinNode->pNext;
    }
}

// ================================================================================= //
//15. Uma das opções deve converter a árvore em uma lista e ordenar com insertion Sort
// ================================================================================= //

void insertionSort(NodeList** ppHead, NodeList** ppTail) {
    if (*ppHead == nullptr || *ppTail == nullptr) {
        // Lista vazia ou contém apenas um elemento, já está ordenada
        return;
    }

    NodeList* pSorted = nullptr; // Lista de nós ordenados

    NodeList* pCurrent = *ppHead;
    while (pCurrent != nullptr) {
        NodeList* pNextNode = pCurrent->pNext;

        // Encontra a posição correta para inserir o nó atual na lista ordenada
        // Pega o elemento pCurrent e busca onde deve ser insere na sublista ordenada
        NodeList* pSortedCurrent = pSorted;
        while (pSortedCurrent != nullptr && pSortedCurrent->nData < pCurrent->nData) {
            pSortedCurrent = pSortedCurrent->pNext;
        }

        if (pSortedCurrent == nullptr) {
            // O nó atual deve ser inserido no final da lista ordenada
            if (pSorted == nullptr) {
                // A lista ordenada está vazia
                pSorted = pCurrent;
                pSorted->pPrev = nullptr;
                pSorted->pNext = nullptr;
            } else {
                NodeList* pLastNode = pSorted;
                while (pLastNode->pNext != nullptr) {
                    pLastNode = pLastNode->pNext;
                }
                pLastNode->pNext = pCurrent;
                pCurrent->pPrev = pLastNode;
                pCurrent->pNext = nullptr;
            }
        } else {
            // O nó atual deve ser inserido antes de pSortedCurrent
            NodeList* pPrevNode = pSortedCurrent->pPrev;

            if (pPrevNode != nullptr) {
                pPrevNode->pNext = pCurrent;
            } else {
                pSorted = pCurrent;
            }

            pSortedCurrent->pPrev = pCurrent;
            pCurrent->pPrev = pPrevNode;
            pCurrent->pNext = pSortedCurrent;
        }

        pCurrent = pNextNode;
    }

    // Atualiza a cabeça e a cauda da lista original
    *ppHead = pSorted;
    NodeList* pLastNode = pSorted;
    while (pLastNode->pNext != nullptr) {
        pLastNode = pLastNode->pNext;
    }
    *ppTail = pLastNode;
}

// ================================================================================= //
//16. Uma das opções deve converter a árvore em uma lista e ordenar com Shell Sort
// ================================================================================= //

void shellSort(NodeList** ppHead, NodeList** ppTail) {
    int nSize = 0; // Tamanho da lista
    NodeList* pCurrent = *ppHead;

    // Conta o tamanho da lista
    while (pCurrent != nullptr) {
        pCurrent = pCurrent->pNext;
        nSize++;
    }

    // Calcula o intervalo inicial que é dado por n/2
    int nInterval = nSize / 2;

    while (nInterval > 0) {
        // Percorre a lista com o intervalo atual
        for (int i = nInterval; i < nSize; i++) {
            NodeList* pCurrent = *ppHead;

            // Vai até o nó na posição i
            for (int j = 0; j < i; j++) {
                pCurrent = pCurrent->pNext;
            }
            NodeList* pPrev = pCurrent->pPrev;

            // Realiza a comparação e troca dos nós conforme necessário
            while (pPrev != nullptr && pCurrent != nullptr && pPrev->nData > pCurrent->nData) {
                swapNode(ppHead, ppTail, pPrev, pCurrent);

                // Atualiza os ponteiros pPrev e pCurrent
                NodeList* pTemp = pPrev;
                pPrev = pCurrent;
                pCurrent = pTemp;
                pCurrent = pCurrent->pPrev;

                // Retrocede para trás pelo intervalo
                if (pPrev != nullptr)
                    pPrev = pPrev->pPrev;
            }
        }

        // Atualiza o intervalo para a próxima iteração
        nInterval /= 2;
    }
}