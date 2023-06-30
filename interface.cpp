#include <iostream>
#include "create_tree.cpp"
#include "tree_infos.cpp"
#include "BFS.cpp"

using namespace std;

void tela()
{
    string strTelaInicio = 
    " _________________________________________________________________________________\n/\\                                                                                \\\n\\_|   ___________ _____ _____   _______   ________ _     ___________ ___________  |\n  |  |_   _| ___ \\  ___|  ___| |  ___\\ \\ / /| ___ \\ |   |  _  | ___ \\  ___| ___ \\ |\n  |    | | | |_/ / |__ | |__   | |__  \\ V / | |_/ / |   | | | | |_/ / |__ | |_/ / |\n  |    | | |    /|  __||  __|  |  __| /   \\ |  __/| |   | | | |    /|  __||    /  |\n  |    | | | |\\ \\| |___| |___  | |___/ /^\\ \\| |   | |___\\ \\_/ / |\\ \\| |___| |\\ \\  |\n  |    \\_/ \\_| \\_\\____/\\____/  \\____/\\/   \\/\\_|   \\_____/\\___/\\_| \\_\\____/\\_| \\_| |\n  |   ____________________________________________________________________________|_\n   \\_/_____________________________________________________________________________/";
    string strOpcoes = "\t*---------------------------------------*----------------------------------------*\n\t|                              0 - Sair do programa                              |\n\t*---------------------------------------*----------------------------------------*\n\t| 1 - Criar BST a partir de .txt        | 6 - Remova um dado da arvore           |\n\t| 2 - Digite dados para criar uma BST   | 7 - Retornar o endereco de um elemento |\n\t| 3 - Retornar a altura da arvore       | 8 - Retornar se a arvore eh completa   |\n\t| 4 - Retornar o tamanho da arvore      | 9 - Retornar se a arvore eh perfeita   |\n\t| 5 - Insira um novo dado na arvore     | 10 - Exibir a arvore BFS               |\n\t*---------------------------------------*----------------------------------------*\n\t| 11 - Fazer a travessia da arvore (escolha a ordem)                             |\n\t*---------------------------------------*----------------------------------------*\n\t| 12 - Converter a arvore em lista e ordenar (escolher algoritmo)                |\n\t*--------------------------------------------------------------------------------*";
    cout << strTelaInicio << endl;
    cout << "           |                      INSIRA A OPERACAO DESEJADA                  |" << endl;
    cout << "           \\__________________________________________________________________/" << endl;
    cout << strOpcoes << endl;
}

void transicao()
{
    cout << "Pressione Enter para continuar..." << endl;
    cin.ignore();
    cin.get();
}

bool escolha(struct Node **ptrRoot)
{
    int iOpcao, iData;
    string strFileName, strConfirma;
    cin >> iOpcao;
    switch (iOpcao)
    {
    case 0:
        cout << "Opcao 0 - Sair" << endl;
        cout << "Digite SAIR para confirmar" << endl;
        cin >> strConfirma;
        if (strConfirma == "SAIR")
        {
            cout << "Saindo..." << endl;
            transicao();
            return true;
        }
        else
        {
            cout << "Operacao cancelada." << endl;
            transicao();
            return false;
        }
    case 1:
        cout << "Opcao 1 - Criar BST a partir de .txt" << endl;
        cout << "Insira o nome do arquivo:" << endl;
        cin >> strFileName;
        *ptrRoot = constructTreeFromFile(strFileName);
        if (ptrRoot != nullptr)
        {
            cout << "Arvore criada com sucesso!" << endl;
            transicao();
        }
        else
        {
            cout << "Erro ao criar arvore." << endl;
            transicao();
        }
        return false;
    case 2:
        cout << "Opcao 2 - Digite dados para criar uma BST" << endl;
        *ptrRoot = constructTreeFromUserInput();
        cout << "Arvore criada com sucesso!" << endl;
        transicao();
        return false;
    case 3:
        cout << "Opcao 3 - Retornar a altura da arvore" << endl;
        cout << "Altura da arvore: " << height(*ptrRoot) << endl;
        transicao();
        return false;
    case 4:
        cout << "Opcao 4 - Retornar o tamanho da arvore" << endl;
        cout << "Tamanho da arvore: " << size(*ptrRoot) << endl;
        transicao();
        return false;
    case 5:
        cout << "Opcao 5 - Insira um novo dado na arvore" << endl;
        cout << "Insira o dado:" << endl;
        cin >> iData;
        *ptrRoot = insertNode(*ptrRoot, iData);
        cout << "Dado inserido com sucesso!" << endl;
        transicao();
        return false;
    case 6:
        cout << "Opcao 6 - Remova um dado da arvore" << endl;
        cout << "Insira o dado:" << endl;
        cin >> iData;
        *ptrRoot = deleteNode(*ptrRoot, iData);
        cout << "Dado removido com sucesso!" << endl;
        transicao();
        return false;
    case 7:
        cout << "Opcao 7 - Retornar o endereco de um elemento" << endl;
        cout << "Insira o dado:" << endl;
        cin >> iData;
        if (searchNode(*ptrRoot, iData) == 0)
            cout << "Dado nao encontrado." << endl;
        else
            cout << "Endereco do dado: " << searchNode(*ptrRoot, iData) << endl;
        transicao();
        return false;
    case 8:
        cout << "Opcao 8 - Retornar se a arvore eh completa" << endl;
        if (complete(*ptrRoot))
            cout << "A arvore eh completa." << endl;
        else
            cout << "A arvore nao eh completa." << endl;
        transicao();
        return false;
    case 9:
        cout << "Opcao 9 - Retornar se a arvore eh perfeita" << endl;
        if (perfect(*ptrRoot))
            cout << "A arvore eh perfeita." << endl;
        else
            cout << "A arvore nao eh perfeita." << endl;
        transicao();
        return false;
    case 10:
        cout << "Opção 10 - Exibir a arvore BFS" << endl;
        printTreeBFS(*ptrRoot);
        transicao();
        return false;
    case 11:
        cout << "Opcao 11 - Fazer a travessia da arvore (escolha a ordem)" << endl;
        cout << "Insira a ordem desejada:" << endl;
        cout << "0 - Pre-ordem" << endl;
        cout << "1 - In-ordem" << endl;
        cout << "2 - Pos-ordem" << endl;
        cin >> iData;
        switch (iData)
        {
        case 0:
            cout << "Pre-ordem:" << endl;
            traversePreOrder(*ptrRoot);
            cout << endl;
            break;
        case 1:
            cout << "In-ordem:" << endl;
            traverseInOrder(*ptrRoot);
            cout << endl;
            break;
        case 2:
            cout << "Pos-ordem:" << endl;
            traversePostOrder(*ptrRoot);
            cout << endl;
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
        }
        transicao();
        return false;
    case 12:
        cout << "Opcao 12 - Converter a arvore em lista e ordenar (escolher algoritmo)" << endl;
        return false;
    default:
        cout << "Opcao invalida" << endl;
        return false;
    }
}