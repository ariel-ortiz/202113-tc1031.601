#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Se espera el nombre del archivo de entrada.\n";
        std::exit(1);
    }

    for (int i = 0; i < argc; ++i) {
        std::string s = std::string(argv[i]);
        std::cout << '[' << i << "] " << s << '\n';
    }

    return 0;
}
