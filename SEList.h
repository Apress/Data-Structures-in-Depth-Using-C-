#ifndef SELIST_H_INCLUDED
#define SELIST_H_INCLUDED

#include <algorithm>
#include "IList.h"
#include "ListNode.h"

template <typename T>
class SEList : public IList<T> {
public:
    SEList(int arraySize);
    ~SEList();

    // IList Interface Methods
    virtual void insertAt(size_t index, const T item);
    virtual void removeAt(size_t index);
    virtual void pushFront(const T item);
    virtual void pushBack(const T item);
    virtual T popFront();
    virtual T popBack();
    virtual T topFront() const;
    virtual T topBack() const;
    virtual void clear();
    virtual void print() const;

    // SEList-specific functions
    void printSubLists(const std::string& sep = "->") const;
    void mergeIfNecessary(ListNode<T>* );

    virtual const T& get(size_t index) const;

    // ..... Other Abstract Interface methods
    virtual T& get(size_t index);
    virtual void set(size_t index, const T item);
    virtual T& operator[](size_t index) ;
    virtual int indexOf(const T item) const;
private:
    ListNode<T>* dummy;
    size_t nodeArraySize;

protected:
    // Inherited members to use directly
    using IList<T>::size;
};

template <typename T>
SEList<T>::SEList(int arraySize)
    : nodeArraySize(arraySize) {
    dummy = new ListNode<T>(arraySize);
    dummy->next = dummy;
    dummy->prev = dummy;
}

template <typename T>
SEList<T>::~SEList() {
    clear();
    delete dummy;
}

