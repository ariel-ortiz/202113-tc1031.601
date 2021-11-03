#include <iostream>
#include "intlist.h"
#include "recursion.h"

int main()
{
    IntList a;
    IntList b {4, 8, 15, 16, 23};

    std::cout << size(a) << '\n';
    std::cout << size(b) << '\n';
    std::cout << cons_end(5, a) << '\n';
    std::cout << cons_end(42, b) << '\n';
    std::cout << sum(a) << '\n';
    std::cout << sum(b) << '\n';
    std::cout << duplicate(a) << '\n';
    std::cout << duplicate(b) << '\n';
    std::cout << last(b) << '\n';

    return 0;
}
