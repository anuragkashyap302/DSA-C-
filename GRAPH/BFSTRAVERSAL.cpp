#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <unordered_map>
using namespace std;

void prepareadjlist(unordered_map<int, list<int>>& adjlist, vector<pair<int, int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

void solve(unordered_map<int, list<int>>& adjlist, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontnode = q.front();
        q.pop();

        // store the front into ans
        ans.push_back(frontnode);

        // traverse all neighbors of front node
        for (auto i : adjlist[frontnode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int n, vector<pair<int, int>>& edges) {
    // Create adjacency list
    unordered_map<int, list<int>> adjlist;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareadjlist(adjlist, edges);

    // Traverse all components of the graph
    for (int i = 0; i < n; i++) {
        // Check if the node is visited
        if (!visited[i]) {
            solve(adjlist, visited, ans, i);
        }
    }

    return ans;
}

int main() {
    int n = 5; // Number of nodes
    vector<pair<int, int>> edges = { {0, 3}, {3, 1}, {1, 2}, {1, 4} };

    vector<int> bfsResult = BFS(n, edges);

    for (int i = 0; i < bfsResult.size(); i++) {
        cout << bfsResult[i] << " ";
    }

    return 0;
}
