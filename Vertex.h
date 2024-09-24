#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

template <typename T>
struct Vertex {
    T weight;
    int index;

    // Default constructor
    Vertex() : weight(T()), index(-1) {}
    Vertex(T w, int idx) : weight(w), index(idx) {}
    operator int() const {
        return index;
    }

    // Equality operator
    bool operator==(const Vertex& other) const {
        return index == other.index
            && weight == other.weight;
    }

    // Assignment operator to assign an int to weight
    Vertex& operator=(int value) {
        weight = value;
        return *this;
    }
};


#endif // VERTEX_H_INCLUDED
