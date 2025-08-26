 #include<bits/stdc++.h>
 using namespace std;


class DisjointSet {
   
    vector<int> rank , parent;
    vector<int> size;
    public:  
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } 
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
     void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
           
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            // size[ulp_u]++;
            // size[ulp_v]++;
          
        }
    }
 };

int main(){
        DisjointSet ds(7);
        ds.unionByRank(1, 2);
        ds.unionByRank(2, 3);
        ds.unionByRank(4, 5);
        ds.unionByRank(6, 7);
        ds.unionByRank(5, 6);
        // if 3 and 7 same or not
        if(ds.findUPar(3) == ds.findUPar(7)){
            cout << "Same\n";
        }
        else cout << "Not Same\n";
        ds.unionByRank(3, 7);
        if(ds.findUPar(3) == ds.findUPar(7)){
            cout << "Same\n";
        }
        else cout << "Not Same\n";
        return 0;
        // 1 - 2 - 3 - 7
        // 4 - 5 - 6  
        // time complexity O(4*alpha) ~ O(4)  
        // space complexity O(n)  
    }

