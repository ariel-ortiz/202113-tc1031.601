#pragma once

#include <iostream>
#include <sstream>

template<typename T>
class LinkedList {

public:

    // Constructor por omisión
    // Complejidad: O(1)
    LinkedList()
    {

    }

    // Deshabilitar constructor de copiado
    LinkedList(const LinkedList<T>& other) = delete;

    // Deshabilitar operador de asignación
    LinkedList<T>& operator=(const LinkedList<T>& other) = delete;

    // Complejidad: O(N)
    ~LinkedList()
    {
        Node *p = _start;
        _start = nullptr;
        while (p != nullptr) {
            Node *current = p;
            p = p->next;
            delete current;
            current = nullptr;
        }
    }

    // Complejidad: O(N)
    std::string to_string() const
    {
        std::ostringstream result;
        result << "[";

        bool first_time = true;
        Node *p = _start;
        while (p != nullptr) {
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
    void insert_front(T value)
    {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = _start;
        _start = new_node;
        ++_size;
    }

    // Complejidad: O(1)
    int size() const
    {
        return _size;
    }

private:

    struct Node {
        T value;
        Node *next;
    };

    Node *_start = nullptr;
    int _size = 0;
};
