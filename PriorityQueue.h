#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include "PQNode.h"
#include "BinaryHeap.h"
#include <iostream>

template <typename T>
class PriorityQueue {
public:
    PriorityQueue();
    ~PriorityQueue();

    // Inserts a new element into the priority queue
    void add(const T& data, int priority);

    // Removes the element from queue
    void remove(const T& data);

    // Removes the highest priority element
    T pop();

    // Returns the highest priority element
    T peek() const;

    // Checks if the priority queue is empty
    bool isEmpty() const;

    // Clears all elements in the priority queue
    void clear();

    // Prints all elements in the priority queue
    void print() const;

    bool contains(const T x) const;

    size_t getSize() const {
        return heap.getSize();
    }
private:
    BinaryHeap<PQNode<T>> heap;
};


template <typename T>
PriorityQueue<T>::PriorityQueue()
    : heap(HeapType::MAX_HEAP) {} // Initialize max-heap

template <typename T>
PriorityQueue<T>::~PriorityQueue() {}

template <typename T>
void PriorityQueue<T>::add(const T& data, int priority) {
    PQNode<T> node(data, priority);
    heap.add(node);
}

template <typename T>
T PriorityQueue<T>::pop() {
    assert(!isEmpty() && "Priority queue is empty");
    T val = heap.peek().data;
    heap.deleteRoot();
    return val;
}

template <typename T>
T PriorityQueue<T>::peek() const {
    assert(!isEmpty() && "Priority queue is empty");
    return heap.peek().data;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const {
    return heap.getSize() == 0;
}

template <typename T>
void PriorityQueue<T>::clear() {
    heap.clear();
}

template <typename T>
void PriorityQueue<T>::print() const {
    heap.print();
}

template <typename T>
bool PriorityQueue<T>::contains(const T x) const {
    // Priority queue doesn't naturally support searching by value
    return false;
}

/** NOT IN BOOK */
template <typename T>
void PriorityQueue<T>::remove(const T& data) {
    heap.remove(data);
}
#endif // PRIORITYQUEUE_H_INCLUDED
