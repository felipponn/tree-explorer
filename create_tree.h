#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

////////////////////////////////////////////////////////////////////////////////
/*                         Função que cria um novo nó                         */
////////////////////////////////////////////////////////////////////////////////

// Cria um novo nó
struct Node* newNode(int iData)
{
    struct Node* newNode = new Node;
    newNode->iPayload = iData;
    newNode->ptrLeft = nullptr;
    newNode->ptrRight = nullptr;
    return newNode;
}

////////////////////////////////////////////////////////////////////////////////
/*                  Função que insere um novo nó na árovre                    */
////////////////////////////////////////////////////////////////////////////////

// Insere um novo nó na árvore
struct Node* insertNode(struct Node* node, int iData)
{
    if (node == nullptr) return newNode(iData);
    // Sempre que o valor a ser inserido for menor que o valor do nó atual, o 
    // valor será inserido à esquerda por recursão
    else if (iData < node->iPayload) node->ptrLeft = insertNode(node->ptrLeft, iData);
    // Caso contrário, o valor será inserido à direita por recursão
    else node->ptrRight = insertNode(node->ptrRight, iData);
    return node;
}

////////////////////////////////////////////////////////////////////////////////
/*                  Funções que percorrem a árvore binária                    */
////////////////////////////////////////////////////////////////////////////////

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

/*----------------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------------*/

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

////////////////////////////////////////////////////////////////////////////////
/*                   Função que deleta um nó da árvore                        */
////////////////////////////////////////////////////////////////////////////////

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
        // Se o nó tiver apenas um filho (à direita), o nó será deletado e o 
        // filho ocupará seu lugar
        else if (node->ptrLeft == nullptr)
        {
            struct Node* ptrTemp = node;
            node = node->ptrRight;
            free(ptrTemp);
        }
        // Se o nó tiver apenas um filho (à esquerda), o nó será deletado e o 
        // filho ocupará seu lugar
        else if (node->ptrRight == nullptr)
        {
            struct Node* ptrTemp = node;
            node = node->ptrLeft;
            free(ptrTemp);
        }
        // Se o nó tiver dois filhos, o nó será deletado e o menor valor da 
        // sub-árvore à direita ocupará seu lugar (o menor valor da sub-árvore à 
        // direita é o valor mais à esquerda da sub-árvore à direita)
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

////////////////////////////////////////////////////////////////////////////////
/*                  Função que busca um nó na árvore binária                  */
////////////////////////////////////////////////////////////////////////////////

// Busca o endereço de memória de um nó na árvore
struct Node* searchNode(struct Node* node, int iData)
{
    if (node == nullptr) return nullptr;
    // Se o valor a ser buscado for igual ao valor do nó atual, o endereço de 
    // memória do nó atual será retornado
    else if (iData == node->iPayload) return node;
    // Se o valor a ser buscado for menor que o valor do nó atual, a busca será 
    // feita à esquerda por recursão
    else if (iData < node->iPayload) return searchNode(node->ptrLeft, iData);
    // Caso contrário, a busca será feita à direita por recursão
    else return searchNode(node->ptrRight, iData);
}

////////////////////////////////////////////////////////////////////////////////
/*   Função que constrói uma árvore binária a partir de um arquivo de texto   */
////////////////////////////////////////////////////////////////////////////////

// Constrói uma árvore binária de busca a partir de um arquivo texto
struct Node* constructTreeFromFile(const string& strFileName)
{
    // Abre o arquivo
    ifstream inputFile(strFileName);
    // Se o arquivo não puder ser aberto, uma mensagem de erro será exibida
    if (!inputFile.is_open())
    {
        cout << "Erro ao abrir o arquivo " << strFileName << endl;
        return nullptr;
    }
    struct Node* ptrRoot = nullptr;
    int iData;
    // Lê os dados do arquivo e insere-os na árvore
    while (inputFile >> iData)
    {
        ptrRoot = insertNode(ptrRoot, iData);
    }
    // Fecha o arquivo
    inputFile.close();
    return ptrRoot;
}

////////////////////////////////////////////////////////////////////////////////
/*   Função que constrói uma árvore binária com dados inseridos pelo usuário  */
////////////////////////////////////////////////////////////////////////////////

// Constrói uma árvore binária de busca a partir de dados inseridos pelo usuário
struct Node* constructTreeFromUserInput()
{
    struct Node* ptrRoot = nullptr;
    int iData;
    // Lê os dados inseridos pelo usuário e insere-os na árvore
    while (true)
    {
        cout << "Digite um valor inteiro (0 para sair): ";
        cin >> iData;
        // Se o valor inserido for 0, o programa pergunta se o usuário realmente 
        // deseja sair. Se a resposta for sim, o programa é encerrado. Caso 
        // contrário, o programa volta a pedir um valor
        if (iData == 0)
        {
            cout << "Você realmente deseja sair? (S/s): ";
            char cAnswer;
            cin >> cAnswer;
            if (cAnswer == 'S' || cAnswer == 's') break;
        }
        // Se o usuário não quiser sair, o 0 será inserido na árvore
        ptrRoot = insertNode(ptrRoot, iData);
    }
    return ptrRoot;
}