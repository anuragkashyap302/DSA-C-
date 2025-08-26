#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

bool isCyclicDFS(int node, int parent, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {
    visited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (isCyclicDFS(neighbor, node, visited, adj)) {
                return true;
            }
        }
        else if (neighbor != parent) {
            // Visited and not parent => cycle
            return true;
        }
    }

    return false;
}

bool detectCycle(int V, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> adj;

    // Create adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // Check every component
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, -1, visited, adj)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int V = 5;
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {3, 4}
    };

    if (detectCycle(V, edges)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
// This code detects cycles in an undirected graph using DFS.
// It uses a recursive approach to traverse the graph and checks for back edges.
// The function `isCyclicDFS` performs the DFS traversal and checks for cycles.
// The main function initializes the graph and calls the cycle detection function.