#include <iostream>
#include "struct_node.h"

using namespace std;

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

struct queueNode *newQueueNode(struct Node *ptrNode)
{
    struct queueNode *ptrNewQueueNode = (struct queueNode*)malloc(sizeof(queueNode));
    ptrNewQueueNode->ptrNode = ptrNode;
    ptrNewQueueNode->ptrNext = nullptr;
    return ptrNewQueueNode;
}

struct queue *createQueue()
{
    struct queue *ptrQueue = (struct queue*)malloc(sizeof(queue));
    ptrQueue->ptrFront = nullptr;
    ptrQueue->ptrRear = nullptr;
    return ptrQueue;
}

void enqueue(struct queue *ptrQueue, struct Node *ptrNode)
{
    struct queueNode *ptrNewQueueNode = newQueueNode(ptrNode);
    if (ptrQueue->ptrRear == nullptr)
    {
        ptrQueue->ptrFront = ptrNewQueueNode;
        ptrQueue->ptrRear = ptrNewQueueNode;
    }
    else
    {
        ptrQueue->ptrRear->ptrNext = ptrNewQueueNode;
        ptrQueue->ptrRear = ptrNewQueueNode;
    }
}

struct Node *dequeue(struct queue *ptrQueue)
{
    if (ptrQueue->ptrFront == nullptr) return nullptr;
    struct queueNode *ptrTemp = ptrQueue->ptrFront;
    struct Node *ptrRet = ptrTemp->ptrNode;
    ptrQueue->ptrFront = ptrQueue->ptrFront->ptrNext;
    if (ptrQueue->ptrFront == nullptr) ptrQueue->ptrRear = nullptr;
    free(ptrTemp);
    return ptrRet;
}

bool isQueueEmpty(struct queue *ptrQueue)
{
    return (ptrQueue->ptrFront == nullptr);
}

void printTreeBFS(struct Node *ptrRoot)
{
    struct queue *ptrQueue = createQueue();
    enqueue(ptrQueue, ptrRoot);
    while (!isQueueEmpty(ptrQueue))
    {
        struct Node *ptrCurr = dequeue(ptrQueue);
        int iCurrent = ptrCurr->iPayload;
        cout << " " << iCurrent;
        if (ptrCurr->ptrLeft != nullptr) enqueue(ptrQueue, ptrCurr->ptrLeft);
        if (ptrCurr->ptrRight != nullptr) enqueue(ptrQueue, ptrCurr->ptrRight);
    }
    cout << endl;
}