#ifndef DEQUELL_H_INCLUDED
#define DEQUELL_H_INCLUDED

#include "DLList.h"

template <typename T>
class DequeLL : public DLList<T> {
public:
    DequeLL() : DLList<T>() {}
    virtual ~DequeLL(){}

    // Deque-specific functions
    virtual void enqueueFront(const T item) {
        this->pushFront(item);
    }
    virtual T dequeueFront() {
        return this->popFront();
    }
    virtual void enqueueRear(const T item) {
        this->pushBack(item);
    }
    virtual T dequeueRear() {
        return this->popBack();
    }
};

#endif // DEQUELL_H_INCLUDED
