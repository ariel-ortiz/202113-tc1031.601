#include <iostream>

void swap1(int x, int y)
{
    int t = x;
    x = y;
    y = t;
}

void swap2(const int &x, const int &y)
{
    int t = x;
    x = y;
    y = t;
}

int main()
{
    int x = 5;
    int &r = x;  // r es una referencia (alias) a x

    std::cout << "x = " << x << std::endl;
    std::cout << "r = " << r << std::endl;

    ++r;

    std::cout << "x = " << x << std::endl;
    std::cout << "r = " << r << std::endl;

    int a = 10;
    int b = 25;

    std::cout << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << std::endl;
    swap1(a, b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << std::endl;
    swap2(a, b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}