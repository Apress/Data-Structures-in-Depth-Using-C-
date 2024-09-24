#ifndef BTREENODE_H_INCLUDED
#define BTREENODE_H_INCLUDED

template<typename T>
struct BTreeNode {
    T key;
    BTreeNode *parent, *left, *right;
    int height;

    BTreeNode(T data) : key(data), parent(nullptr),
            left(nullptr), right(nullptr),
            height(0) {}
};
#endif // BTREENODE_H_INCLUDED
