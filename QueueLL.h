#ifndef QUEUELL_H_INCLUDED
#define QUEUELL_H_INCLUDED

#include "SinglyLLTailed.h"

template <typename T>
class QueueLL : public SinglyLLTailed<T> {
public:
    QueueLL() : SinglyLLTailed<T>() {}
    virtual ~QueueLL(){}

    // Queue-specific functions
    virtual void enqueue(const T item) {
        this->pushBack(item);
    }
    virtual T dequeue() {
        return this->popFront();
    }
};

#endif // QUEUELL_H_INCLUDED
