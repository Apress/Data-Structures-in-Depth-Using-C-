#ifndef STACKARRAY_H_INCLUDED
#define STACKARRAY_H_INCLUDED

#include "DynamicArray.h"

template <typename T>
class StackArray : public DynamicArray<T> {
public:
    StackArray() : DynamicArray<T>() {}
    virtual ~StackArray(){}

    // Stack-specific functions
    virtual void push(const T item) {
        this->pushBack(item);
    }
    virtual T pop() {
        return this->popBack();
    }
};

#endif // STACKARRAY_H_INCLUDED
