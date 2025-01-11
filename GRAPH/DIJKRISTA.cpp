#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<set>
using namespace std;


vector<int> DIJKRISTA(vector<vector<int>>&vec , int vertices , int edges , int src){
    //create adj list n is no of node
    unordered_map <int , list<pair<int , int>>> adjlist; //wight bhi shmil hai na to adjlist aisa hi banega
    for(int i = 0; i<vertices; i++){
        int u = vec[i][0];
        int v = vec[i][1]; // 2d vector hai baua 1st col me u and 2nd colm me v and 3 col me wight of edges
        int w = vec[i][2];

        // udircted graph hai bothe side connection

        adjlist[u].push_back(make_pair(v ,w)); //list me node ka node ke sath  conection with edges wight
        adjlist[v].push_back(make_pair(u ,w));

    }
   //crition of distance array eith infinite value intiaaly
   vector<int> dist(vertices);
   for(int i = 0 ; i<vertices ; i++){
    dist[i]= INT32_MAX;

   }

   //creation of set 
   set<pair<int ,int>> st; //set value rakega node and distance of taht node from any nodes 
   dist[src] = 0;
   st.insert(make_pair(0 ,src)); //intially src node and distane dal diye src to src shortest dist 0 hi hoga na

    
    while (!st.empty())
    {
       //fetch top rcord
       auto top = *(st.begin());

       int nodedistance = top.first;
       int topnode = top.second;

       //remove the top record now
       st.erase(st.begin());

       //traversre on neighbours
       for(auto neighbour : adjlist[topnode]){
        if(nodedistance + neighbour.second < dist[neighbour.first]){
            //us  particualr node ka dist jo ki src nose se wha tk pahunche me laga hai plus neighbour ka jo dist hai wo dono jor ke hi destanitation pe pauchte hai src node ke hisab se
            //copy dekho

            auto record = st.find(make_pair(dist[neighbour.first] , neighbour.first));
            //pata karo koi aisa to nahi set me jo same node tak pahune ke jyada dist le raha ho to usko replce kar do mini dist wale se
            if(record != st.end()){
                st.erase(record);
            }

            //distance upadtae

            dist[neighbour.first] = nodedistance + neighbour.second;
            //ab minum wala record push kar do set me ki bhiya is node par is dist se pahuca ja sakta hai shortest way me phele wala bada tha
            st.insert(make_pair(dist[neighbour.first] , neighbour.first)); //us node ka dist and node value push kar diye

        }
       }
    }

    return dist;
}

int main(){
    return 0;
}