#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

struct Student {

    int id;
    std::string name;
    double grade_average;

    // Complejidad: O(1)
    std::string to_string() const
    {
        std::ostringstream result;
        result << "<Student " << id << ", " << name
            << ", " << grade_average << ">";
        return result.str();
    }

    // Complejidad: O(1)
    bool operator==(const Student& other) const
    {
        return id == other.id;
    }

    // Complejidad: O(1)
    bool operator<(const Student& other) const
    {
        return id < other.id;
    }
};

// Complejidad: O(1)
std::ostream& operator<<(
    std::ostream& out,
    const Student& student)
{
    return out << student.to_string();
}

// Complejidad: O(N)
template<typename T>
std::ostream& operator<<(
    std::ostream& out,
    const std::vector<T>& values)
{
    bool first_time = true;
    out << "{";
    for (T value : values) {
        if (first_time) {
            first_time = false;
        } else {
            out << ", ";
        }
        out << value;
    }
    return out << "}";
}

// Complejidad: O(N)
template<typename T>
int linear_search(const std::vector<T>& values, const T& target)
{
    for (int i = 0; i < values.size(); ++i) {
        if (values[i] == target) {
            return i;
        }
    }

    return -1;
}

// Complejidad: O(log N)
template<typename T>
int binary_search(const std::vector<T>& values, const T& target)
{
    int min = 0;
    int max = values.size() - 1;

    while (min <= max) {
        int mid = min + (max - min) / 2; // Equivalente a: (min + max) / 2
                                         // pero sin desbordar
        if (target < values[mid]) {
            max = mid - 1;

        } else if (values[mid] < target) {
            min = mid + 1;

        } else {
            return mid;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> a {4, 2, 0, -1, 6, 7, 2, 1, 8, 4};
    std::cout << "a = " << a << '\n';

    std::vector<std::string> b {
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
    std::cout << "b = " << b << '\n';

    std::vector<Student> c {
        {123, "Juan", 85.4},
        {299, "María", 99.9},
        {150, "Roberto", 77.5},
        {666, "Damián", 66.6}
    };

    std::cout << "c = " << c << '\n';

    int index = linear_search(a, 6);
    std::cout << "Linear search 6 in vector a: " << index << '\n';
    index = linear_search(a, 5);
    std::cout << "Linear search 5 in vector a: " << index << '\n';

    index = linear_search(b, std::string("octubre"));
    std::cout << "Linear search \"octubre\" in vector b: "
        << index << '\n';
    index = linear_search(b, std::string("inexistente"));
    std::cout << "Linear search \"inexistente\" in vector b: "
        << index << '\n';

    index = linear_search(c, {150, "", 0.0});
    std::cout << "Linear search id 150 in vector c: " << index << '\n';
    index = linear_search(c, {300, "", 0.0});
    std::cout << "Linear search id 300 in vector c: " << index << '\n';

    std::cout << "\nSorting all the vectors...\n";

    std::sort(a.begin(), a.end());
    std::cout << "a = " << a << '\n';

    std::sort(b.begin(), b.end());
    std::cout << "b = " << b << '\n';

    std::sort(c.begin(), c.end());
    std::cout << "c = " << c << '\n';

    index = binary_search(a, 2);
    std::cout << "Binary search 2 in vector a: " << index << '\n';
    index = binary_search(a, 5);
    std::cout << "Binary search 3 in vector a: " << index << '\n';

    index = binary_search(b, std::string("septiembre"));
    std::cout << "Binary search \"septiembre\" in vector b: "
        << index << '\n';
    index = binary_search(b, std::string("inexistente"));
    std::cout << "Binary search \"inexistente\" in vector b: "
        << index << '\n';

    index = binary_search(c, {123, "", 0.0});
    std::cout << "Binary search id 666 in vector 123: "
        << index << '\n';
    index = binary_search(c, {999, "", 0.0});
    std::cout << "Binary search id 999 in vector c: "
        << index << '\n';

    return 0;
}