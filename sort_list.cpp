#include <iostream>
using namespace std;

// =============== Primeira Parte ===============
// Funções para criar a lista, inserir elementos e imprimir a lista
// Notação seguida: https://pt.wikipedia.org/wiki/Nota%C3%A7%C3%A3o_h%C3%BAngara


struct Node {
    int nData;
    Node* pPrev;
    Node* pNext;
};

// Função para criar um novo nó
Node* createNode(int nData) {
    Node* pNewNode = new Node;
    pNewNode->nData = nData;
    pNewNode->pPrev = nullptr;
    pNewNode->pNext = nullptr;
    return pNewNode;
}

// Função para inserir um novo nó no final da lista
void insertBack(Node** ppHead, Node** ppTail, int nData) {
    Node* pNewNode = createNode(nData);
    if (*ppHead == nullptr) {
        *ppHead = pNewNode;
    } else {
        (*ppTail)->pNext = pNewNode;
        pNewNode->pPrev = *ppTail;
    }
    *ppTail = pNewNode;
}

// Função para imprimir a lista
void printList(Node* pHead) {
    Node* pCurrent = pHead;
    while (pCurrent != nullptr) {
        cout << pCurrent->nData << " ";
        pCurrent = pCurrent->pNext;
    }
    cout << endl << endl;
}


// =============== Segunda Parte ===============
// Função para trocar dois nós de lugar
// Funções de ordenação de lista duplamente encadeada
// Funções: bubbleSort, selectionSort, insertionSort, mergeSort

// Função swap para lista duplamente encadeada
void swap(Node** ppHead, Node** ppTail, Node* pNode1, Node* pNode2) {
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
        Node* pPrev1 = pNode1->pPrev;
        Node* pNext2 = pNode2->pNext;

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
        Node* pPrev2 = pNode2->pPrev;
        Node* pNext1 = pNode1->pNext;

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
        Node* pPrev1 = pNode1->pPrev;
        Node* pNext1 = pNode1->pNext;
        Node* pPrev2 = pNode2->pPrev;
        Node* pNext2 = pNode2->pNext;

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

void bubbleSort(Node** ppHead, Node** ppTail) {
    // Lista vazia ou com apenas um elemento, não precisa ordenar
    if (*ppHead == nullptr || (*ppHead)->pNext == nullptr) {
        return; 
    }
    
    bool bSwapped = true;
    Node* pCurrent;
    while (bSwapped) {
        bSwapped = false;
        pCurrent = *ppHead;
        // Percorre a lista trocando os nós adjacentes
        while (pCurrent->pNext != nullptr) {
            if (pCurrent->nData > pCurrent->pNext->nData) {
                // Troca os nós
                // Ao trocar os nós, não é necessário atualizar o ponteiro
                swap(ppHead, ppTail, pCurrent, pCurrent->pNext);
                bSwapped = true;
            } else {
                pCurrent = pCurrent->pNext;
            }
        }
    }
}

//14. Uma das opções deve converter a árvore em uma lista e ordenar com Selection Sort

void selectionSort(Node** ppHead, Node** ppTail) {
    // Lista vazia ou com apenas um elemento, não precisa ordenar
    if (*ppHead == nullptr || (*ppHead)->pNext == nullptr) {
        return;
    }

    Node* pCurrent = *ppHead;

    while (pCurrent->pNext != nullptr) {
        Node* pMinNode = pCurrent;
        Node* pTemp = pCurrent->pNext;

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
            swap(ppHead, ppTail, pCurrent, pMinNode);

            // Atualiza o ponteiro tail, se necessário
            if (pMinNode == *ppTail) {
                *ppTail = pCurrent;
            }
        }

        pCurrent = pMinNode->pNext;
    }
}

//14. Uma das opções deve converter a árvore em uma lista e ordenar com insertion Sort


void insertionSort(Node** ppHead, Node** ppTail) {
    if (*ppHead == nullptr || *ppTail == nullptr) {
        // Lista vazia ou contém apenas um elemento, já está ordenada
        return;
    }

    Node* pSorted = nullptr; // Lista de nós ordenados

    Node* pCurrent = *ppHead;
    while (pCurrent != nullptr) {
        Node* pNextNode = pCurrent->pNext;

        // Encontra a posição correta para inserir o nó atual na lista ordenada
        // Pega o elemento pCurrent e busca onde deve ser insere na sublista ordenada
        Node* pSortedCurrent = pSorted;
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
                Node* pLastNode = pSorted;
                while (pLastNode->pNext != nullptr) {
                    pLastNode = pLastNode->pNext;
                }
                pLastNode->pNext = pCurrent;
                pCurrent->pPrev = pLastNode;
                pCurrent->pNext = nullptr;
            }
        } else {
            // O nó atual deve ser inserido antes de pSortedCurrent
            Node* pPrevNode = pSortedCurrent->pPrev;

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
    Node* pLastNode = pSorted;
    while (pLastNode->pNext != nullptr) {
        pLastNode = pLastNode->pNext;
    }
    *ppTail = pLastNode;
}


// =============== Terceira Parte ===============
// main apenas para testar as funções
// Não é necessário implementar nada aqui

int main() {
    Node* pHead = nullptr;
    Node* pTail = nullptr;

    insertBack(&pHead, &pTail, 8);
    insertBack(&pHead, &pTail, 3);
    insertBack(&pHead, &pTail, 2);
    insertBack(&pHead, &pTail, 5);
    insertBack(&pHead, &pTail, 7);
    insertBack(&pHead, &pTail, 4);
    insertBack(&pHead, &pTail, 1);
    insertBack(&pHead, &pTail, 6);

    printList(pHead);

    //swap(&pHead, &pTail, pHead->pNext->pNext, pTail->pPrev->pPrev);

    //bubbleSort(&pHead, &pTail);
    //selectionSort(&pHead, &pTail);
    insertionSort(&pHead, &pTail);

    printList(pHead);
}