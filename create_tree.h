#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

// Cria um novo nó
struct Node* newNode(int iData);

// Insere um novo nó na árvore
struct Node* insertNode(struct Node* node, int iData);

// Percorre a árvore com pré-ordem
void traversePreOrder(struct Node* ptrStartingNode);

// Percorre a árvore em ordem
void traverseInOrder(struct Node* ptrStartingNode);

// Percorre a árvore com pós-ordem
void traversePostOrder(struct Node* ptrStartingNode);

// Deleta um nó da árvore
struct Node* deleteNode(struct Node* node, int iData);

// Busca o endereço de memória de um nó na árvore
struct Node* searchNode(struct Node* node, int iData);

// Constrói uma árvore binária de busca a partir de um arquivo texto
struct Node* constructTreeFromFile(const string& strFileName);

// Constrói uma árvore binária de busca a partir de dados inseridos pelo usuário
struct Node* constructTreeFromUserInput();