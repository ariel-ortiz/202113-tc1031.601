#include <functional>
#include <iostream>
#include <unordered_set>

struct Student {
    const int id;
    const std::string name;
    const double grade_average;
    bool operator==(const Student& other) const
    {
        return id == other.id
            and name == other.name
            and grade_average == other.grade_average;
    }
};

namespace std {
    template<>
    class hash<Student> {
    public:
        /* Implementación de hashCode sugerida por:
         * Joshua Bloch
         * “Effective Java, Third Edition”
         * Addison-Wesley Professional, 2017.
         * Chapter 3, Item 11.
         */
        std::size_t operator() (const Student& s) const
        {
            std::hash<int> hi;
            std::hash<std::string> hs;
            std::hash<double> hd;

            std::size_t result = hi(s.id);
            result = 31 * result + hs(s.name);
            result = 31 * result + hd(s.grade_average);
            return result;
        }
    };
}

int main()
{
    std::hash<std::string> hs;
    std::string s = "hello";
    std::cout << "Data type:  string\n";
    std::cout << "Value:      " << s << '\n';
    std::cout << "Hash code:  " << hs(s) << '\n';
    std::cout << "Hash again: " << hs(s) << "\n\n";

    std::hash<int> hi;
    int i = 108;
    std::cout << "Data type:  int\n";
    std::cout << "Value:      " << i << '\n';
    std::cout << "Hash code:  " << hi(i) << '\n';
    std::cout << "Hash again: " << hi(i) << "\n\n";

    std::hash<double> hd;
    double d = 3.1416;
    std::cout << "Data type:  double\n";
    std::cout << "Value:      " << d << '\n';
    std::cout << "Hash code:  " << hd(d) << '\n';
    std::cout << "Hash again: " << hd(d) << "\n\n";

    std::hash<Student> stuhsh;
    Student st {123, "Juan", 98.5};
    std::cout << "Data type:  Student\n";
    std::cout << "Value:      {" << st.id << ", " << st.name
        << ", " << st.grade_average << "}\n";
    std::cout << "Hash code:  " << stuhsh(st) << '\n';
    std::cout << "Hash again: " << stuhsh(st) << '\n';

    // La clase Student cuenta con:
    // 1) Operador == sobrecargado
    // 2) Una clase epecializada hash para calcular su código hash
    // Por tanto, objetos de la clase Student pueden ser
    // contenidos en un unordered_set.
    std::unordered_set<Student> student_set {
        {101, "Marta", 95.0},
        {110, "María", 91.2},
        {199, "Mateo", 85.3},
        {202, "Marcos", 72.4},
        {299, "Lucas", 100.0},
        {123, "Juan", 98.5},
    };
    std::cout << std::boolalpha;
    std::cout << "Is Lucas in set? "
        << (student_set.count({299, "Lucas", 100.0}) == 1) << '\n';
    std::cout << "Is Damián in set? "
        << (student_set.count({666, "Damián", 66.6}) == 1) << '\n';

    return 0;
}
