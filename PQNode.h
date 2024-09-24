#ifndef PQNODE_H_INCLUDED
#define PQNODE_H_INCLUDED

#include <iostream>

template <typename T>
class PQNode {
public:
    T data;
    int priority;

    // Default constructor
    PQNode() : data(T()), priority(0) {}

    // Parameterized constructor
    PQNode(T data) :
        data(data),priority(0) {}
    PQNode(T data, int priority) :
        data(data), priority(priority) {}

    // Copy constructor
    PQNode(const PQNode<T>& other) :
        data(other.data), priority(other.priority) {}

    // Move constructor
    PQNode(PQNode<T>&& other) noexcept :
        data(std::move(other.data)), priority(other.priority) {}

    // Assignment operator
    PQNode<T>& operator=(const PQNode<T>& other) {
        if (this != &other) {
            data = other.data;
            priority = other.priority;
        }
        return *this;
    }

    // Equality operator
    bool operator==(const PQNode<T>& other) const {
        return data == other.data
        && priority == other.priority;
    }


    // Operator overloading to compare PQNode objects
    bool operator<(const PQNode& other) const {
        return this->priority < other.priority;
    }

    bool operator>(const PQNode& other) const {
        return this->priority > other.priority;
    }

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const PQNode<T>& node) {
    os << "{ Data: " << node.data << ", Priority: " << node.priority << " }";
    return os;
}

#endif // PQNODE_H_INCLUDED

