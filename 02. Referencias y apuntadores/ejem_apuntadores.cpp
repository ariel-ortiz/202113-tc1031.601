#include <iostream>

int main()
{
    int i;  // i es un entero
    int *p; // p es un apuntador a entero

    i = 5;
    p = &i; // p apunta a la dirección de i

    std::cout << "i = " << i << std::endl;
    std::cout << "p = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;

    return 0;
}