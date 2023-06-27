#include <iostream>

using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

// Cria um novo nó
struct Node* newNode(int iData)
{
    struct Node* newNode = new Node;
    newNode->iPayload = iData;
    newNode->ptrLeft = nullptr;
    newNode->ptrRight = nullptr;

    return newNode;
}

// Insere um novo nó na árvore
struct Node* insertNode(struct Node* node, int iData)
{
    if (node == nullptr) return newNode(iData);
    // Sempre que o valor a ser inserido for menor que o valor do nó atual, o valor
    // será inserido à esquerda por recursão
    else if (iData < node->iPayload) node->ptrLeft = insertNode(node->ptrLeft, iData);
    // Caso contrário, o valor será inserido à direita por recursão
    else node->ptrRight = insertNode(node->ptrRight, iData);
    return node;
}

// Percorre a árvore com pré-ordem
void traversePreOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        // Imprime o valor do nó atual
        cout << " " << ptrStartingNode->iPayload;
        // Percorre a sub-árvore à esquerda até o fim
        traversePreOrder(ptrStartingNode->ptrLeft);
        // Percorre a sub-árvore à direita até o fim
        traversePreOrder(ptrStartingNode->ptrRight);
    }
}

// Percorre a árvore em ordem
void traverseInOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        // Percorre a sub-árvore à esquerda até o fim
        traverseInOrder(ptrStartingNode->ptrLeft);
        // Imprime o valor do nó atual
        cout << " " << ptrStartingNode->iPayload;
        // Percorre a sub-árvore à direita até o fim
        traverseInOrder(ptrStartingNode->ptrRight);
    }
}

// Percorre a árvore com pós-ordem
void traversePostOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        // Percorre a sub-árvore à esquerda até o fim
        traversePostOrder(ptrStartingNode->ptrLeft);
        // Percorre a sub-árvore à direita até o fim
        traversePostOrder(ptrStartingNode->ptrRight);
        // Imprime o valor do nó atual
        cout << " " << ptrStartingNode->iPayload;
    }
}