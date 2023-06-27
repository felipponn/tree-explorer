#include <iostream>
using namespace std;

// =============== Primeira Parte ===============
// Funções para criar a lista, inserir elementos e imprimir a lista


// Estrutura do nó da lista
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Função para criar um novo nó
Node* create_node(int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->prev = nullptr;
    new_node->next = nullptr;
    return new_node;
}

// Função para inserir um novo nó no final da lista
void insert_back(Node** head, Node** tail, int data) {
    Node* new_node = create_node(data);
    if (*head == nullptr) {
        *head = new_node;
    } else {
        (*tail)->next = new_node;
        new_node->prev = *tail;
    }
    *tail = new_node;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    cout << endl;
}



// =============== Terceira Parte ===============
// main apenas para testar as funções
// Não é necessário implementar nada aqui

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    insert_back(&head, &tail, 8);
    insert_back(&head, &tail, 3);
    insert_back(&head, &tail, 2);
    insert_back(&head, &tail, 5);
    insert_back(&head, &tail, 7);
    insert_back(&head, &tail, 4);
    insert_back(&head, &tail, 1);
    insert_back(&head, &tail, 6);

    printList(head);
}