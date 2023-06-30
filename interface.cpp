#include <iostream>

using namespace std;

void tela()
{
    string strTelaInicio = 
    " _________________________________________________________________________________\n/\\                                                                                \\\n\\_|   ___________ _____ _____   _______   ________ _     ___________ ___________  |\n  |  |_   _| ___ \\  ___|  ___| |  ___\\ \\ / /| ___ \\ |   |  _  | ___ \\  ___| ___ \\ |\n  |    | | | |_/ / |__ | |__   | |__  \\ V / | |_/ / |   | | | | |_/ / |__ | |_/ / |\n  |    | | |    /|  __||  __|  |  __| /   \\ |  __/| |   | | | |    /|  __||    /  |\n  |    | | | |\\ \\| |___| |___  | |___/ /^\\ \\| |   | |___\\ \\_/ / |\\ \\| |___| |\\ \\  |\n  |    \\_/ \\_| \\_\\____/\\____/  \\____/\\/   \\/\\_|   \\_____/\\___/\\_| \\_\\____/\\_| \\_| |\n  |   ____________________________________________________________________________|_\n   \\_/_____________________________________________________________________________/";
    string strOpcoes = "\t*---------------------------------------*----------------------------------------*\n\t| 1 - Criar BST a partir de .txt        | 6 - Remova um dado da árvore           |\n\t| 2 - Digite dados para criar uma BST   | 7 - Retornar o endereço de um elemento |\n\t| 3 - Retornar a altura da árvore       | 8 - Retornar se a árvore é completa    |\n\t| 4 - Retornar o tamanho da árvore      | 9 - Retornar se a árvore é perfeita    |\n\t| 5 - Insira um novo dado na árvore     | 10 - Exibir a árvore BFS               |\n\t*---------------------------------------*----------------------------------------*\n\t| 11 - Converter a árvore em lista e ordenar (escolher algoritmo)                |\n\t*--------------------------------------------------------------------------------*";
    cout << strTelaInicio << endl;
    cout << "           |                      INSIRA A OPERAÇÃO DESEJADA                  |" << endl;
    cout << "           \\__________________________________________________________________/" << endl;
    cout << strOpcoes << endl;
}

bool escolha()
{
    int iOpcao;
    cin >> iOpcao;
    switch (iOpcao)
    {
    case 0:
        cout << "Opção 0 - Sair" << endl;
        return true;
    case 1:
        cout << "Opção 1 - Criar BST a partir de .txt" << endl;
        return false;
    case 2:
        cout << "Opção 2 - Digite dados para criar uma BST" << endl;
        return false;
    case 3:
        cout << "Opção 3 - Retornar a altura da árvore" << endl;
        return false;
    case 4:
        cout << "Opção 4 - Retornar o tamanho da árvore" << endl;
        return false;
    case 5:
        cout << "Opção 5 - Insira um novo dado na árvore" << endl;
        return false;
    case 6:
        cout << "Opção 6 - Remova um dado da árvore" << endl;
        return false;
    case 7:
        cout << "Opção 7 - Retornar o endereço de um elemento" << endl;
        return false;
    case 8:
        cout << "Opção 8 - Retornar se a árvore é completa" << endl;
        return false;
    case 9:
        cout << "Opção 9 - Retornar se a árvore é perfeita" << endl;
        return false;
    case 10:
        cout << "Opção 10 - Exibir a árvore BFS" << endl;
        return false;
    case 11:
        cout << "Opção 11 - Converter a árvore em lista e ordenar (escolher algoritmo)" << endl;
        return false;
    default:
        cout << "Opção inválida" << endl;
        return false;
    }
}