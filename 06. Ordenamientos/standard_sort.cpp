#include <algorithm>
#include <iostream>
#include <vector>

void print(const std::vector<std::string>& values)
{
    for (std::string value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

bool mi_comparador(const std::string& a, const std::string& b)
{
    return a.size() < b.size();
}

int main()
{
    std::vector<std::string> values {
        "enero",
        "febrero",
        "marzo",
        "abril",
        "mayo",
        "junio",
        "julio",
        "agosto",
        "septiembre",
        "octubre",
        "noviembre",
        "diciembre"
    };

    print(values);
    std::sort(values.begin(), values.end(), mi_comparador);
    print(values);

    return 0;
}