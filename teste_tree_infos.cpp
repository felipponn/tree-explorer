#include<iostream>
#include"create_tree.h"
#include"tree_infos.h"

using namespace std;

// ========================================================================= //
// -------------------------------  TESTE ----------------------------------
// Arquivo para testar as funções de informações de árvores
// As principais funções da tree_infos.h são:
// - height: calcula a altura de uma árvore
// - size: calcula o tamanho de uma árvore
// - full: verifica se uma árvore é cheia
// - perfect: verifica se uma árvore é perfeita
// - complete: verifica se uma árvore é completa
// ========================================================================= //


int main()
{
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando a funcao que calcula a altura de uma arvore: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    struct Node* ptrRoot = nullptr;
    ptrRoot = insertNode(ptrRoot, 10);
    ptrRoot = insertNode(ptrRoot, 5);
    ptrRoot = insertNode(ptrRoot, 15);
    ptrRoot = insertNode(ptrRoot, 3);
    ptrRoot = insertNode(ptrRoot, 7);
    ptrRoot = insertNode(ptrRoot, 13);
    ptrRoot = insertNode(ptrRoot, 17);
    ptrRoot = insertNode(ptrRoot, 2);
    ptrRoot = insertNode(ptrRoot, 4);
    ptrRoot = insertNode(ptrRoot, 6);
    ptrRoot = insertNode(ptrRoot, 8);
    ptrRoot = insertNode(ptrRoot, 12);
    ptrRoot = insertNode(ptrRoot, 14);
    ptrRoot = insertNode(ptrRoot, 16);
    ptrRoot = insertNode(ptrRoot, 18);

    cout << "Arvore: ";
    traversePreOrder(ptrRoot);
    cout << endl;

    cout << "Altura da arvore: " << height(ptrRoot) << endl;

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando a funcao que calcula o tamanho de uma arvore: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    cout << "Tamanho da arvore: " << size(ptrRoot) << endl;

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando a funcao que verifica se uma arvore eh cheia: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    cout << "Arvore: ";
    traversePreOrder(ptrRoot);
    cout << endl;

    if (full(ptrRoot)) cout << "A arvore eh cheia" << endl;
    else cout << "A arvore nao eh cheia" << endl;

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando a funcao que verifica se uma arvore eh perfeita: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    cout << "Arvore: ";
    traversePreOrder(ptrRoot);
    cout << endl;

    if (perfect(ptrRoot)) cout << "A arvore eh perfeita" << endl;
    else cout << "A arvore nao eh perfeita" << endl;

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Testando a funcao que verifica se uma arvore eh completa: " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    cout << "Arvore: ";
    traversePreOrder(ptrRoot);
    cout << endl;

    if (complete(ptrRoot)) cout << "A arvore eh completa" << endl;
    else cout << "A arvore nao eh completa" << endl;

    return 0;
}