#ifndef SINGLYLL_H_INCLUDED
#define SINGLYLL_H_INCLUDED

#include "Node.h"
#include "IList.h"

using namespace std;

template <typename T>
class SinglyLL : public IList<T> {
public:
    SinglyLL() : IList<T>(),
                 head(nullptr) {}

    virtual ~SinglyLL();

    virtual void insertAt(size_t index, const T item);
    virtual void removeAt(size_t index);
    virtual void pushFront(const T item);
    virtual void pushBack(const T item);
    virtual T popFront();
    virtual T popBack();
    virtual T topFront() const;
    virtual T topBack() const;
    // ..... Other Abstract Interface methods
    virtual void clear() ;
    virtual void print() const ;

    virtual T& get(size_t index)  ;
    virtual const  T& get(size_t index) const  ;

    virtual void set(size_t index, const T item);
    virtual T& operator[](size_t index) ;
    virtual const T& operator[](size_t index) const;
    virtual int indexOf(const T item) const;

    template <typename U>
    friend ostream& operator<<(ostream&, const SinglyLL<U>&);

    template <typename U>
    friend bool operator==(const SinglyLL<U>&, const SinglyLL<U>&);

protected:
    Node<T>* head;
    // Inherited members to use directly
    using IList<T>::size;
};

template <typename T>
void SinglyLL<T>::pushFront(const T item) {
    Node<T>* newNode = new Node<T>(item);

    // (1) Link the new node to the current head.
    newNode->next = head;

    // (2) Update the head pointer to the new node.
    head = newNode;

    ++size;
}

template <typename T>
void SinglyLL<T>::pushBack(const T item) {
    Node<T>* newNode = new Node<T>(item);

    // CASE 1: If there is no head
    if (!head) {
        // (1) Set the new node as the head.
        head = newNode;
    }
    // CASE 2: If there are existing nodes
    else {
        Node<T>* current = head;
        // (1) Seek to the last node.
        while (current->next) {
            current = current->next;
        }
        // (2) Append the new element to the last node.
        current->next = newNode;
    }
    ++size;
}

template <typename T>
T SinglyLL<T>::popFront() {
    assert(head && size > 0);

    // (1) Save a reference to the current head node.
    Node<T>* temp = head;
    // (2) Update the head pointer to the next node.
    head = head->next;
    T frontData = temp->data;
    // (3) Delete the old head node.
    delete temp;
    --size;
    return frontData;
}

template <typename T>
T SinglyLL<T>::popBack() {
    // Ensure the list is not empty
    assert(head && size > 0);

    T backData;
    // Case 1: If there's only one element in the list
    if (head->next == nullptr) {
        backData = head->data;
        // (1) Delete the head node.
        delete head;
        // (2) Update the head pointer to null.
        head = nullptr;
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
        // (3) Update the node's 'next' pointer to null.
        current->next = nullptr;
    }
    --size;
    return backData;
}

template <typename T>
T& SinglyLL<T>::get(size_t index) {
    assert(index >= 0 && index < size);
    Node<T>* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
const T& SinglyLL<T>::get(size_t index) const {
    assert(index >= 0 && index < size);
    Node<T>* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
T& SinglyLL<T>::operator[](size_t i) {
    return get(i);
}

template <typename T>
const T& SinglyLL<T>::operator[](size_t i) const{
    return get(i);
}
template <typename T>
void SinglyLL<T>::print() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
SinglyLL<T>::~SinglyLL() {
    clear();
}

template <typename T>
void SinglyLL<T>::clear() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template <typename T>
void SinglyLL<T>::insertAt(size_t index, const T item) {
     // Check if the index is within valid range
    assert(index >= 0 && index <= size);

    // Case 1: Inserting at the beginning of the list
    if (index == 0) {
        pushFront(item);
    }
    // Case 2: Inserting in the middle or end of the list
    else {
        Node<T>* newNode = new Node<T>(item);
        Node<T>* current = head;
        // (1) Traverse to the node before the index
        for (size_t i = 1; i < index; i++) {
            current = current->next;
        }
        // (2) Update the new node's `next`.
        newNode->next = current->next;
        // (3) Update the previous node's `next`.
        current->next = newNode;
        ++size;
    }
}

template <typename T>
void SinglyLL<T>::removeAt(size_t index) {
    // Check if the index is within valid range
    assert(index >= 0 && index < size);

    // Case 1: Removing the first element
    if (index == 0) {
        popFront();
    }
    // Case 2: Removing from the middle or end of the list
    else {
        Node<T>* prev = head;
        // (1) Traverse to the node before the
        //     one to be removed
        for (size_t i = 1; i < index; i++) {
            prev = prev->next;
        }
        Node<T>* current = prev->next;
        // (2) Update the previous node's `next`.
        prev->next = current->next;
        // (3) Delete the element at the specified index.
        delete current;
        --size;
    }
}

/***
NOT IN BOOK
***/



template <typename T>
void SinglyLL<T>::set(size_t index, const T item) {
     assert(index >= 0 && index < size);
    Node<T>* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    current->data = item;
}


template <typename T>
int SinglyLL<T>::indexOf(const T item) const {
    Node<T>* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        ++index;
    }
    return -1;
}

template <typename T>
T SinglyLL<T>::topFront() const {
    assert(size > 0);
    return head->data;
}

template <typename T>
T SinglyLL<T>::topBack() const {
    assert(size > 0);
    Node<T>* current = head;
    while (current->next) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
ostream& operator<<(ostream& os, const SinglyLL<T>& list) {
    list.print();
    return os;
}

template <typename T>
bool operator==(const SinglyLL<T>& lhs, const SinglyLL<T>& rhs) {
    Node<T>* current1 = lhs.head;
    Node<T>* current2 = rhs.head;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->data != current2->data) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return (current1 == nullptr && current2 == nullptr);
}
#endif // SINGLYLL_H_INCLUDED


