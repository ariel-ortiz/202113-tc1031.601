#include <iostream>

// Complejidad: O(2^N)
void hanoi(
        int n,
        std::string origen,
        std::string auxiliar,
        std::string destino
        )
{
    static int paso_num = 0;

    if (n > 0) {
        hanoi(n - 1, origen, destino, auxiliar);
        ++paso_num;
        std::cout << paso_num << ". Mover disco " << n << " de " << origen
            << " a " << destino << "\n";
        hanoi(n - 1, auxiliar, origen, destino);
    }
}

int main()
{
    const int num_discos = 3;

    std::cout << "Solución a torres de Hanoi con "
        << num_discos << " discos\n";
    hanoi(num_discos, "A", "B", "C");

    return 0;
}