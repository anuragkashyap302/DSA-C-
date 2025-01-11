#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

vector<int> shortestpath(int n , vector<pair <int , int>>&edges , int src , int des){
    //create adj list n is no of node
    unordered_map <int , list<int>> adjlist;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        // undircted graph hai 

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);

    }
   
   // do bfs;

   queue< int> q;
   
    unordered_map<int, bool> visited;
     unordered_map<int, int> parent;

     // ab q me push karo sec ko
     q.push(src);
     visited[src] = true;


   while (!q.empty())
   {
    int front = q.front();
    q.pop();
   
//harek nesighbhour ko visit karke q me push
    for(auto neighbour:adjlist[front]){
       if(!visited[neighbour]){
        visited[neighbour] = true;
        parent[neighbour] = front;
        q.push(neighbour);

       }
    }

   }
   // abhi tak thumara parent array banke taiyer hai 

   //prepare shortest path
   vector <int> ans;
   int currnode = des;
   while(currnode != src){
    currnode = parent[currnode];
    //har baar ans push karte gye hmo waha tak pahne me jo element mila uska veator ans me chiye

    ans.push_back(currnode);
 //ans me des se src node tak ka vectoar element store hai 
 // hmko chiye src to des

   }


  // reverse(ans.begin() , ans.end());


   
return ans;
    

}
int main(){

}