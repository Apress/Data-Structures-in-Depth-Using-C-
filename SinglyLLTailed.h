#ifndef SINGLYLLTAILED_H_INCLUDED
#define SINGLYLLTAILED_H_INCLUDED

#include "SinglyLL.h"

template <typename T>
class SinglyLLTailed : public SinglyLL<T> {
public:
    SinglyLLTailed() : SinglyLL<T>(),
                     tail(nullptr) {}

    virtual ~SinglyLLTailed();

    // IList Interface Methods
    virtual void clear();
    virtual void pushBack(const T item);
    virtual void pushFront(const T item);
    virtual T popBack() ;
    virtual T popFront();
    virtual T topBack() const;

protected:
    Node<T>* tail;

    using SinglyLL<T>::size;
    using SinglyLL<T>::head;
};

template <typename T>
void SinglyLLTailed<T>::pushBack(const T item)  {
    Node<T>* newNode = new Node<T>(item);

    // Case 1: If there is no head
    if (!head) {
        // (1) Set the new node as the head.
        head = newNode;
        // (2) Set the new node as the tail.
        tail = newNode;
    }
    // Case 2: If there are existing nodes
    else {
        // (1) Append the new element to the current tail.
        tail->next = newNode;
        // (2) Update the tail to the new node.
        tail = newNode;
    }
    ++size;
}

template <typename T>
T SinglyLLTailed<T>::popBack() {
    // Ensure the list is not empty
    assert(head && size > 0);

    T backData;

    // Case 1: If there's only one element in the list
    if (head->next == nullptr) {
        backData = head->data;
        // (1) Delete the head node.
        delete head;
        // (2) Update the head and tail pointers to null.
        head = tail = nullptr;
    }
    // Case 2: If there are multiple nodes in the list
    else {
        Node<T>* current = head;
        // (1) Traverse to the second-to-last node.
        while (current->next->next) {
            current = current->next;
        }
        backData = current->next->data;
        // (2) Delete the last node.
        delete current->next;
        // (3) Update the tail pointer to the 2-to-last node.
        current->next = nullptr;
        tail = current;
    }
    --size;
    return backData;
}

template <typename T>
void SinglyLLTailed<T>::clear()  {
    SinglyLL<T>::clear();
    // Release `tail` pointer.
    tail = nullptr;
}

template <typename T>
SinglyLLTailed<T>::~SinglyLLTailed() {
    clear();
}

/***
NOT IN BOOK
***/

template <typename T>
void SinglyLLTailed<T>::pushFront(const T item) {
    SinglyLL<T>::pushFront(item);
    if (tail == nullptr) {
        tail = head;
    }
}

template <typename T>
T SinglyLLTailed<T>::popFront() {
    assert(head && size > 0);
    // (1) Save a reference to the current head node.
    Node<T>* temp = head;
    // (2) Update the head pointer to the next node.
    head = head->next;
    T frontData = temp->data;
    // (3) Delete the old head node.
    delete temp;
    --size;
    if (head == nullptr) {
        tail = nullptr;
    }
    return frontData;
}

template <typename T>
T SinglyLLTailed<T>::topBack() const  {
    assert(size > 0);
    return tail->data;
}
#endif // SINGLYLLTAILED_H_INCLUDED
