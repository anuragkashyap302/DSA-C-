#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void heapify(vector<int>ans , int n , int i){
    int largestidx = i;// man ke chele cuur node largest hai
    int left = 2*i;
    int right = 2*i +1;
    if(left<=n && ans[largestidx]<ans[left]){
        largestidx = left;
    }
    if(right<=n && ans[largestidx]<ans[right]){
        largestidx = right;
    }
    // jo children bada tha wo largest index me aa gya 
    // largset index wale element ko cuur yani  rroot index wale element se  usse swap kar do kyki asli haqdar wahi hai us position ka

    if(largestidx!= i){//agar ye cond sahi
        // matalb largest index badal chuka
        swap(ans[largestidx],ans[i]);
        // ab largest idx me cuur index ka element pahuch gya to usko bhi
        // hepify hone bhej
        heapify(ans,n,largestidx);//largest naam ka index pass kar rahe hai
        // confuse not
        //kiye curr index hepify ho gya ek pass me ab age balla ho ga
        
    }
}


vector<int> mergeheaps(vector<int>&a ,vector<int>&b,int n ,int m){
    // dno vector ko merge kar diye ek me
    vector<int> ans;
    ans.push_back(-1);//oth index -1 thus diye koi kaam nhi hai
    //iska hum yaha indxing 1 se chalu kar rahe hai
    // o se bhi kar sakte hai left and right ka formauala badla jayega
    for(auto i :a){
        ans.push_back(i);

    }
    for(auto i:b){
        ans.push_back(i);
    }
    // ab ek vector hoguya isko hepify kar do be
     int size = ans.size();
     for(int i= size/2;i>0;i--){
        //leaf node chor ke hepify kiye size/2 to size leaf node hota hai na
        heapify(ans,size,i);//jis node heapify karna hai uska index pass
     }
}
int main(){
    int size =5;
    int arr[size];
    cout << "enter the element of array" << endl;
    for(int i =0 ; i<size; i++){
        cin>>arr[i];
    }
  cout <<"enter the value of k"<< endl;
    int k ;
    cin >> k;
    //maxheap ke liye 
    priority_queue <int> pq;
    //first k element ko heap bna do
    for(int i = 0;i<k;i++){
        pq.push(arr[i]);
    }
    //now chrek for rest of element
    for(int i = k ; i<size ; i++){
        if(arr[i]< pq.top()){
            pq.pop();
            pq.push(arr[i]);

        }
    }
    // lop se nikale ke  badd ans hep ke top pe hoga 
    int ans = pq.top();
    cout<< ans ;

}
 