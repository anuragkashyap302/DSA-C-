#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
bool checkCycleDFS(int node ,unordered_map <int , bool> &visited,unordered_map <int , bool>& dfsvisited,unordered_map <int , list<int>> &adjlist){

    visited[node] = true;
    dfsvisited[node] = true;

    for(auto neighbour:adjlist[node]){
        if(!visited[neighbour]){
            //agar node ka parodsi visted nahi to recursive call mar diye
            bool cycleDetected = checkCycleDFS(neighbour,visited,dfsvisited,adjlist);
            if(cycleDetected)
            return true; //agar recursion lake deta hai cycle to true retkun kar do

        }
        // yaha tabhi aayeaga jab node visited ho nahi to if congition chalajayeg 
        //chek dfsvisted hai phele sse natlab cyle detected
        else if(dfsvisited[neighbour]){
                return true;

            }
    }
    // recrsoin se wapas jatte waqt node ka dfs visted false karte jao taki agar phir call aatya to pata chal sakee
    dfsvisited[node] = false;
    return false;

}
int detectCycleInDirectedGraph(int n , vector<pair <int , int>>&edges){
    //create adj list
    unordered_map <int , list<int>> adjlist;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        // dircted graph hai only one side connection

        adjlist[u].push_back(v);
    }
    unordered_map <int , bool> visited;
    unordered_map <int , bool> dfsvisited;

    //call dfs for all component
    for(int i = 0 ; i<= n ; i++){
        if(!visited[i]){
            bool cyclefound = checkCycleDFS(i , visited, dfsvisited,adjlist);
            if(cyclefound){
                return true;
            }
        }
    }

}
int main(){

}