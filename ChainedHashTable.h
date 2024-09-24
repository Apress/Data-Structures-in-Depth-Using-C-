#ifndef CHAINEDHASHTABLE_H_INCLUDED
#define CHAINEDHASHTABLE_H_INCLUDED

#include "ISet.h"
#include "DynamicArray.h"
#include "SinglyLL.h"
#include <cmath>

template <typename T>
class ChainedHashTable : public ISet<T>{

public:
    ChainedHashTable(size_t initialCapacity = 1024)
        : table(initialCapacity, SinglyLL<T>()),
          D((int)(std::log2(initialCapacity))) {}

    virtual void clear();
    virtual void print() const ;

    virtual bool add(const T);
    virtual bool remove(const T);
    virtual bool contains(const T) const;

    const SinglyLL<T>& get(const T&) const;
    SinglyLL<T>& get(const T&);

    DynamicArray<T> getAll() const;

private:
    DynamicArray<SinglyLL<T>> table;

    // Multiplicative hash parameters
    static const int W = 32;
    // D is determined based on the capacity
    // D = 10 For Table size of 1024
    int D;

    // A randomly chosen odd number in [1:2^W-1]
    static const long long Z = 2654435769;

    // Hash function using multiplicative hashing
    unsigned int hash(const T item) const{
        unsigned int x = convertToInt(item);
        return ((Z * x) >> (W - D)) % table.getCapacity();
    }

    // Conversion based on problem
    unsigned int convertToInt(const T x) const;

protected:
    // Inherited members to use directly
    using ISet<T>::size;
};

template <typename T>
bool ChainedHashTable<T>::contains(const T item) const {
    size_t index = hash(item);
    // Ensure the index is within the bounds
    assert(index < table.getCapacity());
    // Using indexOf to check if x exists
    const SinglyLL<T>& bucket = table[index];
    return bucket.indexOf(item) != -1;
}


template <typename T>
unsigned int ChainedHashTable<T>::convertToInt(const T x) const {
    // Implement conversion logic based on type T
    // Example for integers:
    return static_cast<unsigned int>(x);
}

template <typename T>
void ChainedHashTable<T>::clear() {
    for (size_t i = 0; i < table.getCapacity(); ++i) {
        table[i].clear();
    }
    size = 0;
}

template <typename T>
void ChainedHashTable<T>::print() const {
    for (size_t i = 0; i < table.getCapacity(); ++i) {
        std::cout << "Bucket " << i << ": ";
        const SinglyLL<T>& bucket = table[i];
        bucket.print();
    }
    std::cout << std::endl;
}


template <typename T>
bool ChainedHashTable<T>::add(const T x) {
    size_t index = hash(x);
    // Ensure the index is within the bounds
    assert(index < table.getCapacity());
    // Using indexOf to check if x exists
    if (table[index].indexOf(x) == -1) {
        table[index].pushFront(x);
        ++size;
        return true;
    }
    return false;
}

template <typename T>
bool ChainedHashTable<T>::remove(const T x) {
    size_t index = hash(x);
    // Ensure the index is within the bounds
    assert(index < table.getCapacity());
    int pos = table[index].indexOf(x);
    // Using indexOf to check if x exists
    if (pos != -1) {
        --size;
        // Remove specific element in SinglyLL
        table[index].removeAt(pos);
        return true;
    }
    return false;
}

/** NOT IN BOOK **/
template <typename T>
const SinglyLL<T>& ChainedHashTable<T>::get(const T& item) const {
    unsigned int index = hash(item);
    return table[index];
}
template <typename T>
SinglyLL<T>& ChainedHashTable<T>::get(const T& item) {
    unsigned int index = hash(item);
    return table[index];
}
template <typename T>
DynamicArray<T> ChainedHashTable<T>::getAll() const {
    // Initialize with the current size
    DynamicArray<T> allItems= DynamicArray<T>(size);

    for (size_t i = 0; i < table.getCapacity(); ++i) {
        for (size_t j = 0; j < table[i].getSize(); ++j) {
            allItems.pushBack(table[i].get(j));
        }
    }

    return allItems;
}

#endif // CHAINEDHASHTABLE_H_INCLUDED
