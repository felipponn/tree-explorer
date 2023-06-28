# include <iostream>

using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

int height(struct Node* node)
{
    if (node == nullptr) // caso base
        return 0;
    else
        return 1 + max(height(node->ptrLeft), height(node->ptrRight)); // calcula a altura da subárvore esquerda e direita
}

int size(struct Node* node)
{
    if (node == nullptr) // caso base
        return 0;
    else
        return 1 + size(node->ptrLeft) + size(node->ptrRight); // calcula o tamanho da subárvore esquerda e direita
}

bool complete(struct Node* node)
{
    if (node->ptrRight == nullptr || node->ptrLeft == nullptr) // caso base
        if (node->ptrRight == nullptr && node->ptrLeft == nullptr) // verifica se o nó é folha
            return true;
        else
            return false;
    return complete(node->ptrLeft) && complete(node->ptrRight); // verifica se a subárvore esquerda e direita são completas
}

bool perfect(struct Node* node)
{
    if (node == nullptr) // caso base
        return true;
    else if (height(node->ptrLeft) == height(node->ptrRight)) // verifica se a altura da subárvore esquerda é igual a da direita
        return perfect(node->ptrLeft) && perfect(node->ptrRight); // verifica se a subárvore esquerda e direita são perfeitas
    else
        return false;
}