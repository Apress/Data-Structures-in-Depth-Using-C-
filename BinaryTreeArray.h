#ifndef BINARYTREEARRAY_H_INCLUDED
#define BINARYTREEARRAY_H_INCLUDED

#include "DynamicArray.h"

template<typename T>
class BinaryTreeArray : public DynamicArray<T> {
public:
    BinaryTreeArray(size_t initialCapacity = 8)
        : DynamicArray<T>(initialCapacity) {}

    T getLeftChild(size_t index) {
        size_t leftIndex = 2 * index + 1;
        return (leftIndex < this->capacity) ?
                 this->get(leftIndex) : T();
    }

    T getRightChild(size_t index) {
        size_t rightIndex = 2 * index + 2;
        return (rightIndex < this->capacity) ?
                 this->get(rightIndex) : T();
    }

    T getParent(size_t index) {
        return (index == 0) ?
                T() : this->get((index - 1) / 2);
    }
};

#endif // BINARYTREEARRAY_H_INCLUDED
