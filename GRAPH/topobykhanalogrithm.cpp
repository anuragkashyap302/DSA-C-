#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

vector<int> dtopologicalsort(int n , vector<pair <int , int>>&edges){
    //create adj list n is no of node
    unordered_map <int , list<int>> adjlist;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        // dircted graph hai only one side connection

        adjlist[u].push_back(v);
    }
   
   // find all indgrees
   vector<int> indegree(n);
   for(auto i: adjlist){
    for(auto j : i.second){
        indegree[j]++;
    }
   }
   // 0 indgree walo ko push karo
   queue< int> q;
   for(int i = 0 ; i <n; i++){
    if(indegree[i]== 0){
        q.push(i);
    }
   }
   //do bfs
   vector <int> ans;


   while (!q.empty())
   {
    int front = q.front();
    q.pop();

    // ans me store karo
    ans.push_back(front);
    // neighbour ka indree update kar do

    for(auto neighbour:adjlist[front]){
        indegree[neighbour]--;
        if(indegree[neighbour]== 0){
            q.push(neighbour);
        }
    }

   }
   
return ans;
    

}
int main(){

}