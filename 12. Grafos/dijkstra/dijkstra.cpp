/*
 * Algoritmo de Dijkstra para calcular los caminos mínimos en un grafo.
 *
 * Código basado en implementación de Shubham Agrawal disponible
 * en:
 *
 *   https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
 */

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <climits>

const int infinity = INT_MAX;

struct Edge {
    std::string destination;
    int weight;
};

using Graph =
    std::map<std::string, std::vector<Edge>>;
using GraphKeyValuePair =
    std::pair<std::string, std::vector<Edge>>;

void add_edge(
    Graph& connections,
    std::string vertex_1,
    std::string vertex_2,
    int weight)
{
    connections[vertex_1].push_back(Edge {vertex_2, weight});
    connections[vertex_2].push_back(Edge {vertex_1, weight});
}


// Complejidad: O(V^2)
void dijkstra(Graph& connections, std::string start)
{
    std::queue<std::string> queue;
    queue.push(start);

    std::map<std::string, int> distance;
    for (GraphKeyValuePair pair : connections) {
        distance[pair.first] = infinity;
    }
    distance[start] = 0;

    while (not queue.empty()) {
        std::string current_vertex = queue.front();
        int current_weight = distance[current_vertex];
        queue.pop();
        for (Edge edge : connections[current_vertex]) {
            if (distance[edge.destination] > current_weight + edge.weight) {
                distance[edge.destination] = current_weight + edge.weight;
                queue.push(edge.destination);
            }
        }
    }

    std::cout << "Distance from " << start << '\n';
    for (GraphKeyValuePair pair : connections) {
        std::string vertex = pair.first;
        std::cout << vertex << ": " << distance[vertex] << '\n';
    }
}

int main()
{
    return 0;
}
