#include <iostream>
#include "dinoset.h"

int main()
{
    DinoSet a;
    DinoSet b;
    DinoSet c;

    a.add(DinoId::velocirraptor);
    a.add(DinoId::triceratops);
    b.add(DinoId::triceratops);
    b.add(DinoId::pteranodon);

    c = a + b;

    std::cout << c.to_string() << std::endl;
    std::cout << c.size() << std::endl;

    return 0;
}
