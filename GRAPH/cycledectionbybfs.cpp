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

bool isCyclicBFS(unordered_map<int, list<int>>& adjlist, unordered_map<int, bool>& visited,  int src) {
    queue<int> q;
    //parent ke ek map bana do
    unordered_map< int ,int> parent;
    parent[src] = -1;
    visited[src] = true;

    q.push(src);
    
    while (!q.empty()) {
        int frontnode = q.front();
        q.pop();

        // traverse all neighbors of front node
        //While traversing, if we encounter a visited neighbor that is not the parent of currfrontnode, a cycle exists cheak it.
        //If v is visited and not parent of u, then it's a back edge, indicating a cycle.
        for (auto neighbour: adjlist[frontnode]) {
            if (visited[neighbour] == true && neighbour!=parent[frontnode]) {
                return true;
               
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour]= frontnode;
            }
        }
    }
    return false;
}

string cycleDetection(int n, vector<pair<int, int>>& edges,int m) {
    // Create adjacency list
    unordered_map<int, list<int>> adjlist;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareadjlist(adjlist, edges);

    // Traverse all components of the graph
    for (int i = 0; i < n; i++) {
        // Check if the node is visited
        if (!visited[i]) {
           bool ans = isCyclicBFS(adjlist, visited ,i );
           if(ans== 1){
            return " yes";
           }
        }
    }

    return "no";
}

int main() {
    int n = 5; // Number of nodes
    vector<pair<int, int>> edges = { {0, 1}, {0, 2}, {1, 3}, {2, 4} };

    

    return 0;
}
/*
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

bool isCyclicBFS(int start, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {
    queue<pair<int, int>> q; // (node, parent)
    q.push({start, -1});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            }
            // If visited and not parent => cycle
            else if (neighbor != parent) {
                return true;
            }
        }
    }

    return false;
}

bool detectCycle(int V, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> adj;

    // Build adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // Handle disconnected components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicBFS(i, visited, adj)) {
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
*/
