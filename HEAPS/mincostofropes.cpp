#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int mincost(vector<int>&arr,int &n){
     //min heap bna wahi min element milga
     priority_queue<int ,vector<int> ,greater<int>> pq;
     for(int i =0 ; i<n ;i++){
        pq.push(arr[i]);


     }
     int cost = 0;
     while(pq.size()>1){
        int a = pq.top(); //furst min mil gaya
        pq.pop();
        int b = pq.top(); // second mim mil gaya
         pq.pop();
        int sum = a+b;
        // cost jitna rope jorenge utna hi har bar badega
        cost = cost +sum ;
        pq.push(sum);// sum ko push kar diye wo ab agle ement se mil kar rope banega
        //sum ko value to cost me stroe kar chuke hai
        //phir agli baar sum aayega to cost me jud jagyga
        //last do element jude ga cost me add hoga tab push hoga 
        //queue me sum banke to 1 element bachefga while ka condition fail
        //liken hum cost me to ad kar chike hai sum socho dry run karo
     }

     return cost;


}

int main(){
    int size = 4;
    vector<int> arr(size);
    cout<<"enter the element"<< endl;
    for(int i = 0 ; i<size;i++){
        cin >> arr[i];
    }
    cout<<endl;
    
    int ans = mincost(arr,size);
    cout << " your cost to bind the ropes is " << ans;


}
 