#ifndef SKIPLIST_H_INCLUDED
#define SKIPLIST_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SKNode.h"


template <typename T>
class SkipList : public ISet<T> {
public:
    SkipList(int maxLevel, float probability);
    ~SkipList();

    // Inserts a value into the skip list
    bool add(const T value);

    // Removes a value from the skip list
    bool remove(const T value);

    // Searches for a value in the skip list
    bool contains(const T value) const;

    // Clears the skip list
    void clear();

    // Displays the contents of the skip list
    void print() const;

private:
    int maxLevel;
    float probability;
    SKNode<T>* head;

    // Function to determine the random level for a new node
    int randomLevel();
};

// Constructor
template <typename T>
SkipList<T>::SkipList(int maxLevel, float probability)
    : maxLevel(maxLevel), probability(probability) {
    // Initialize head node with dummy value
    head = new SKNode<T>(maxLevel, T());
    // Seed the random number generator
    srand(time(nullptr));
}

// Destructor
template <typename T>
SkipList<T>::~SkipList() {
    clear();
    delete head;
}

// Random level generation based on the given probability
template <typename T>
int SkipList<T>::randomLevel() {
    int level = 0;
    while ((rand() / double(RAND_MAX)) < probability && level < maxLevel) {
        level++;
    }
    return level;
}

// Add a new value to the skip list
template <typename T>
bool SkipList<T>::add(const T value) {
    DynamicArray<SKNode<T>*> update(maxLevel + 1);
    SKNode<T>* curr = head;

    // Find the position to insert
    for (int i = maxLevel; i >= 0; i--) {
        while (curr->forward[i] != nullptr && curr->forward[i]->value < value) {
            curr = curr->forward[i];
        }
        update[i] = curr;
    }

    curr = curr->forward[0];

    // If value already exists, return false
    if (curr != nullptr && curr->value == value) {
        return false;
    }

    // Determine the level for the new node
    int level = randomLevel();
    SKNode<T>* newNode = new SKNode<T>(level, value);

    // Insert the new node and update forward pointers
    for (int i = 0; i <= level; i++) {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }

    this->size++;
    return true;
}

// Remove a value from the skip list
template <typename T>
bool SkipList<T>::remove(const T value) {
    DynamicArray<SKNode<T>*> update(maxLevel + 1);
    SKNode<T>* curr = head;

    // Find the position to remove
    for (int i = maxLevel; i >= 0; i--) {
        while (curr->forward[i] != nullptr && curr->forward[i]->value < value) {
            curr = curr->forward[i];
        }
        update[i] = curr;
    }

    curr = curr->forward[0];
    if (curr == nullptr || curr->value != value) {
        return false;  // Value not found
    }

    // Update forward pointers and delete the node
    for (int i = 0; i <= maxLevel; i++) {
        if (update[i]->forward[i] != curr) {
            break;
        }
        update[i]->forward[i] = curr->forward[i];
    }

    delete curr;
    this->size--;
    return true;
}

// Check if the skip list contains a given value
template <typename T>
bool SkipList<T>::contains(const T value) const {
    SKNode<T>* curr = head;
    for (int i = maxLevel; i >= 0; i--) {
        while (curr->forward[i] != nullptr && curr->forward[i]->value < value) {
            curr = curr->forward[i];
        }
    }
    curr = curr->forward[0];
    return curr != nullptr && curr->value == value;
}

// Clear the skip list
template <typename T>
void SkipList<T>::clear() {
    SKNode<T>* curr = head->forward[0];
    while (curr != nullptr) {
        SKNode<T>* next = curr->forward[0];
        delete curr;
        curr = next;
    }
    for (int i = 0; i <= maxLevel; i++) {
        head->forward[i] = nullptr;
    }
    this->size = 0;
}

// Print the skip list
template <typename T>
void SkipList<T>::print() const {
    for (int i = maxLevel; i >= 0; i--) {
        SKNode<T>* current = head->forward[i];
        std::cout << "Level " << i << ": ";
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->forward[i];
        }
        std::cout << std::endl;
    }
}

#endif // SKIPLIST_H_INCLUDED
