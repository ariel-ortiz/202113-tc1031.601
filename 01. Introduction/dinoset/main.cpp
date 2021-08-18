#include <iostream>
#include "dinoset.h"

int main()
{
    DinoSet a;
    a.add(DinoId::velocirraptor);
    a.add(DinoId::triceratops);
    std::cout << a.to_string() << std::endl;
    std::cout << a.contains(DinoId::velocirraptor) << std::endl;
    std::cout << a.contains(DinoId::tiranosaurio) << std::endl;
    return 0;
}
