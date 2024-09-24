#ifndef QUEUEARRAY_H_INCLUDED
#define QUEUEARRAY_H_INCLUDED

#include "DynamicArray.h"

template <typename T>
class QueueArray : public DynamicArray<T> {
public:
    QueueArray() : DynamicArray<T>(), front(0) {}
    virtual ~QueueArray(){}

    // DynamicArray functions
    virtual void resize();
    virtual void insertAt(size_t index, const T item);
    virtual void removeAt(size_t index);

    virtual T topFront() const;
    virtual T topBack() const;

    // Queue-specific functions
    virtual void enqueue(const T item);
    virtual T dequeue();

    virtual void print() const;

     // Overriding IList methods to behave like a Queue
    virtual void pushFront(const T item) ;
    virtual void pushBack(const T item) ;
    virtual T popFront();
    virtual T popBack();
    virtual T& get(size_t index);
    virtual int indexOf(const T item) const;

protected:
    size_t front;
    // Inherited members to use directly
    using DynamicArray<T>::size;
    using DynamicArray<T>::capacity;
    using DynamicArray<T>::arr;
};

template <typename T>
void QueueArray<T>::resize() {
    size_t new_capacity =
        std::max(2*static_cast<int>(size), 2);
    T* brr = new T[new_capacity];
    for (size_t  i=0; i< size; i++)
       brr[i] = arr[(front+i)% capacity];

    delete [] arr;
    arr = brr;
    capacity = new_capacity;
    front = 0; // rear = size;
}

template <typename T>
void QueueArray<T>::enqueue(const T item) {
    if (size+1 > capacity)
        resize();
    // calc rear position
    size_t rear=(front+size)%capacity;
    arr[rear] = item;
    // rear = (rear + 1) % capacity; // calculated
    ++size;
}

template <typename T>
T QueueArray<T>::dequeue() {
    // Ensure the queue is not empty
    assert(size > 0);
    T item = arr[front];
    front = (front + 1) % capacity;
    --size;
    if (3 * size < capacity)
        resize();
    return item;
}

template <typename T>
void QueueArray<T>::insertAt(size_t i, const T item) {
    assert(i <= size);
    if (size+1 > capacity)
        resize();
    if (i < size/2) {
      // Update front
      front = (front == 0) ? capacity - 1 : front - 1;
      // shift arr[0],..,arr[i-1] left one position
      for (size_t k = 0; k < i; k++) {
        arr[(front + k) % capacity]
            = arr[(front + k + 1) % capacity];
      }
    } else {
      // shift arr[i],..,arr[n-1] right one position
      for (size_t k = size; k > i; k--) {
        arr[(front + k) % capacity]
            = arr[(front + k - 1) % capacity];
      }
    }
    arr[(front+i)% capacity] = item;
    ++size;
}

template <typename T>
void QueueArray<T>::removeAt(size_t i) {
    assert(i < size);
    if (i < size/2) {
        // shift arr[0],..,arr[i-1] right one position
        for (size_t k = i; k > 0; k--){
            arr[(front + k) % capacity]
                = arr[(front + k - 1) % capacity];
        }
        // Update front index after shifting
        front = (front + 1) % capacity;
    } else {
        // shift arr[i+1],..,arr[n-1] left one position
        for (size_t k = i; k < size - 1; k++){
           arr[(front + k) % capacity]
            = arr[(front + k + 1) % capacity];
        }
    }
    --size;
    if (3 * size < capacity)
        resize();
}

/*
template <typename T>
void QueueArray<T>::insertAt(size_t i, const T item) {
    if (this->size+1 > this->capacity)
        resize();
    if (i < this->size/2) {
      // Update front
      front = (front == 0) ? this->capacity - 1 : front - 1;
      // shift arr[0],..,arr[i-1] left one position
        std::copy_backward(this->arr + front,
                           this->arr + front + i,
                           this->arr + front + i + 1);

    } else {
      // shift arr[i],..,arr[n-1] right one position
        std::copy(this->arr + front + i,
                  this->arr + front + this->size,
                  this->arr + front + i + 1);
    }
    this->arr[(front+i)% this->capacity]= item;
    ++this->size;
}

template <typename T>
void QueueArray<T>::removeAt(size_t i) {
    if (i < this->size/2) {
        // shift arr[0],..,arr[i-1] right one position
        std::copy_backward(this->arr + front,
                           this->arr + front + i,
                           this->arr + front + i + 1);

        // Update front index after shifting
        front = (front + 1) % this->capacity;
    } else {
        // shift arr[i+1],..,arr[n-1] left one position
        std::copy(this->arr + front + i + 1,
                  this->arr + front + this->size,
                  this->arr + front + i);

    }
    --this->size;
    if (3 * this->size < this->capacity)
        resize();
}*/
/***
NOT IN BOOK
***/

// Customizing get method for queue-like access
template <typename T>
T& QueueArray<T>::get(size_t index) {
    assert(index < size && "Index out of range");
    return arr[(front + index) % capacity];
}

template <typename T>
int QueueArray<T>::indexOf(const T item) const {
    for (size_t i = 0; i < size; ++i) {
        if (arr[(front + i) % capacity] == item) {
            return i;
        }
    }
    return -1; // Item not found
}

// Overriding pushFront to assert as it's not typical for a queue
template <typename T>
void QueueArray<T>::pushFront(const T item) {
    assert(false && "pushFront is not supported for QueueArray");
}
// Overriding popBack to assert as it's not typical for a queue
template <typename T>
T QueueArray<T>::popBack() {
    assert(false && "popBack is not supported for QueueArray");
    return T();
}

// Overriding pushBack as an alias to enqueue
template <typename T>
void QueueArray<T>::pushBack(const T item) {
    enqueue(item);
}

// Overriding popFront as an alias to dequeue
template <typename T>
T QueueArray<T>::popFront() {
    return dequeue();
}

template <typename T>
T QueueArray<T>::topFront() const {
    assert(size > 0 && "Queue is empty");
    return arr[front];
}

template <typename T>
T QueueArray<T>::topBack() const {
    assert(size > 0 && "Queue is empty");
    size_t rear=(front+size-1)%capacity;
    return arr[rear];
}

template <typename T>
void QueueArray<T>::print() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[(front + i) % capacity] << " ";
    }
    std::cout << std::endl;
}
#endif // QUEUEARRAY_H_INCLUDED
