#include <iostream>

struct Node {
    int value;
    Node *next;
};

// Complejidad: O(1)
Node* insert_first(Node *first, int value)
{
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = first;
    return new_node;
}


// Complejidad: O(N)
void print_list(Node *first)
{
    while (first != nullptr) {
        std::cout << first->value << " ";
        first = first->next;
    }
    std::cout << std::endl;
}

// Complejidad: O(N)
void free_list(Node *first)
{
    Node *current = first;
    while (first != nullptr) {
        first = first->next;
        delete current;
        current = first;
    }
}

// Complejidad: O(N)
int size(Node *first)
{
    int count = 0;
    while (first != nullptr) {
        ++count;
        first = first->next;
    }
    return count;
}

// Complejidad: O(N)
int sum(Node *first)
{
    int total = 0;
    while (first != nullptr) {
        total += first->value;
        first = first->next;
    }
    return total;
}

// Complejidad: O(N)
void dup(Node *first)
{
    while (first != nullptr) {
        // Node *new_node = new Node;
        // new_node->value = first->value;
        // new_node->next = first->next;
        // first->next = new_node;
        first->next = insert_first(first->next, first->value);
        first = first->next->next;
    }
}

int main()
{
    Node *lst = nullptr;
    lst = insert_first(lst, 5);
    lst = insert_first(lst, 10);
    lst = insert_first(lst, 15);
    std::cout << "size = " << size(lst) << std::endl;
    std::cout << "sum = " << sum(lst) << std::endl;
    print_list(lst);
    lst = insert_first(lst, 20);
    lst = insert_first(lst, 30);
    std::cout << "size = " << size(lst) << std::endl;
    std::cout << "sum = " << sum(lst) << std::endl;
    print_list(lst);
    dup(lst);
    std::cout << "size = " << size(lst) << std::endl;
    std::cout << "sum = " << sum(lst) << std::endl;
    print_list(lst);
    free_list(lst);
    return 0;
}
