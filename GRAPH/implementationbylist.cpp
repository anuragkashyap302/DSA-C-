#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
class graph {
    public:
    unordered_map <int ,list<int> > adj; //map ek int amd usse related list ka hisab rakega
    void addEdge (int u ,int v , bool direction){
        //direction = 0 -> undirected graph indicating both side
        //direction = 1 -> directed graph  indicating one side 

        // create a edge form u to v
        adj[u].push_back(v); // adj wale map me  u int ko v se conenct kar diye aur bhi ho sakta hai list me

        if(direction == 0){
            // undirected graph hai v ka bhi u se connection hona chiye
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i : adj){
            cout << i.first << " -> "; //map ke first koi int store hoga phle usko print karo
            for( auto j: i.second){
                cout << j << ", "; // us number se conected jo bhi para hai list me sabko print
            }
            cout << endl;

        }
    }

};

// by using vector
vector < vector <int >> printAdjancy(int n , int m , vector < vector <int >> edges){
    vector< int> ans[n];
    for(int i = 0 ; i < m; i++){
        int u = edges[i][0]; //vector ke ith row and 1st col me u milga
        int v = edges[i][1]; // vector ke ith row and 2nd col me v milaga
        //dono ko ans me push kardo kyki u and v ke bich me edges hai
        ans[u].push_back(v); //ans ke uth elemnbt ke liye v push
        ans[v].push_back(u); // ans ke vth elment ke liye u push matabal v se u me coonection hai edge ka
    }

    vector < vector <int >> adj; // ek 2d vector jo kisi elemnbt ke all connection ka lisit ragaka e.g for 0th use undur ek vector jo 0 se connected hoga and so on for 1th element
    for(int i = 0 ; i<n; i++){
        adj[i].push_back(i); //khud ka kud se conecton
        for(int j = 0; j< ans[i].size();j++){
           adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

int main(){

    int n ; 
    cout << " Enter the number of nodes" << endl;
    cin >> n;

    int m ;
    cout << " Enter the number of edges" << endl;
    cin  >> m;

    graph G;

    for( int i = 0 ; i<n ; i++){
        int u , v;
        cin >> u >> v ;
        // creating an undricerd graph
      G.addEdge(u,v , 0); // u&v me edge bna ke lao
    }

    //printing 
    G.printAdjList();

    return 0;

}