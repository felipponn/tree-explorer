#include <iostream>
#include <chrono>
#include "create_tree.h"

void tela();

void transicao();

void tempoExec(chrono::duration<double, milli> timeDuration);

bool escolha(struct Node **ptrRoot);