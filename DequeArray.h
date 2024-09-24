#ifndef DEQUEARRAY_H_INCLUDED
#define DEQUEARRAY_H_INCLUDED

#include "DynamicArray.h"

template <typename T>
class DequeArray : public DynamicArray<T> {
public:
    DequeArray() : DynamicArray<T>(),
                front(0), rear(0) {}
    virtual ~DequeArray(){}
    // Deque-specific functions
    virtual void enqueueFront(const T item);
    virtual T dequeueFront();
    virtual void enqueueRear(const T item);
    virtual T dequeueRear();
    // ... Other relevant functions
    virtual void print() const;
    virtual void resize();
protected:
    size_t front;
    size_t rear;

    // Inherited members to use directly
    using DynamicArray<T>::size;
    using DynamicArray<T>::capacity;
    using DynamicArray<T>::arr;
};

template <typename T>
void DequeArray<T>::enqueueFront(const T item) {
    this->insertAt(0, item);
}

template <typename T>
T DequeArray<T>::dequeueFront() {
    T item = arr[front];
    this->removeAt(0);
    return item;
}

template <typename T>
void DequeArray<T>::enqueueRear(const T item) {
    this->insertAt(size, item);
}

template <typename T>
T DequeArray<T>::dequeueRear() {
    T item = arr[rear];
    this->removeAt(size - 1);
    return item;
}

/*
template <typename T>
void DequeArray<T>::enqueueFront(const T item) {
    if (this->size+1 > this->capacity)
        resize();
    // decrement front position circularly
    front = (front == 0) ? this->capacity - 1 : front - 1;
    this->arr[front] = item;
    ++this->size;
}

template <typename T>
T DequeArray<T>::dequeueFront() {
    assert(this->size > 0);
    T item = this->arr[front];
    front = (front + 1) % this->capacity;
    --this->size;
    if (3 * this->size < this->capacity)
        resize();
    return item;
}

template <typename T>
void DequeArray<T>::enqueueRear(const T item) {
    if (this->size+1 > this->capacity)
        resize();
    // calc rear position
    size_t rear =(front + this->size)%this->capacity;
    this->arr[rear] = item;
    ++this->size;
}

template <typename T>
T DequeArray<T>::dequeueRear() {
    assert(this->size > 0);
    size_t rear = (front+this->size-1)%this->capacity;
    T item = this->arr[rear];
    --this->size;
    if (3 * this->size < this->capacity)
        resize();
    return item;
}*/

/***
NOT IN BOOK
***/
template <typename T>
void DequeArray<T>::resize() {
    size_t new_capacity = std::max(2 * static_cast<int>(this->size), 2);
    T* brr = new T[new_capacity];
    for (size_t i = 0; i < this->size; i++) {
        brr[i] = this->arr[(front + i) % this->capacity];
    }
    delete[] this->arr;
    this->arr = brr;
    this->capacity = new_capacity;
    front = 0;
    rear = this->size-1;
}

template <typename T>
void DequeArray<T>::print() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[(front + i) % capacity] << " ";
    }
    std::cout << std::endl;
}

#endif // DEQUEARRAY_H_INCLUDED
