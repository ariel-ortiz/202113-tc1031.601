#include <iostream>
#include <vector>
#include "treeset.h"

void visita(int value)
{
    std::cout << value << ' ';
}

int main()
{
    TreeSet<int> t {10, 5, 15, 13, 20, 14};

    t.levelorder(visita);

    std::cout << '\n';

    return 0;
}
