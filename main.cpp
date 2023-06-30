#include <iostream>
#include "interface.cpp"

using namespace std;

int main()
{
    bool bExit = false;
    struct Node *ptrRoot = nullptr;
    while (!bExit)
    {
        tela();
        bExit = escolha(ptrRoot);
    }
    return 0;
}