template <typename T>
void SEList<T>::clear() {
    ListNode<T>* curr = dummy->next;
    while (curr != dummy) {
        ListNode<T>* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    dummy->next = dummy;
    dummy->prev = dummy;
    size = 0;
}

template <typename T>
void SEList<T>::print() const {
    ListNode<T>* curr = dummy->next;
    while (curr != dummy) {
        for (size_t i = 0; i < curr->size; ++i) {
            std::cout << curr->dataArray[i] << " ";
        }
        curr = curr->next;
    }
    std::cout << std::endl;
}

template <typename T>
T& SEList<T>::operator[](size_t index) {
    assert(index <= this->size && "Index out of range");

    ListNode<T>* curr = dummy->next;
    while (curr != dummy && index >= curr->size) {
        index -= curr->size;
        curr = curr->next;
    }
    return curr->dataArray[index];
}

template <typename T>
void SEList<T>::set(size_t index, const T item) {
    assert(index <= this->size && "Index out of range");

    ListNode<T>* curr = dummy->next;
    while (curr != dummy && index >= curr->size) {
        index -= curr->size;
        curr = curr->next;
    }
    curr->dataArray[index] = item;
}

template <typename T>
int SEList<T>::indexOf(const T item) const {
    ListNode<T>* curr = dummy->next;
    int currIndex = 0;

    while (curr != dummy) {
        for (size_t i = 0; i < curr->size; ++i) {
            if (curr->dataArray[i] == item) {
                return currIndex + i;
            }
        }
        currIndex += curr->size;
        curr = curr->next;
    }

    return -1; // Item not found
}

template <typename T>
void SEList<T>::insertAt(size_t index, const T item) {
    // Ensure the index is within valid range
    assert(index <= this->size && "Index out of range");

    // CASE 1: inserting into an empty list
    if (this->size == 0) {
        ListNode<T>* newNode = new ListNode<T>(nodeArraySize);
        newNode->dataArray[0] = item;
        newNode->size = 1;
        newNode->next = dummy;
        newNode->prev = dummy;
        dummy->next = newNode;
        dummy->prev = newNode;
        ++this->size;
        return;
    }

    // Navigate to the appropriate node for insertion
    ListNode<T>* curr = dummy->next;
    size_t count = 0;

    while (curr != dummy && count + curr->size <= index) {
        count += curr->size;
        curr = curr->next;
    }

    // CASE 2: If inserting at the end of the list
    if (curr == dummy && count == index) {
        curr = dummy->prev;

        if (curr->size < curr->capacity) {
            // Insert at the end of the last node if it has space
            curr->dataArray[curr->size] = item;
            ++curr->size;
            ++this->size;
        } else {
            // Create a new node if the last node is full
            ListNode<T>* newNode = new ListNode<T>(nodeArraySize);
            newNode->dataArray[0] = item;
            newNode->size = 1;
            newNode->prev = curr;
            newNode->next = dummy;
            curr->next = newNode;
            dummy->prev = newNode;
            ++this->size;
        }
        return;
    } else if (curr == dummy) {
        assert(false && "Index out of range");
    }

    // CASE 3: If the node is full, split it before inserting

    // Calculate the local index within the node
    size_t localIndex = index - count;

    if (curr->size == curr->capacity) {
        // (1) Create a new ListNode
        ListNode<T>* newNode = new ListNode<T>(nodeArraySize);
        // (2) Calculate the middle point
        size_t mid = curr->capacity / 2;
        // (3) Copy the right half to the new ListNode
        std::copy(curr->dataArray + mid, curr->dataArray + curr->size, newNode->dataArray);

        newNode->size = curr->size - mid;
        // (4) Adjust the current ListNode size

        curr->size = mid;

        // (5) Adjust pointers
        newNode->next = curr->next;
        newNode->prev = curr;
        if (curr->next != nullptr) {
            curr->next->prev = newNode;
        }
        curr->next = newNode;

        // (6) Determine whether to insert in
        //  the new node or the current one
        if (localIndex >= mid) {
            curr = newNode;
            localIndex -= mid;
        }
    }

    // Shift elements within the node to make space for the new item
    for (size_t i = curr->size; i > localIndex; --i) {
        curr->dataArray[i] = curr->dataArray[i - 1];
    }

    // Insert the new item
    curr->dataArray[localIndex] = item;
    ++curr->size;
    ++this->size;
}


template <typename T>
void SEList<T>::pushFront(const T item) {
    insertAt(0, item);
}

template <typename T>
void SEList<T>::pushBack(const T item) {
    insertAt(size, item);
}

template <typename T>
T SEList<T>::topFront() const {
    assert(!this->isEmpty() && "List is empty");

    return dummy->next->dataArray[0];
}

template <typename T>
T SEList<T>::topBack() const {
    assert(!this->isEmpty() && "List is empty");
    return get(this->size - 1);
}


template <typename T>
T SEList<T>::popFront() {
    assert(!this->isEmpty() && "List is empty");

    T item = get(0);
    removeAt(0);
    return item;
}

template <typename T>
T SEList<T>::popBack() {
    assert(!this->isEmpty() && "List is empty");

    T item = get(size - 1);
    removeAt(size - 1);
    return item;
}

template <typename T>
const T& SEList<T>::get(size_t index) const {
    return const_cast<SEList<T>&>(*this)[index];
}

template <typename T>
T& SEList<T>::get(size_t index) {
    return (*this)[index];
}


template <typename T>
void SEList<T>::removeAt(size_t index) {
    // Ensure the index is within valid range
    assert(index < this->size && "Index out of range");

    ListNode<T>* curr = dummy->next;
    size_t count = 0;

    // Navigate to the appropriate node
    while (curr != dummy && count + curr->size <= index) {
        count += curr->size;
        curr = curr->next;
    }

    // Ensure we have found a valid node
    assert(curr != dummy &&
            "Unexpected dummy node encountered during remove");

    // Calculate the local index within the node
    size_t localIndex = index - count;

    // Shift elements within the node
    for (size_t i = localIndex; i < curr->size - 1; ++i) {
        curr->dataArray[i] = curr->dataArray[i + 1];
    }

    --curr->size;
    --this->size;

    // Delete the node if it becomes empty
    if (curr->size == 0) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }
    // Optional: Handle merging of nodes if necessary
}

template <typename T>
void SEList<T>::mergeIfNecessary(ListNode<T>* node) {
    if (node->next != dummy && node->size + node->next->size <= node->capacity) {
        // Merge node with next node
        ListNode<T>* nextNode = node->next;
        std::copy(nextNode->dataArray, nextNode->dataArray + nextNode->size, node->dataArray + node->size);
        node->size += nextNode->size;

        node->next = nextNode->next;
        nextNode->next->prev = node;

        delete nextNode;
    }
}

template <typename T>
void SEList<T>::printSubLists(const std::string& sep) const {
    ListNode<T>* curr = dummy->next;

    while (curr != dummy) {
        std::cout << "[";
        for (size_t i = 0; i < curr->size; ++i) {
            std::cout << curr->dataArray[i];
            if (i < curr->size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (curr->next != dummy) {
            std::cout << sep;
        }
        curr = curr->next;
    }
    std::cout << std::endl;
}

#endif // SELIST_H_INCLUDED
