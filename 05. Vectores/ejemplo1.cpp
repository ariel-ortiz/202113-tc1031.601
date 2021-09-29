#include <iostream>
#include <vector>

int main()
{
    std::vector<int> a(10, 42);
    a.reserve(1024);

    a.push_back(4);
    a.push_back(8);
    a.push_back(15);
    a.push_back(16);
    a.push_back(23);

    a.at(0) = 66;
    a.at(14) = 66;

    for (int i = 0; i < a.size(); ++i) {
        std::cout << a.at(i) << ' ';
    }
    std::cout << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << a.capacity() << std::endl;
}
