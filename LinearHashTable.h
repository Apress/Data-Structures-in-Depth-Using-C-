#ifndef LINEARHASHTABLE_H_INCLUDED
#define LINEARHASHTABLE_H_INCLUDED

#include "ISet.h"
#include "DynamicArray.h"

template <typename T>
class LinearHashTable : public ISet<T> {
public:
    // Constructor
    LinearHashTable(size_t capacity)
        : table(new DynamicArray<T>(capacity)),
          status(new DynamicArray<SlotStatus>(capacity, FREE)) {}

    virtual ~LinearHashTable() {
        delete table;
        delete status;
    }

    virtual void clear();
    virtual void print() const;

    virtual bool add(const T);
    virtual bool remove(const T);
    virtual bool contains(const T) const;
private:
    // 0 for free, 1 for occupied, 2 for deleted
    enum SlotStatus { FREE, OCCUPIED, DELETED };

    DynamicArray<T> *table;
    DynamicArray<SlotStatus> *status;

    // Hash function using Modulo
    int hash(const T item) const {
        unsigned int x = convertToInt(item);
        return x % table->getCapacity();
    }

    // Conversion based on problem
    unsigned int convertToInt(const T item) const;

    void resize();

protected:
    // Inherited members to use directly
    using ISet<T>::size;
};


template <typename T>
bool LinearHashTable<T>::contains(const T x) const {
    size_t i = hash(x);
    // Loop until an unoccupied slot is found
    while ((*status)[i] != SlotStatus::FREE) {
        // Case 1: Found and status is not DELETED
        if ((*status)[i] != SlotStatus::DELETED && (*table)[i]==x)
            return true;

        // Case 2: DELETED or OCCUPIED, continue the search
        i = (i + 1) % table->getCapacity();
    }
    // Element not found
    return false;
}

template <typename T>
bool LinearHashTable<T>::add(const T x) {
    // Case 1: Check if the element is already present
    if (contains(x))
        return false;

    // Case 2: Resize the table if it exceeds 80% occupancy
    if ( (size+1) >= 0.8* table->getCapacity())
        resize();

    // Case 3: Find the next available slot for insertion
    size_t i = hash(x);
    // Loop until an unoccupied slot is found
    while ((*status)[i] == SlotStatus::OCCUPIED) {
        i = (i + 1) % table->getCapacity();
    }

    // Update counters and insert the element
    ++size;
    (*table)[i] = x;
    (*status)[i] = SlotStatus::OCCUPIED;
    // Successfully added the element
    return true;
}



template <typename T>
bool LinearHashTable<T>::remove(const T x) {
    size_t i = hash(x);
    // Loop until an unoccupied slot is found
    while ((*status)[i] != SlotStatus::FREE) {
        T y = (*table)[i];
        if ((*status)[i] != SlotStatus::DELETED && x == y) {
            (*status)[i] = SlotStatus::DELETED;
            --size;
            // min 12.5% occupancy
            if (8 * size < table->getCapacity())
                resize();
            return true;
        }
        i = (i + 1) % table->getCapacity();
    }
    // Element not found
    return false;
}

template <typename T>
void LinearHashTable<T>::resize() {
    size_t newCapacity = 1;
    while (newCapacity < 3 * size) newCapacity <<= 1;

    DynamicArray<T>* newTable
        = new DynamicArray<T>(newCapacity);
    DynamicArray<SlotStatus>* newStatus
        = new DynamicArray<SlotStatus>(newCapacity, FREE);

    // Insert everything into newTable
    for (size_t k = 0; k < table->getCapacity(); ++k) {
        if ((*status)[k] == SlotStatus::OCCUPIED) {
            size_t i = hash((*table)[k]);
            while ((*newStatus)[i] == SlotStatus::OCCUPIED) {
                i = (i + 1) % newTable->getCapacity();
            }
            (*newTable)[i] = (*table)[k];
            (*newStatus)[i] = SlotStatus::OCCUPIED;
        }
    }

    // Update arrays
    delete table;
    delete status;

    table = newTable;
    status = newStatus;
}

/***
NOT IN BOOK
***/

template <typename T>
unsigned int LinearHashTable<T>::convertToInt(const T item) const {
    // Implement conversion logic based on type T
    // Example for integers:
    return (int)(item);
}

template <typename T>
void LinearHashTable<T>::clear() {
    for (size_t i = 0; i < table->getCapacity(); ++i) {
        (*status)[i] = FREE;
    }
    size = 0;
}

template <typename T>
void LinearHashTable<T>::print() const {
    for (size_t i = 0; i < table->getCapacity(); ++i) {
        if ((*status)[i] == OCCUPIED) {
            std::cout << "Slot " << i << ": " << (*table)[i] << std::endl;
        } else {
            std::cout << "Slot " << i << ": empty" << std::endl;
        }
    }
}

#endif // LINEARHASHTABLE_H_INCLUDED
