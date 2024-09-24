#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include "BinaryTree.h"

template <typename T=int>
class BinarySearchTree : public BinaryTree<T> {
public:
    BinarySearchTree() : BinaryTree<T>() {}
    virtual ~BinarySearchTree() {}

    // Implementation of the pure virtual functions
    virtual bool insert(const T key);
    virtual bool remove(const T key);
    virtual BTreeNode<T>* find(const T key) const ;
    virtual void traverse() const;

private:
    // Helper functions to implement the required operations
    BTreeNode<T>* insertNode(BTreeNode<T>* node, T key);
    BTreeNode<T>* deleteNode(BTreeNode<T>* node, T key);
    BTreeNode<T>* searchNode(BTreeNode<T>* node, T key) const;
protected:
    // Inherited members to use directly
    using BinaryTree<T>::root;

    BTreeNode<T>* findMin(BTreeNode<T>* node) const;
    BTreeNode<T>* findMax(BTreeNode<T>* node) const;
};


template <typename T>
void BinarySearchTree<T>::traverse() const {
    this->inOrderTraversal(root);
    std::cout << std::endl;
}

// Helper function to insert for a node
template <typename T>
BTreeNode<T>* BinarySearchTree<T>::
    insertNode(BTreeNode<T>* node, T key) {

    if (node == nullptr)
        return new BTreeNode<T>(key);
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    return node;
}

template <typename T>
bool BinarySearchTree<T>::insert(const T key) {
    root = insertNode(root, key);
    return true;
}

// Helper function to search for a node
template <typename T>
BTreeNode<T>* BinarySearchTree<T>::
    searchNode(BTreeNode<T>* root, T key) const {
    if (root == nullptr || root->key == key)
        return root;
    if (key < root->key)
        return searchNode(root->left, key);
    return searchNode(root->right, key);
}


template <typename T>
BTreeNode<T>* BinarySearchTree<T>::
    find(const T key) const {

    return searchNode(root, key);
}

// Helper function to delete a node
template <typename T>
BTreeNode<T>* BinarySearchTree<T>::
    deleteNode(BTreeNode<T>* root, T key) {

    // Base case: If the root is nullptr, the tree is empty
    if (root == nullptr) return root;

    // Recur down the tree to find the node to delete
    if (key < root->key) {
        // The key to be deleted is in the left subtree
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        // The key to be deleted is in the right subtree
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: Node with only one child or no child
        if (root->left == nullptr) {
            // Node has no left child (or is a leaf node),
            // replace it with the right child
            BTreeNode<T>* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            // Node has no right child,
            // replace it with the left child
            BTreeNode<T>* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        // Get the inorder predecessor (maximum in the left subtree)
        BTreeNode<T>* temp = findMax(root->left);

        // Replace the node's key with the inorder predecessor's key
        root->key = temp->key;

        // Delete the inorder predecessor
        root->left = deleteNode(root->left, temp->key);
    }
    return root;
}


template <typename T>
bool BinarySearchTree<T>::remove(const T key) {
    size_t initialSize = this->getSize();
    root = deleteNode(root, key);;
    return this->getSize() < initialSize;
}


// Helper function to find the minimum value node
template <typename T>
BTreeNode<T>* BinarySearchTree<T>::findMin(BTreeNode<T>* node) const {
    BTreeNode<T>* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// Helper function to find the maximum value node
template <typename T>
BTreeNode<T>* BinarySearchTree<T>::findMax(BTreeNode<T>* node) const {
    BTreeNode<T>* current = node;
    while (current && current->right != nullptr)
        current = current->right;
    return current;
}
#endif // BINARYSEARCHTREE_H_INCLUDED
