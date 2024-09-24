#ifndef PAIR_H_INCLUDED
#define PAIR_H_INCLUDED

template <typename K, typename V>
struct Pair {
    K key;
    V value;

    // Default constructor
    Pair() : key(K()), value(V()) {}

    Pair(K k, V v) : key(k), value(v) {}

    // Overloading equality operator for comparison
    bool operator==(const Pair& other) const {
        return key == other.key;
    }

    // Implicit conversion to key type
    operator K() const {
        return key;
    }

    // Overload the stream output operator
    friend std::ostream& operator<<(std::ostream& os, const Pair& p) {
        os << "(" << p.key << ", " << p.value << ")";
        return os;
    }
};


#endif // PAIR_H_INCLUDED
