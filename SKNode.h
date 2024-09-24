#ifndef SKNODE_H_INCLUDED
#define SKNODE_H_INCLUDED

#include "DynamicArray.h"

template <typename T>
struct SKNode {
    T value;
    DynamicArray<SKNode*> forward;

    SKNode(int level, T val) : value(val), forward(level + 1) {
        for (int i = 0; i <= level; ++i) {
            forward[i] = nullptr;
        }
    }
};

#endif // SKNODE_H_INCLUDED
