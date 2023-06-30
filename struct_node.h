#ifndef STRUCT_NODE_H
#define STRUCT_NODE_H
struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};
#endif