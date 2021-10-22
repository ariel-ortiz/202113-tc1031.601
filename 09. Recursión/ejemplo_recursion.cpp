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

// Complejidad: O(A)
int suma(int a, int b)
{
    if (is_zero(a)) {
        return b;
    } else {
        return inc(suma(dec(a), b));
    }
}

// Complejidad: O(B)
int resta(int a, int b)
{
    if (is_zero(b)) {
        return a;
    } else {
        return dec(resta(a, dec(b)));
    }
}

// Complejidad: O(A * B)
int multiplicacion(int a, int b)
{
    if (is_zero(a)) {
        return 0;
    } else {
        return suma(b, multiplicacion(dec(a), b));
    }
}

// Complejidad: O(min(A, B))
bool menor_que(int a, int b)
{
    if (is_zero(a)) {
        if (is_zero(b)) {
            return false;
        } else {
            return true;
        }
    } else {
        if (is_zero(b)) {
            return false;
        } else {
            return menor_que(dec(a), dec(b));
        }
    }
}

// Complejidad: O([A / B] * [min(A, B) + B])
int division(int a, int b)
{
    if (menor_que(a, b)) {
        return 0;
    } else {
        return inc(division(resta(a, b), b));
    }
}

// Complejidad: O([A / B] * [min(A, B) + B])
int residuo(int a, int b)
{
    if (menor_que(a, b)) {
        return a;
    } else {
        return residuo(resta(a, b), b);
    }
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << residuo(20, 6) << '\n';
    return 0;
}
