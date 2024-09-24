#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#include "BinarySearchTree.h"
#include "BTreeNode.h"

template<typename T=int>
class AVLTree : public BinarySearchTree<T> {
public:
    AVLTree() : BinarySearchTree<T>() {}
    virtual ~AVLTree() { }

    // Interface Implementation
    virtual bool remove(const T);
    virtual bool insert(const T);
    virtual void print() const
    {
        this->inOrderTraversal(this->root);
    }

private:
    BTreeNode<T>* rightRotate(BTreeNode<T>* u);
    BTreeNode<T>* leftRotate(BTreeNode<T>* u);
    BTreeNode<T>* leftRightRotate(BTreeNode<T>* u);
    BTreeNode<T>* rightLeftRotate(BTreeNode<T>* u);
    BTreeNode<T>* balanceTree(BTreeNode<T>* u);

    BTreeNode<T>* insertAVL(BTreeNode<T>* u, T key);
    BTreeNode<T>* deleteAVL(BTreeNode<T>* u, T key);

protected:
    // Inherited members to use directly
    using BinarySearchTree<T>::root;

    void updateHeight(BTreeNode<T>* node);
    int getBalance(BTreeNode<T>* node) const;
};

template<typename T>
BTreeNode<T>* AVLTree<T>::rightRotate(BTreeNode<T>* y) {
    // (1) The left child of y, pointer as x
    BTreeNode<T>* x = y->left;
    // (2) The right child of x, pointer as z
    BTreeNode<T>* z = x->right;
    // (3) y becomes the right child of x
    x->right = y;
    // (4) Update the left child of y to be z
    y->left = z;
    // (5) Update the heights of y and x
    updateHeight(y);
    updateHeight(x);
    // Return new root
    return x;
}

template<typename T>
BTreeNode<T>* AVLTree<T>::leftRotate(BTreeNode<T>* x) {
    // (1) The right child of x, pointer as y
    BTreeNode<T>* y = x->right;
    // (2) The left child of y, pointer as z
    BTreeNode<T>* z = y->left;
    // (3) x becomes the left child of y
    y->left = x;
    // (4) Update the right child of x to be z
    x->right = z;
    // (5) Update the heights of x and y
    updateHeight(x);
    updateHeight(y);
    // Return new root
    return y;
}

template<typename T>
BTreeNode<T>* AVLTree<T>::leftRightRotate(BTreeNode<T>* u) {
    // (1) Perform a LR on the left child of the root
    u->left = leftRotate(u->left);
    // (2) Perform a RR on the root
    return rightRotate(u);
}

template<typename T>
BTreeNode<T>* AVLTree<T>::rightLeftRotate(BTreeNode<T>* u) {
    // (1) Perform a RR on the right child of the root
    u->right = rightRotate(u->right);
    // (2) Perform a left rotation on the root
    return leftRotate(u);
}

template<typename T>
BTreeNode<T>* AVLTree<T>::insertAVL(BTreeNode<T>* u, T key) {
    // Step 1: Perform standard BST insertion
    if (u == nullptr) {
        return new BTreeNode<T>(key);
    }

    if (key < u->key) {
        u->left = insertAVL(u->left, key);
    } else if (key > u->key) {
        u->right = insertAVL(u->right, key);
    } else {
        // Duplicate keys are not allowed
        return u;
    }

    // Step 2: Update the height of the current node
    updateHeight(u);

    // Step 3: Check and Balance the tree
    return balanceTree(u);
}

template<typename T>
bool AVLTree<T>::insert(const T key) {
    root = insertAVL(root, key);
    return true;
}

template<typename T>
BTreeNode<T>* AVLTree<T>::deleteAVL(BTreeNode<T>* root, T key) {
    if (root == nullptr) return root;

    // Step 1: Perform standard BST deletion
    if (key < root->key) {
        root->left = deleteAVL(root->left, key);
    } else if (key > root->key) {
        root->right = deleteAVL(root->right, key);
    } else {
         // Node with only one child or no child
        if (root->left == nullptr ||
                root->right == nullptr) {
            BTreeNode<T>* temp = root->left ?
                                root->left : root->right;
            if (temp == nullptr) {
                // No child case
                temp = root;
                root = nullptr;
            } else {
                // One child case
                *root = *temp;
            }
            delete temp;
        } else {
            // Node with two children
            // Get the inorder successor
            BTreeNode<T>* temp = this->findMin(root->right);
            root->key = temp->key;
            root->right = deleteAVL(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;

    // Step 2: Update the height of the current node
    updateHeight(root);

    // Step 3: Check and balance the tree
    return balanceTree(root);
}


template<typename T>
bool AVLTree<T>::remove(const T key) {
    size_t initialSize = this->getSize();
    root = deleteAVL(root, key);
    return this->getSize() < initialSize;
}


template<typename T>
void AVLTree<T>::updateHeight(BTreeNode<T>* u) {
    if (u != nullptr) {
        u->height = 1 + std::max(this->height(u->left),
                                this->height(u->right));
    }
}

template<typename T>
int AVLTree<T>::getBalance(BTreeNode<T>* u) const {
    if (u == nullptr) return 0;
    return this->height(u->left) - this->height(u->right);
}


template<typename T>
BTreeNode<T>* AVLTree<T>::balanceTree(BTreeNode<T>* u) {
    int balance = getBalance(u);

    if (balance > 1) {
        // Left subtree is taller
        if (getBalance(u->left) >= 0) {
            return rightRotate(u);
        } else {
            return leftRightRotate(u);
        }
    } else if (balance < -1) {
        // Right subtree is taller
        if (getBalance(u->right) <= 0) {
            return leftRotate(u);
        } else {
            return rightLeftRotate(u);
        }
    }
    return u;
}

#endif // AVLTREE_H_INCLUDED
