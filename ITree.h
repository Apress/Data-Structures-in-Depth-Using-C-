#ifndef ITREE_H_INCLUDED
#define ITREE_H_INCLUDED

template <typename N, typename T>
class ITree {

public:
    virtual ~ITree() {}
    ITree() {}

    virtual size_t depth(N* node) const = 0;
    virtual size_t height() const = 0;
    virtual size_t height(N* node) const = 0;

    virtual size_t getSize() const = 0;
    virtual size_t getSize(N* node) const = 0;

    virtual N* getRoot() const = 0;

    virtual bool insert(const T) = 0;
    virtual bool remove(const T) = 0;
    virtual N* find(const T) const = 0;
    virtual void traverse() const = 0;
    virtual void clear() = 0;
};

#endif // ITREE_H_INCLUDED
