#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int source) {
    vector<int> dist(V, numeric_limits<int>::max());
    dist[source] = 0;

    for (int i = 1; i <= V - 1; ++i) {
        for (auto edge : edges) {
            if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    for (auto edge : edges) {
        if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight < dist[edge.v]) {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }

    for (int i = 0; i < V; ++i) {
        cout << "Distance from source to " << i << ": " << (dist[i] == numeric_limits<int>::max() ? "INF" : to_string(dist[i])) << endl;
    }
}

int main() {
    int V = 5; 
    int E = 8;
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {2, 3, 5}, {3, 4, -3}, {4, 2, 1}
    };
    
    bellmanFord(V, E, edges, 0);

    return 0;
}
