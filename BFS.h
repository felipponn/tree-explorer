#ifndef BFS_H
#define BFS_H
#include <iostream>

struct queueNode
{
    struct Node *ptrNode;
    struct queueNode *ptrNext;
};

struct queue
{
    struct queueNode *ptrFront;
    struct queueNode *ptrRear;
};

struct queueNode *newQueueNode(struct Node *ptrNode);

struct queue *createQueue();

void enqueue(struct queue *ptrQueue, struct Node *ptrNode);

struct Node *dequeue(struct queue *ptrQueue);

bool isQueueEmpty(struct queue *ptrQueue);

void printTreeBFS(struct Node *ptrRoot);

#endif