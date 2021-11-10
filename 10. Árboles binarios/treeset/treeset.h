#pragma once

#include <functional>
#include <initializer_list>

template<typename T>
class TreeSet {

public:

    TreeSet() {}

    TreeSet(std::initializer_list<T> args)
    {
        for (T value : args) {
            add(value);
        }
    }

    ~TreeSet()
    {
        _destroy(_root);
    }

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

    void inorder(std::function<void(T)> fn) const
    {
        _inorder(fn, _root);
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
