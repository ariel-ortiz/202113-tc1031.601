#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<char> char_set {'a', 'b', 'c'};

    char_set.insert('d');
    char_set.insert('e');
    char_set.erase('b');

    std::cout << std::boolalpha;

    std::cout << "Set of chars: ";
    for (char c : char_set) {
        std::cout << c << ' ';
    }
    std::cout << '\n';

    std::cout << "Is c in set? "
        << (char_set.count('c') == 1) << '\n';
    std::cout << "Is x in set? "
        << (char_set.count('x') == 1) << '\n';

    std::unordered_set<int> int_set {4, 8, 15, 16, 23, 42};
    int_set.insert(108);

    std::cout << "Set of ints: ";
    for (int i : int_set) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::unordered_set<std::string> str_set {"uno", "dos", "tres"};
    std::cout << "Erasing tres: "
        << (str_set.erase("tres") == 1) << '\n';
    std::cout << "Erasing four: "
        << (str_set.erase("four") == 1) << '\n';
    std::cout << "Set of strings: ";
    for (std::string s : str_set) {
        std::cout << s << ' ';
    }
    std::cout << '\n';

    return 0;
}
