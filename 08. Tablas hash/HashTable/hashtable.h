#pragma once

#include <stdexcept>

template<typename K, typename T>
class HashTable {

public:

    HashTable(const HashTable<K, T>&) = delete;
    HashTable<K, T>& operator=(const HashTable<K, T>&) = delete;

    // Complejidad: O(B)
    HashTable(int num_buckets)
    {
        _bucket = new Pair*[num_buckets];
        _num_buckets = num_buckets;
        _size = 0;
        for (int i = 0; i < _num_buckets; ++i) {
            _bucket[i] = new Pair;
        }
    }

    // Complejidad: O(N / B)
    bool put(K key, T value)
    {
        int hash = _hash(key);
        Pair *p = _bucket[hash]->next;
        while (p != nullptr) {
            if (key == p->key) {
                p->value = value;
                return false;
            }
            p = p->next;
        }
        Pair *new_pair = new Pair;
        new_pair->key = key;
        new_pair->value = value;
        new_pair->next = _bucket[hash]->next;
        _bucket[hash]->next = new_pair;
        ++_size;
        return true;
    }

    // Complejidad: O(N / B)
    bool contains_key(K key) const
    {
        int hash = _hash(key);
        Pair *p = _bucket[hash]->next;
        while (p != nullptr) {
            if (key == p->key) {
                return true;
            }
            p = p->next;
        }
        return false;
    }

    T get(K key) const
    {
        int hash = _hash(key);
        Pair *p = _bucket[hash]->next;
        while (p != nullptr) {
            if (key == p->key) {
                return p->value;
            }
            p = p->next;
        }
        throw std::invalid_argument("key not found");
    }

private:

    struct Pair {
        K key {};
        T value {};
        Pair *next { nullptr };
    };

    std::size_t _hash(K key) const
    {
        std::hash<K> h;
        return h(key) % _num_buckets;
    }

    Pair **_bucket;
    int _num_buckets;
    int _size;
};