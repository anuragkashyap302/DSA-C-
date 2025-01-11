#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<long long>printfirstnegativeinteger(long long int a[],long long int n,long long int k){
   deque<long long int> dq;
   vector<long long> ans;
   //process first window of k size
   for(int i=0;i<k;i++){
    if(a[i]<0){
        dq.push_back(i);

    }
   }

   //store ans of first k sized window 
   if(dq.size()>0){
    ans.push_back(a[dq.front()]);//vector me dalo q ke front me jo arr ka index haiyani first negative usko ans bana do
   }
   else{
    ans.push_back(0);
   }
   //process for remaing window
   for(int i=k; i<n;i++){
    //removal of extra jo next window me hmko nahi chaiyjie
    if(!dq.empty()&& i-dq.front()>=k){ //ye concept index ko dhyan me rakhte hue lgaya gya hai front me index store hai na ki arr ka element
        dq.pop_front();

    }
    //aditon of next element
    if(a[i]<0){
        dq.push_back(i);
    }
    //ans store karo is window ka bhi
    if(dq.size()>0){
    ans.push_back(a[dq.front()]);//vector me dalo q ke front me jo arr ka index hai yani first negative usko ans bana do
   }
   else{
    ans.push_back(0);
   }
   }
   return ans;
}

int main(){
   long long int arr[] = {-8,2,3,-6,18};
    long long int n = 5;
    long long int k =2;
    vector<long long int> ans = printfirstnegativeinteger(arr,n,k);
    for(int i= 0 ;i<ans.size();i++){
        cout <<ans[i]<<" ";
    }
//cout<< ans;
return 0;

}