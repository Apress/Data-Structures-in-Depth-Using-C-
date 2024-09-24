#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

#include <algorithm>
#include "IList.h"

template <typename T>
class DynamicArray : public IList<T> {
public:
    DynamicArray()
        : IList<T>(),
          arr(new T[getDefaultCapacity()]),
          capacity(getDefaultCapacity()),
          autoResize(true) {}

    // constructor with capacity
    DynamicArray(size_t capacityValue)
        : IList<T>(),
          arr(new T[capacityValue]),
          capacity(capacityValue),
          autoResize(true) {}

    // constructor with capacity and initial value
    DynamicArray(size_t capacityValue, const T initialValue)
        : IList<T>(),
          arr(new T[capacityValue]),
          capacity(capacityValue),
          autoResize(false)
    {
        for (size_t i = 0; i < capacityValue; ++i) {
            arr[i] = initialValue;
        }
        size = capacityValue;
    }

    virtual ~DynamicArray(){
          cleanup();
    }
    DynamicArray(const DynamicArray<T>& other);     // Copy constructor
    DynamicArray(DynamicArray<T>&& other) noexcept; // Move constructor

    DynamicArray& operator=(DynamicArray<T>&& other) noexcept;

    // Interface Methods
    virtual void resize();
    DynamicArray& operator=(const DynamicArray<T>& other);
    virtual size_t getCapacity() const {
        return capacity;
    }

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
    virtual void print() const ;

    // ..... Other Abstract Interface methods
    virtual T& get(size_t index);
    virtual const T& get(size_t index)const;
    virtual void set(size_t index, const T item);

    virtual T& operator[](size_t index) ;
    virtual const T& operator[](size_t index)  const;

    virtual int indexOf(const T item) const;

    // Method to enable or disable auto-resizing
    void setAutoResize(bool value) {
        autoResize = value;
    }
    bool isAutoResize() const {
        return autoResize;
    }

protected:
    T* arr;
    size_t capacity;

    // Flag to control auto-resize
    bool autoResize;

    // To allow derived classes to change default capacity
    virtual size_t getDefaultCapacity() const {
        return 8;
    }

    // Inherited members to use directly
    using IList<T>::size;

private:
     // Helper methods for deep copy and cleanup
    void copyFrom(const DynamicArray<T>& other);
    void moveFrom(DynamicArray<T>&& other) noexcept;
    void cleanup();

};


template <typename T>
T& DynamicArray<T>::get(size_t i) {
    assert(i >= 0 && i < size);
    return arr[i];
}
template <typename T>
const T& DynamicArray<T>::get(size_t i) const{
    assert(i >= 0 && i < size);
    return arr[i];
}

template <typename T>
void DynamicArray<T>::set(size_t i, const T item) {
    assert(i >= 0 && i < size);
    arr[i] = item;
}

template <typename T>
T& DynamicArray<T>::operator[](size_t i) {
    return arr[i];
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t i) const{
    assert(i >= 0 && i < size);
    return arr[i];
}

template <typename T>
void DynamicArray<T>::insertAt(size_t i, const T item) {
    assert(i >= 0 && i <= size);
    if (size == capacity)
        resize();
    std::copy_backward(arr + i,
                       arr + size,
                       arr + size + 1);
    arr[i] = item;
    ++size;
}

template <typename T>
void DynamicArray<T>::removeAt(size_t i) {
    assert(i >= 0 && i < size);
    for (size_t j = i; j < size - 1; ++j)
        arr[j] = arr[j + 1];
    --size;
    if (autoResize && capacity >= 3*size)
        resize();
}

/*template <typename T>
void DynamicArray<T>::removeAt(size_t i) {
    assert(i >= 0 && i < size);
    std::copy(arr + i + 1,
              arr + size,
              arr + i);
    --size;
    if (autoResize && capacity >= 3*size)
        resize();
}*/

template <typename T>
void DynamicArray<T>::pushBack(const T item) {
    insertAt(size, item);
}

template <typename T>
void DynamicArray<T>::pushFront(const T item) {
    insertAt(0,item);
}

template <typename T>
T DynamicArray<T>::popFront() {
   assert(size > 0);
    T& frontData = arr[0];
    removeAt(0);
    return frontData;
}

template <typename T>
T DynamicArray<T>::popBack() {
    assert(size > 0);
    T& backData = arr[size - 1];
    --size;
    return backData;
}

template <typename T>
void DynamicArray<T>::resize() {
    size_t new_capacity = std::max(2*static_cast<int>(size), 2);
    T* brr = new T[new_capacity];
    std::copy(arr, arr + size, brr);
    delete[] arr;
    arr = brr;
    capacity = new_capacity;
}
/***
NOT IN BOOK
***/
template <typename T>
int DynamicArray<T>::indexOf(const T item) const {
    for (size_t i = 0; i < size; ++i) {
        // Requires T to have operator==
        if (arr[i] == item) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void DynamicArray<T>::print() const {
    for (size_t i = 0; i < size; ++i) {
        // Requires T to have operator<<
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void DynamicArray<T>::clear() {
    delete[] arr;
    arr = new T[getDefaultCapacity()];
    size = 0;
    capacity = getDefaultCapacity();
}


template <typename T>
T DynamicArray<T>::topFront() const {
    assert(size > 0);
    return arr[0];
}

template <typename T>
T DynamicArray<T>::topBack() const {
    assert(size > 0);
    return arr[this->size - 1];
}


template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
    copyFrom(other);
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& other) noexcept {
    moveFrom(std::move(other));
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
    if (this != &other) {
        cleanup();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>&& other) noexcept {
    if (this != &other) {
        cleanup();
        moveFrom(std::move(other));
    }
    return *this;
}

template <typename T>
bool operator==(const DynamicArray<T>& lhs, const DynamicArray<T>& rhs) {
    if (lhs.getSize() != rhs.getSize()) {
        return false;
    }
    for (size_t i = 0; i < lhs.getSize(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& obj) {
    os << "[ ";
    for (size_t i = 0; i < obj.getSize() ; ++i) {
        os << obj[i] << " ";  // This assumes T has operator<< defined
    }
    os << "]";
    return os;
}

template <typename T>
void DynamicArray<T>::copyFrom(const DynamicArray<T>& other) {
    arr = new T[other.capacity];
    capacity = other.capacity;
    size = other.size;
    autoResize = other.autoResize;
    for (size_t i = 0; i < size; ++i) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
void DynamicArray<T>::moveFrom(DynamicArray<T>&& other) noexcept {
    arr = other.arr;
    capacity = other.capacity;
    size = other.size;
    autoResize = other.autoResize;

    other.arr = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <typename T>
void DynamicArray<T>::cleanup() {
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
}
#endif // DYNAMICARRAY_H_INCLUDED
