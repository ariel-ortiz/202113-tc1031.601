#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>

template<typename T>
class LinkedList {

public:

    // Constructor por omisión
    // Complejidad: O(1)
    LinkedList()
    {
        _sentinel = new Node;
        _sentinel->next = _sentinel;
        _sentinel->prev = _sentinel;
        _size = 0;
    }

    // Constructor a partir de lista de inicialización
    // Complejidad: O(N)
    LinkedList(std::initializer_list<T> args): LinkedList()
    {
        for (T arg: args) {
            insert_back(arg);
        }
    }

    // Deshabilitar constructor de copiado
    LinkedList(const LinkedList<T>& other) = delete;

    // Deshabilitar operador de asignación
    LinkedList<T>& operator=(const LinkedList<T>& other) = delete;

    // Destructor
    // Complejidad: O(N)
    ~LinkedList()
    {
        Node *p = _sentinel->next;
        while (p != _sentinel) {
            Node *current = p;
            p = p->next;
            delete current;
            current = nullptr;
        }
        delete _sentinel;
        _sentinel = nullptr;
    }

    // Complejidad: O(N)
    std::string to_string() const
    {
        std::ostringstream result;
        result << "[";

        bool first_time = true;
        Node *p = _sentinel->next;
        while (p != _sentinel) {
            if (first_time) {
                first_time = false;
            } else {
                result << ", ";
            }
            result << p->value;
            p = p->next;
        }

        result << "]";
        return result.str();
    }

    // Complejidad: O(1)
    int size() const
    {
        return _size;
    }

    // Complejidad: O(1)
    bool is_empty() const
    {
        return size() == 0;
    }

    // Complejidad: O(1)
    void insert_front(T value)
    {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = _sentinel->next;
        new_node->prev = _sentinel;
        _sentinel->next->prev = new_node;
        _sentinel->next = new_node;
        ++_size;
    }

    // Complejidad: O(1)
    void insert_back(T value)
    {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = _sentinel;
        new_node->prev = _sentinel->prev;
        _sentinel->prev->next = new_node;
        _sentinel->prev = new_node;
        ++_size;
    }

    // Complejidad: O(1)
    T remove_front()
    {
        if (is_empty()) {
            throw std::length_error(
                "Can't remove form the front of an empty list");
        }
        Node *current = _sentinel->next;
        _sentinel->next = current->next;
        current->next->prev = _sentinel;
        T result = current->value;
        delete current;
        current = nullptr;
        --_size;
        return result;
    }

private:

    struct Node {
        T value;
        Node *next;
        Node *prev;
    };

    Node *_sentinel;
    int _size;
};
