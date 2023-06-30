#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <chrono>
// #include "create_tree.h"
#include "struct_node.h"

using namespace std;

void tela();

void transicao();

void tempoExec(chrono::duration<double, milli> timeDuration);

bool escolha(struct Node **ptrRoot);

#endif