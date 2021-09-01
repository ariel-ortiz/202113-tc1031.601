#include <iostream>

int global;

void f(int *ptr) {
    ++(*ptr);
}

void g(int x) {
    ++x;
}

int main()
{
    int i;  // i es un entero
    int *p; // p es un apuntador a entero

    i = 5;
    p = &i; // p apunta a la dirección de i

    std::cout << "i  = " << i << std::endl;
    std::cout << "p  = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;
    std::cout << "&p = " << &p << std::endl;
    std::cout << "sizeof(i) = " <<  sizeof(i) << std::endl;
    std::cout << "sizeof(p) = " <<  sizeof(p) << std::endl;

    ++(*p);

    ++p; // aritmética de apuntadores

    std::cout << "i  = " << i << std::endl;
    std::cout << "p  = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;

    std::cout << "global = " << global << std::endl;
    std::cout << "&global = " << &global << std::endl;

    p = nullptr;
    std::cout << "p  = " << p << std::endl;
    // std::cout << "*p = " << *p << std::endl; // Produce segmentation fault

    int a = 10;
    std::cout << "a = " << a << std::endl;
    g(a);
    std::cout << "a = " << a << std::endl;
    f(&a);
    std::cout << "a = " << a << std::endl;

    return 0;
}
