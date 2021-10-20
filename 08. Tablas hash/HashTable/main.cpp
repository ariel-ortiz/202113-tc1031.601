#include <iostream>
#include "hashtable.h"

int main()
{
    HashTable<char, int> ht(10);
    ht.put('A', 1);
    ht.put('B', 2);
    ht.put('C', 3);
    std::cout << ht.get('B') << '\n';
    std::cout << ht.get('X') << '\n';
    return 0;
}
