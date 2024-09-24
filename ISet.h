#ifndef ISET_H_INCLUDED
#define ISET_H_INCLUDED

template <typename T>
class ISet {
public:
  ISet() : size(0) {}

  virtual size_t getSize() const {
     return size;
  }
  virtual bool isEmpty() const {
    return size == 0;
  }

  virtual void clear() = 0;
  virtual void print() const = 0;

  virtual bool add(const T x) = 0;
  virtual bool remove(const T x) = 0;
  virtual bool contains(const T x) const = 0;

protected:
  size_t size;
};

#endif // ISET_H_INCLUDED
