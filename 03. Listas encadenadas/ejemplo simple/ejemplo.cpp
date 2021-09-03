#include <iostream>

struct Node {
    int value;
    Node *next;
};

Node* insert_first(Node *first, int value)
{
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = first;
    return new_node;
}

void print_list(Node *first)
{
    while (first != nullptr) {
        std::cout << first->value << " ";
        first = first->next;
    }
    std::cout << std::endl;
}

int main()
{
    Node *lst = nullptr;
    lst = insert_first(lst, 5);
    lst = insert_first(lst, 10);
    lst = insert_first(lst, 15);
    print_list(lst);
    lst = insert_first(lst, 20);
    lst = insert_first(lst, 30);
    print_list(lst);
    return 0;
}
