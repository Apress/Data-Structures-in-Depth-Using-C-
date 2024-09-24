#ifndef DNODE_H_INCLUDED
#define DNODE_H_INCLUDED

#include "Node.h"

template <class T>
struct DNode : public Node<T> {
    DNode* prev;
    DNode* next;

    DNode() : Node<T>(),
        prev(nullptr), next(nullptr){}
    DNode(const T& item) : Node<T>(item),
        prev(nullptr), next(nullptr){}
};

#endif // DNODE_H_INCLUDED
