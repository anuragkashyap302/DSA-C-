#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int getkthlargest(vector<int>&arr ,int k){
    vector<int> sumstore;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        int sum = 0;// jitna bar loop me gusega naya sum
        //for every elenment
        for(int j = i ; j<n ;j++){
            sum = sum +arr[j];
            sumstore.push_back(sum);
            //dry run karo smajh aa jayega jaygda likho nay

        }
    }
    sort(sumstore.begin(),sumstore.end());
    return sumstore[sumstore.size() - k];
    // largest sum size-1 pe milaga 2nd largest size-2 pe
    // to kth larest size - k pe smjhhe

}
//using priorty q
int getkthlargest(vector<int>&arr ,int k){
priority_queue<int ,vector<int> ,greater<int>> mini;
int n = arr.size();
for(int i = 0; i<n; i++){
        int sum = 0;// jitna bar loop me gusega naya sum
        //for every elenment
        for(int j = i ; j<n ;j++){
            sum = sum +arr[j];
           if(mini.size()<k){
            mini.push(sum);
           }
     //agar 1st largst sum chiye to queqw  mwe ek hi element store hoga 
     //agar 2nd largest chiye to 2 elemnt store hoga 1st largest and 2nd largest 
     //but top pe 2nd largest rahega min heap hai na         
           else{
            if(sum>mini.top()){
                mini.pop();
                mini.push(sum);
            }
           }
            //dry run karo smajh aa jayega jaygda likho nay
/// bus ek barr dry run kar lo sb amjh aayega copy dekh lo
        }
    }

}
int main(){
    vector<int> arr ;
    arr.push_back(1);
    arr.push_back(2);
   arr.push_back(3);
   arr.push_back(4);
   arr.push_back(5);
   int ans = getkthlargest(arr ,1);
   cout << ans;

}