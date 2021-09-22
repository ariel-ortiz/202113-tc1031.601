#include <iostream>
#include "linkedlist.h"

struct Alumno {
    int matricula;
    std::string nombre;
};

int main()
{
    LinkedList<int> lista1 {5, 4, 3};
    LinkedList<std::string> lista2 {"a", "b", "c", "d", "e"};
    LinkedList<double> lista3;
    LinkedList<Alumno> lista4;
    LinkedList<int> lista5;

    std::cout << lista1.to_string() << std::endl;
    std::cout << lista2.to_string() << std::endl;

    return 0;
}
