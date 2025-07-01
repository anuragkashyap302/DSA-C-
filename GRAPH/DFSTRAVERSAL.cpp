#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <unordered_map>
using namespace std;

void solve(int node,unordered_map<int, bool>& visited,unordered_map<int, list<int>>& adjlist,  vector<int>& component) {
    component.push_back(node);
    visited[node] = true;

    //har node ke recursive call
    for(auto i: adjlist[node]){
        if(!visited[i]){
            solve(i , visited ,adjlist ,component);
        }
    }
}

vector<vector<int>> DFS(int V,int E, vector<pair<int, int>>& edges) {
    // Create adjacency list
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;


    // Traverse all components of the graph
    for (int i = 0; i < V; i++) {
        // Check if the node is visited
        if (!visited[i]) {
            vector<int> component;
            solve(i , visited,adjlist, component); // ek node ka jtna bhi coonection hoga usko ek vector me store karke ans me push kar diye
            ans.push_back(component);

        }
    }

    return ans;
}

int main() {
    int v = 5; // Number of nodes
    int e = 4;
    vector<pair<int, int>> edges = { {0, 1}, {0, 2}, {1, 3}, {2, 4} };

    vector< vector<int>> dfsResult = DFS(v,e, edges);
    

    for (int i = 0; i < dfsResult.size(); i++) {
        for(int j = 0 ;j < dfsResult[i].size(); j++){
            cout << dfsResult[i][j] << " ";
        }
    }

    return 0;
}
