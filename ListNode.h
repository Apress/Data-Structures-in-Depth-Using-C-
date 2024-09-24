#ifndef LISTNODE_H_INCLUDED
#define LISTNODE_H_INCLUDED

template <typename T>
struct ListNode {
    T* dataArray;    // Array of data values
    size_t size;     // Number of elements in the array
    size_t capacity; // Array Capacity
    ListNode* next;  // Pointer to the next node
    ListNode* prev;  // Pointer to the previous node

    ListNode(int arraySize);
    ~ListNode();
};

template <typename T>
ListNode<T>::ListNode(int arraySize)
    : size(0), capacity(arraySize),
      next(nullptr), prev(nullptr) {
    dataArray = new T[arraySize];
}

template <typename T>
ListNode<T>::~ListNode() {
    delete[] dataArray;
}

#endif // LISTNODE_H_INCLUDED
