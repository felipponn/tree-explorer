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

// Deleta um nó da árvore
struct Node* deleteNode(struct Node* node, int iData)
{
    if (node == nullptr) return node;
    // Se o valor a ser deletado for menor que o valor do nó atual, o valor
    // será deletado à esquerda por recursão
    else if (iData < node->iPayload) node->ptrLeft = deleteNode(node->ptrLeft, iData);
    // Caso contrário, o valor será deletado à direita por recursão
    else if (iData > node->iPayload) node->ptrRight = deleteNode(node->ptrRight, iData);
    // Se o valor a ser deletado for igual ao valor do nó atual, o nó será deletado
    else
    {
        // Se o nó não tiver filhos, ele será deletado
        if (node->ptrLeft == nullptr && node->ptrRight == nullptr)
        {
            free(node);
            node = nullptr;
        }
        // Se o nó tiver apenas um filho (à direita), o nó será deletado e o filho
        // ocupará seu lugar
        else if (node->ptrLeft == nullptr)
        {
            struct Node* ptrTemp = node;
            node = node->ptrRight;
            free(ptrTemp);
        }
        // Se o nó tiver apenas um filho (à esquerda), o nó será deletado e o filho
        // ocupará seu lugar
        else if (node->ptrRight == nullptr)
        {
            struct Node* ptrTemp = node;
            node = node->ptrLeft;
            free(ptrTemp);
        }
        // Se o nó tiver dois filhos, o nó será deletado e o menor valor da sub-árvore
        // à direita ocupará seu lugar (o menor valor da sub-árvore à direita é o
        // valor mais à esquerda da sub-árvore à direita)
        else
        {
            struct Node* temp = node->ptrRight;
            while (temp->ptrLeft != nullptr) temp = temp->ptrLeft;
            node->iPayload = temp->iPayload;
            node->ptrRight = deleteNode(node->ptrRight, temp->iPayload);
        }
    }
    return node;
}