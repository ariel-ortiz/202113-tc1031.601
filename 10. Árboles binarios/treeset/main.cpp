#include <iostream>
#include <vector>
#include "treeset.h"

int main()
{
    TreeSet<int> t {10, 5, 15, 13, 20, 14};

    t.levelorder([&] (int value) { std::cout << value << ' '; });

    std::cout << '\n';

    int suma = 0;

    t.levelorder([&] (int value) { suma += value; });

    std::cout << suma << '\n';

    return 0;
}
