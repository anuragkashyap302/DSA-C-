#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<stack>
using namespace std;
void topoSort(int node ,unordered_map <int , bool> &visited,unordered_map <int , list<int>> &adjlist,stack<int>&s){

    visited[node] = true;
    

    for(auto neighbour:adjlist[node]){
        if(!visited[neighbour]){
            
           topoSort(neighbour , visited , adjlist , s);
        }
        // recusion se wapas waqt push karo stachk me
        s.push(node);
        

}
}
vector<int> dtopologicalsort(int n , vector<pair <int , int>>&edges){
    //create adj list n is no of node
    unordered_map <int , list<int>> adjlist;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        // dircted graph hai only one side connection

        adjlist[u].push_back(v);
    }
    unordered_map <int , bool> visited;
    stack<int> s;
    
    //call dfs for all component
    for(int i = 0 ; i<= n ; i++){
        if(!visited[i]){
            topoSort(i , visited , adjlist , s);
        }

        
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
    

}
int main(){

}