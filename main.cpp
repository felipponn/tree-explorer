#include <iostream>
#include "interface.cpp"
#include "create_tree.cpp"

using namespace std;

int main()
{
    bool bExit = false;
    while (!bExit)
    {
        tela();
        bExit = escolha();
    }
    return 0;
}