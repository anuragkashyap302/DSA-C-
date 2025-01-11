#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <set>
using namespace std;

vector<pair<pair<int, int>, int>> PRIM(vector<pair<pair<int, int>, int>>& g, int vertices, int edges, int src) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adjlist;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        // Undirected graph: both sides connection
        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    // Initialization of distance array with infinite value initially
    vector<bool> mst(vertices + 1, false);
    vector<int> dist(vertices + 1, INT32_MAX);
    vector<int> parent(vertices + 1, -1);

    // Start the algorithm
    // Indexing starting from 1 (assuming 1-based index)
    //indxing me confuse mat hona
    dist[src] = 0;
    parent[src] = -1;

    for (int i = 1; i < vertices; i++) {
        int mini = INT32_MAX;
        int u;

        // Find the minimum weight node
        for (int v = 1; v <= vertices; v++) {
            if (!mst[v] && dist[v] < mini) {
                u = v;
                mini = dist[v];
            }
        }

        // Mark the minimum node as true
        mst[u] = true;

        // Check its adjacency list
        for (auto it : adjlist[u]) {
            int v = it.first;
            int w = it.second;

            if (!mst[v] && w < dist[v]) {
                parent[v] = u;
                dist[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    //i 2 se chelaga kyki aary 1 se start ho raha hai and 1st element yani src ka koi parnet to hai nahi
    for (int i = 2; i <= vertices; i++) {
        if (parent[i] != -1) { // Ensure there is a parent
            result.push_back({{parent[i], i}, dist[i]});
        }
    }
    return result;
}

int main() {
    // Example usage:
    vector<pair<pair<int, int>, int>> graph = {{{1, 2}, 1}, {{1, 3}, 4}, {{2, 3}, 2}, {{2, 4}, 5}, {{3, 4}, 3}};
    int vertices = 4;
    int edges = 5;
    int src = 1;

    vector<pair<pair<int, int>, int>> mst = PRIM(graph, vertices, edges, src);

    for (auto edge : mst) {
        cout << "Edge: (" << edge.first.first << ", " << edge.first.second << ") with weight: " << edge.second << endl;
    }

    return 0;
   
}