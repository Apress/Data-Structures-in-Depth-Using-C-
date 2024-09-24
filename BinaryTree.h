#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include "ITree.h"
#include "BTreeNode.h"
#include "QueueArray.h"

template <typename T=int>
class BinaryTree : public ITree<BTreeNode<T>, T> {
public:
    BinaryTree() : root(nullptr) {}

    virtual ~BinaryTree();

    virtual size_t depth(BTreeNode<T>*) const;
    virtual size_t height() const ;
    virtual size_t height(BTreeNode<T>*) const;
    virtual size_t getSize() const;
    virtual size_t getSize(BTreeNode<T>*) const;
    virtual BTreeNode<T>* getRoot() const {
        return root;
    }

    void preOrderTraversal(BTreeNode<T>*) const;
    void inOrderTraversal(BTreeNode<T>*) const;
    void postOrderTraversal(BTreeNode<T>*) const;
    void levelOrderTraversal(BTreeNode<T>*) const;

    // ... Other relevant functions
    virtual bool remove(const T) = 0;
    virtual bool insert(const T) = 0;
    virtual BTreeNode<T>* find(const T) const = 0;
    virtual void traverse() const = 0;
    virtual void clear();

protected:
    BTreeNode<T> *root;

    void deleteSubTree(BTreeNode<T> *);
};


template <typename T>
size_t BinaryTree<T>::depth(BTreeNode<T> *u) const {
    size_t d = 0;
    while (u != nullptr) {
        u = u->parent;
        d++;
    }
    return d;
}

template <typename T>
size_t BinaryTree<T>::getSize(BTreeNode<T> *u) const {
    if (u == nullptr) return 0;
    return 1 + getSize(u->left) + getSize(u->right);
}

template <typename T>
size_t BinaryTree<T>::getSize() const {
    return  getSize(root);
}


template <typename T>
size_t BinaryTree<T>::height(BTreeNode<T> *u) const {
    if (u == nullptr) return -1;
    return 1 + std::max(height(u->left), height(u->right));
}

template <typename T>
size_t BinaryTree<T>::height() const {
    return height(root);
}

template <typename T>
void BinaryTree<T>::preOrderTraversal(BTreeNode<T>*node) const{
    if (node == nullptr) return;
    // Process the root
    std::cout << node->key << " ";
    // Traverse left subtree
    preOrderTraversal(node->left);
    // Traverse right subtree
    preOrderTraversal(node->right);
}

template <typename T>
void BinaryTree<T>::inOrderTraversal(BTreeNode<T>*node) const{
    if (node == nullptr) return;
    // Traverse left subtree
    inOrderTraversal(node->left);
    // Process the root
    std::cout << node->key << " ";
    // Traverse right subtree
    inOrderTraversal(node->right);
}

template <typename T>
void BinaryTree<T>::postOrderTraversal(BTreeNode<T>*node) const{
    if (node == nullptr) return;
    // Traverse left subtree
    postOrderTraversal(node->left);
    // Traverse right subtree
    postOrderTraversal(node->right);
    // Process the root
    std::cout << node->key << " ";
}

template <typename T>
void BinaryTree<T>::levelOrderTraversal(BTreeNode<T>*root) const{
    if (root == nullptr) return;
    QueueArray<BTreeNode<T>*> q;
    q.enqueue(root);
    while (!q.isEmpty()) {
        BTreeNode<T>* node = q.dequeue();
        // Process the current node
        std::cout << node->key << " ";
        if (node->left != nullptr)
            // Enqueue left child
            q.enqueue(node->left);
        if (node->right != nullptr)
            // Enqueue right child
            q.enqueue(node->right);
    }
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear();
}

template <typename T>
void BinaryTree<T>::clear() {
    deleteSubTree(root);
    root = nullptr;
}

template <typename T>
void BinaryTree<T>::deleteSubTree(BTreeNode<T> *node) {
    if (node != nullptr) {
        deleteSubTree(node->left);
        deleteSubTree(node->right);
        delete node;
    }
}

#endif // BINARYTREE_H_INCLUDED
