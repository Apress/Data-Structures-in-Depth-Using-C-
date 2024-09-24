#ifndef BINARYHEAP_H_INCLUDED
#define BINARYHEAP_H_INCLUDED

#include "DynamicArray.h"

enum class HeapType { MIN_HEAP, MAX_HEAP };

template <typename T>
class BinaryHeap {
public:
    // Constructor to initialize the desired type
    BinaryHeap(HeapType type = HeapType::MIN_HEAP);

    // Inserts a new element into the heap
    void add(const T value);

    // Removes an element by value
    void remove(const T value);

    // Deletes the root element
    void deleteRoot();

    // Builds a heap from an arbitrary array of elements
    void buildHeap();

    // Sorts the elements
    void heapSort();

    // Heapifies the array
    void heapify(DynamicArray<T>& arr);

    // Utility functions
    void print() const;
    void clear();

    // Returns the element at the root
    T peek() const;

    virtual size_t getSize() const {
         return heap.getSize();
    }

protected:
    DynamicArray<T> heap;
    HeapType type; // Heap type: MIN_HEAP or MAX_HEAP

    // Maintains the heap by "bubbling down" at index i to n
    void heapifyDown(int i, int size);

    // Maintains the heap by "bubbling up" at index i
    void heapifyUp(int i);

private:
    // Returns the index of the parent/children node
    int parent(int i) const { return (i - 1) / 2; }
    int left(int i) const { return 2 * i + 1; }
    int right(int i) const { return 2 * i + 2; }

    // Helper function for comparison
    bool compare(int i, int j) const;
};

// Constructor
template <typename T>
BinaryHeap<T>::BinaryHeap(HeapType type)
    : type(type) {}

// Helper function for comparison
template <typename T>
bool BinaryHeap<T>::compare(int i, int j) const {
    if (type == HeapType::MIN_HEAP) {
        // Min-heap: Parent should be less than children
        return heap[i] > heap[j];
    } else {
        // Max-heap: Parent should be greater than children
        return heap[i] < heap[j];
    }
}

/* // UPDATED
template <typename T>
void BinaryHeap<T>::heapifyUp(int i) {
    while (i != 0 && heap[parent(i)] > heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}*/

template <typename T>
void BinaryHeap<T>::heapifyUp(int i) {
    while (i != 0 && compare(parent(i), i)) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void BinaryHeap<T>::add(const T value) {
    heap.pushBack(value);
    heapifyUp(heap.getSize() - 1);
}

template <typename T>
void BinaryHeap<T>::heapifyDown(int i, int n) {
    while (true) {
        int lChild = left(i);
        int rChild = right(i);
        int target = i;

        if (lChild < n && compare(target, lChild))
            target = lChild;

        if (rChild < n && compare(target, rChild))
            target = rChild;

        if (target == i) break;

        std::swap(heap[i], heap[target]);
        i = target;
    }
}

template <typename T>
void BinaryHeap<T>::remove(const T value) {
    int index = heap.indexOf(value);
    if (index == -1) return;

    heap[index] = heap.popBack();
    heapifyDown(index, heap.getSize());
}

/* // UPDATED
template <typename T>
void BinaryHeap<T>::heapifyDown(int i, int n) {
    while (true) {
        int lChild = left(i);
        int rChild = right(i);
        int smallest = i;

        if (lChild < n && heap[lChild] < heap[smallest]) {
            smallest = lChild;
        }

        if (rChild < n && heap[rChild] < heap[smallest]) {
            smallest = rChild;
        }

        if (smallest == i) break;

        std::swap(heap[i], heap[smallest]);
        i = smallest;
    }
}*/


template <typename T>
void BinaryHeap<T>::deleteRoot() {
    if (heap.getSize() == 0)
        return;

    heap[0] = heap.popBack();
    heapifyDown(0, heap.getSize());
}

template <typename T>
void BinaryHeap<T>::buildHeap() {
    int n = heap.getSize();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapifyDown(i, n);
    }
}

template <typename T>
void BinaryHeap<T>::heapify(DynamicArray<T>& arr) {
    heap = arr;
    buildHeap();
}

template <typename T>
void BinaryHeap<T>::heapSort() {
    buildHeap(); // First build the heap
    for (int i = heap.getSize() - 1; i >= 0; i--) {
        std::swap(heap[0], heap[i]);
        heapifyDown(0, i);
    }
}


template <typename T>
T BinaryHeap<T>::peek() const {
    assert(heap.getSize() > 0 && "Heap is empty");
    return heap[0];
}


/** NOT IN BOOK **/
template <typename T>
void BinaryHeap<T>::print() const {
    for (int i = 0; i < static_cast<int>(heap.getSize()); ++i) {
        std::cout << heap[i] << "\n";
    }
    std::cout << std::endl;
}

template <typename T>
void BinaryHeap<T>::clear() {
    // Clears all elements from the heap
    heap.clear();
}
#endif // BINARYHEAP_H_INCLUDED
