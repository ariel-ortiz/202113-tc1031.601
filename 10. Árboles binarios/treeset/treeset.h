#pragma once

#include <functional>
#include <initializer_list>
#include <queue>

template<typename T>
class TreeSet {

public:

    // Complejidad: O(1)
    TreeSet() {}

    // Complejidad: O(N log N)
    TreeSet(std::initializer_list<T> args)
    {
        for (T value : args) {
            add(value);
        }
    }

    // Complejidad: O(N)
    ~TreeSet()
    {
        _destroy(_root);
    }

    // Complejidad: O(log N)
    bool add(T value)
    {
        if (_root == nullptr) {
            _root = new Node(value);
            ++_size;
            return true;
        } else {
            Node* p = _root;
            while (true) {
                if (value == p->value) {
                    return false;
                } else if (value < p->value) {
                    if (p->left == nullptr) {
                        p->left = new Node(value);
                        ++_size;
                        return true;
                    } else {
                        p = p->left;
                    }
                } else {
                    if (p->right == nullptr) {
                        p->right = new Node(value);
                        ++_size;
                        return true;
                    } else {
                        p = p->right;
                    }
                }
            }
        }
    }

    // Complejidad: O(log N)
    bool contains(T value) const
    {
        return _contains(value, _root);
    }

    // Complejidad: O(N)
    void inorder(std::function<void(T)> fn) const
    {
        _inorder(fn, _root);
    }

    // Complejidad: O(N)
    void levelorder(std::function<void(T)> fn) const
    {
        std::queue<Node*> queue;

        queue.push(_root);

        while (not queue.empty()) {
            Node* p = queue.front();
            queue.pop();

            if (p != nullptr) {
                fn(p->value);
                queue.push(p->left);
                queue.push(p->right);
            }
        }
    }

private:

    struct Node {
        Node(T v): value(v) {}
        T value;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    void _destroy(Node* p)
    {
        if (p != nullptr) {
            _destroy(p->left);
            _destroy(p->right);
            delete p;
        }
    }

    bool _contains(T value, Node* p) const
    {
        if (p == nullptr) {
            return false;
        } else if (value == p->value) {
            return true;
        } else if (value < p->value) {
            return _contains(value, p->left);
        } else {
            return _contains(value, p->right);
        }
    }

    void _inorder(std::function<void(T)> fn, Node* p) const
    {
        if (p != nullptr) {
            _inorder(fn, p->left);
            fn(p->value);
            _inorder(fn, p->right);
        }
    }

    Node* _root = nullptr;
    int _size = 0;
};
