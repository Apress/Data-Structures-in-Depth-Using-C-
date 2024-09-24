#ifndef ILIST_H_INCLUDED
#define ILIST_H_INCLUDED

#include <stdexcept>
#include <cassert>
#include <iostream>

template <typename T>
class IList {
public:
  IList() : size(0) {}

  virtual size_t getSize() const {
     return size;
  }
  virtual bool isEmpty() const {
    return size == 0;
  }

  virtual void clear() = 0;
  virtual void print() const = 0;

  virtual T& get(size_t index) = 0;
  virtual void set(size_t index, const T item) = 0;
  virtual T& operator[](size_t index) = 0;
  virtual int indexOf(const T item) const = 0;

  virtual void insertAt(size_t index, const T item) = 0;
  virtual void removeAt(size_t index) = 0;
  virtual void pushFront(const T item) = 0;
  virtual void pushBack(const T item) = 0;
  virtual T popFront() = 0;
  virtual T popBack() = 0;
  virtual T topFront() const = 0;
  virtual T topBack() const = 0;

protected:
  size_t size;
};

#endif // ILIST_H_INCLUDED
