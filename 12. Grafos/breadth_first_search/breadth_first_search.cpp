#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using Graph = std::unordered_map<std::string, std::vector<std::string>>;


// Complejidad: O(V + E)
//    V = # de vértices
//    E = # de aristas
void breadth_first_search(
    Graph& connections,
    std::string start,
    std::function<void(std::string)> fn)
{
    std::unordered_set<std::string> visited;
    std::queue<std::string> to_do;

    to_do.push(start);
    visited.insert(start);

    while (not to_do.empty()) {
        std::string current = to_do.front();
        to_do.pop();
        fn(current);
        for (std::string value : connections[current]) {
            if (visited.count(value) == 0) {
                to_do.push(value);
                visited.insert(value);
            }
        }
    }

}

int main()
{
    Graph connections {
        {"Mateo",     {"Marcos", "Lucas", "María"}},
        {"Marcos",    {"Juan"}},
        {"Lucas",     {"Marcos"}},
        {"Juan",      {"Lucas", "Mateo"}},
        {"María",     {"Lucas", "Marcos", "Magdalena"}},
        {"Magdalena", {"Marcos"}}
    };

    breadth_first_search(
        connections,
        "Juan",
        [] (std::string value) { std::cout << value << " "; }
    );

    std::cout << '\n';

    return 0;
}
