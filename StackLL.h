#ifndef STACKLL_H_INCLUDED
#define STACKLL_H_INCLUDED

#include "SinglyLL.h"

template <typename T>
class StackLL : public SinglyLL<T> {
public:
    StackLL() : SinglyLL<T>() {}
    virtual ~StackLL(){}

    // Stack-specific functions
    virtual void push(const T item) {
        this->pushFront(item);
    }
    virtual T pop() {
        return this->popFront();
    }
};

#endif // STACKLL_H_INCLUDED
