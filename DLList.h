#ifndef DLLIST_H_INCLUDED
#define DLLIST_H_INCLUDED

#include "DNode.h"
#include "IList.h"

template <typename T>
class DLList : public IList<T> {
public:
    DLList() : IList<T>() {
        dummy = new DNode<T>();
        dummy->next = dummy;
        dummy->prev = dummy;
    }

     // Deep copy constructor
    DLList(const DLList& other) : DLList() {
        for (DNode<T>* node = other.dummy->next;
        node != other.dummy; node = node->next) {
            pushBack(node->data);
        }
    }

    virtual ~DLList() ;
    // IList Interface Methods
    virtual void insertAt(size_t index, const T item);
    virtual void removeAt(size_t index);
    virtual void pushFront(const T item);
    virtual void pushBack(const T item);
    virtual T popFront();
    virtual T popBack();
    virtual T topFront() const;
    virtual T topBack() const;

    virtual void clear() ;
    virtual void print() const;

    virtual T& get(size_t index);
    virtual const T& get(size_t index) const;
    virtual void set(size_t index, const T item);
    virtual T& operator[](size_t index) ;
    virtual const T& operator[](size_t index) const;

    virtual int indexOf(const T item) const;
private:
    DNode<T>* dummy;

    DNode<T>* jumpTo(size_t index) const;


protected:
    // Inherited members to use directly
    using IList<T>::size;
};


template <typename T>
void DLList<T>::pushBack(const T item) {
    // (1) Create a new node
    DNode<T>* newNode = new DNode<T>(item);

    // (2) Link the new node with the
    //     current last node and dummy node
    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    // (3) Increment the size of the list
    ++size;
}

template <typename T>
void DLList<T>::pushFront(const T item) {
    // (1) Create a new node
    DNode<T>* newNode = new DNode<T>(item);

    // (2) Link the new node with
    //  the dummy node and the first node
    newNode->next = dummy->next;
    newNode->prev = dummy;
    dummy->next->prev = newNode;
    dummy->next = newNode;

    // (3) Increment the size of the list
    ++size;
}


template <typename T>
T DLList<T>::popBack() {
    assert(dummy->prev != dummy && size > 0);

    // (1) Save a reference to the last node
    DNode<T>* temp = dummy->prev;
    T backData = temp->data;

    // (2) Update the dummy's previous node
    dummy->prev = temp->prev;
    temp->prev->next = dummy;

    // (3) Delete the last node
    delete temp;
    --size;

    return backData;
}

template <typename T>
T DLList<T>::popFront() {
    assert(dummy->next != dummy && size > 0);

    // (1) Save a reference to the first node
    DNode<T>* temp = dummy->next;
    T frontData = temp->data;

    // (2) Update the dummy's next node
    dummy->next = temp->next;
    temp->next->prev = dummy;

    // (3) Delete the first node
    delete temp;
    --size;

    return frontData;
}

template <typename T>
DNode<T>* DLList<T>::jumpTo(size_t index) const {
    assert(index >= 0 && index < size);

    DNode<T>* current;

    // (1) Determine the direction to traverse
    if (index < size / 2) {
        // (2) Traverse from the head
        //      if the index is in the first half
        current = dummy->next;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
    } else {
        // (3) Traverse from the tail
        //     if the index is in the second half
        current = dummy;
        for (size_t i = size; i > index; --i) {
            current = current->prev;
        }
    }
    return current;
}


template <typename T>
void DLList<T>::insertAt(size_t index, const T item) {
    assert(index >= 0 && index < size);

    // (1) Create a new node
    DNode<T>* newNode = new DNode<T>(item);

    // (2) Jump to index location
    DNode<T>* current = jumpTo(index);

    // (3) Insert the new node
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;

    // (4) Increment the size of the list
    ++size;
}

template <typename T>
void DLList<T>::removeAt(size_t index) {
    assert(index >= 0 && index < size);

    // (1) Jump to index location
    DNode<T>* current = jumpTo(index);

    // (2) Update the links
    current->prev->next = current->next;
    current->next->prev = current->prev;

    // (3) Delete the current node
    delete current;
    --size;
}

template <typename T>
T& DLList<T>::get(size_t index) {
    assert(index >= 0 && index < size);
    // (1) Jump to the specified index location
    DNode<T>* curr = jumpTo(index);
    // (2) Return the data at the index
    return curr->data;
}

template <typename T>
const T& DLList<T>::get(size_t index) const{
    return get(index);
}

template <typename T>
T& DLList<T>::operator[](size_t index) {
    return get(index);
}

template <typename T>
void DLList<T>::set(size_t index, const T item) {
    assert(index >= 0 && index < size);
    DNode<T>* curr = jumpTo(index);
    curr->data = item;
}

template <typename T>
void DLList<T>::print() const {
    DNode<T>* current = dummy->next;
    while (current != dummy) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DLList<T>::clear() {
    DNode<T>* current = dummy->next;
    while (current != dummy) {
        DNode<T>* temp = current;
        current = current->next;
        delete temp;
    }
    dummy->next = dummy;
    dummy->prev = dummy;
    size = 0;
}

template <typename T>
DLList<T>::~DLList() {
    clear();
    delete dummy;
}

/***
NOT IN BOOK
***/

template <typename T>
int DLList<T>::indexOf(const T item) const {
    DNode<T>* curr = dummy->next;
    size_t index = 0;
    while (curr != dummy) {
        if (curr->data == item) {
            return index;
        }
        curr = curr->next;
        ++index;
    }
    return -1;
}

template <typename T>
T DLList<T>::topFront() const {
    assert(size > 0);
    return dummy->next->data;
}

template <typename T>
T DLList<T>::topBack() const {
    assert(size > 0);
    return dummy->prev->data;
}

template <typename T>
const T& DLList<T>::operator[](size_t index) const {
    DNode<T>* node = jumpTo(index);
    return node->data;
}

#endif // DLLIST_H_INCLUDED
