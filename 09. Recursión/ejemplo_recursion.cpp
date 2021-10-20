#include <iostream>

// Complejidad: O(N)
long long factorial(int n)
{
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

//---------------------------------------------------------
// Operaciones básicas

// Complejidad: O(1)
int inc(int n)
{
    return n + 1;
}

// Complejidad: O(1)
int dec(int n)
{
    return n - 1;
}

// Complejidad: O(1)
bool is_zero(int n)
{
    return n == 0;
}

//---------------------------------------------------------
// Operaciones derivadas

// Complejidad: O(N)
int suma(int a, int b)
{
    if (is_zero(a)) {
        return b;
    } else {
        return inc(suma(dec(a), b));
    }
}

int main()
{
    std::cout << suma(3, 5) << '\n';
    return 0;
}
