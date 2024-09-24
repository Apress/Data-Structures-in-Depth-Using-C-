#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "ChainedHashTable.h"
#include "Pair.h"
#include <stdexcept>

template <typename K, typename V>
class Map {
public:
    Map(int buckets=64) : table(buckets) {}

    // Inserts a key-value pair into the map
    void add(K key, V value);

    // Removes a key-value pair from the map
    void remove(K key);

    // Looks up the value associated with a key
    const V& get(K key) const;
    V &get(K key);

    // Get all key-value pairs
    DynamicArray<Pair<K, V>> getAll() const;

    // Print the contents of the map
    void print() const;

    size_t getSize() const {
        return table.getSize();
    }

    // Checks if a key exists in the map
    bool contains(K key) const;

private:
    ChainedHashTable<Pair<K, V>> table;
};

template <typename K, typename V>
void Map<K, V>::add(K key, V value) {
    table.add(Pair<K, V>(key, value));
}

template <typename K, typename V>
void Map<K, V>::remove(K key) {
    Pair<K, V> temp(key, V());
    table.remove(temp);
}

template <typename K, typename V>
const V& Map<K, V>::get(K key) const{
    Pair<K, V> temp(key, V());
    if (table.contains(temp)) {
        auto& bucket = table.get(temp);

        for (size_t i = 0; i < bucket.getSize(); ++i) {
            if (bucket.get(i).key == key) {
                return bucket.get(i).value;
            }
        }
    }
    throw std::runtime_error("Key not found");
}

template <typename K, typename V>
V& Map<K, V>::get(K key) {
    Pair<K, V> temp(key, V());
    if (table.contains(temp)) {
        auto& bucket = table.get(temp);

        for (size_t i = 0; i < bucket.getSize(); ++i) {
            if (bucket.get(i).key == key) {
                return bucket.get(i).value;
            }
        }
    }
    throw std::runtime_error("Key not found");
}

template <typename K, typename V>
void Map<K, V>::print() const {
    table.print();
}
/** NOT IN BOOK **/
template <typename K, typename V>
DynamicArray<Pair<K, V>> Map<K, V>::getAll() const {
    return table.getAll();
}

template <typename K, typename V>
bool Map<K, V>::contains(K key) const {
    try {
        get(key);
        return true;
    } catch (const std::runtime_error&) {
        return false;
    }
}
#endif // MAP_H_INCLUDED
