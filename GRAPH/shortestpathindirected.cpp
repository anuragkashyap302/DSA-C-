#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<stack>
using namespace std;
class Graph{
  public:
  unordered_map<int , list<pair<int ,int >>> adjlist;
  void addEdge(int u , int v , int weight){
    //ek pair p bano jo ki node and weight ka track rakhe
    pair<int,int> p = make_pair(v ,weight);

    adjlist[u].push_back(p); //node ke adj list me pair push kar do


  }
  void printAdj(){
    for(auto i: adjlist){
        cout << i .first << "->";
        for(auto j : i.second){
            //node ke andar ek list jisme us node se comnneted node and wight of egge hoga uso first and second se print kiye

            cout << "(" << j.first<<","<<j.second << ") ";


        }
        cout <<endl;
    }



  }

  void DFS(int node , unordered_map<int , bool >&vis , stack<int>&topo){
       vis[node] = true;

       for(auto neighbour: adjlist[node]){
            if(!vis[neighbour.first]){
                DFS(neighbour.first , vis , topo);
            }
       }

       topo.push(node);
  }

  void getshortestpath(int src , vector<int>&dist , stack<int> &topo){
    dist[src] = 0;

    while(!topo.empty()){
        int top = topo.top();

        topo.pop();

        if(dist[top]!= INT32_MAX){
   //top node ke adjlist me joa neighbour khijo dono ke beech me edges pe jo wight hai usko niklao
   //baki copy aur code dono ko dekho aur analiyas kato
            for(auto i:adjlist[top]){
                if(dist[top] + i.second < dist[i.first]){
                    dist[i.first] = dist[top] + i.second;
                }

            }
        }
    }

  }

};

int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    //topological sort
    int n = 6;
    unordered_map<int , bool > visited;
    stack<int> s;
    for(int i = 0 ;i< n; i++){
        if(!visited[i]){
           g.DFS(i,visited ,s);

        }
    }

    int src = 1;
    vector<int> dist(n);

    for(int i = 0 ; i< n; i++){
        dist[i] = INT32_MAX;
    }
 g.getshortestpath(src , dist ,s);

 cout << " ans is " << endl;

 for(int i = 0 ;  i <dist.size(); i++){

    cout << dist[i] <<" ";
 }
 cout<<endl;
    return 0;



}