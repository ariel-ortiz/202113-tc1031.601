#include <iostream>

struct Node {
    int value;
    Node *next;
};

int main()
{
    Node *lst;

    lst = new Node;
    lst->value = 5;
    lst->next = nullptr;

    Node *other;

    other = new Node;
    other->value = 10;
    other->next = nullptr;

    lst->next = other;

    std::cout << lst->value << " " << lst->next->value <<std::endl;

    delete lst;
    delete other;
}