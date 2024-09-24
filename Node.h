#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
struct Node {
    T data;
    Node* next;

    Node() :  next(nullptr) {}
    Node(const T& item) : data(item), next(nullptr) {}
};

#endif // NODE_H_INCLUDED
