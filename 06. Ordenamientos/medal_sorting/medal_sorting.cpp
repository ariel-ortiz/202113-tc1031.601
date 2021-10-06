#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

struct Country {
    std::string name;
    int gold;
    int silver;
    int bronze;
};

bool compare_function(const Country& a, const Country& b)
{
    if (a.gold == b.gold) {
        if (a.silver == b.silver) {
            if (a.bronze == b.bronze) {
                return a.name < b.name;
            } else {
                return a.bronze > b.bronze;
            }
        } else {
            return a.silver > b.silver;
        }
    } else {
        return a.gold > b.gold;
    }
}

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        std::cerr << "Please specify the name of the input file.\n";
        std::exit(1);
    }

    std::string file_name = argv[1];
    std::ifstream file(file_name);
    if (file.fail()) {
        std::cerr << "Error when trying to open file.\n";
        std::exit(1);
    }

    std::string line;
    std::vector<Country> country_values;
    while (getline(file, line)) {
        std::istringstream file_stream(line);
        Country c;
        file_stream >> c.name;
        file_stream >> c.gold;
        file_stream >> c.silver;
        file_stream >> c.bronze;
        country_values.push_back(c);
    }
    file.close();

    std::stable_sort(
        country_values.begin(),
        country_values.end(),
        compare_function);

    for (Country c : country_values) {
        std::cout << c.name << ' '
            << c.gold << ' '
            << c.silver << ' '
            << c.bronze << '\n';
    }

    return 0;
}
