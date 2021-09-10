#include <iostream>
#include "linkedlist.h"

struct Alumno {
    int matricula;
    std::string nombre;
};

int main()
{
    LinkedList<int> lista1;
    lista1.insert_front(5);
    lista1.insert_front(4);
    lista1.insert_front(3);
    LinkedList<std::string> lista2;
    LinkedList<double> lista3;
    LinkedList<Alumno> lista4;
    LinkedList<int> lista5;

    std::cout << lista1.to_string() << std::endl;
    std::cout << lista5.to_string() << std::endl;

    return 0;
}
