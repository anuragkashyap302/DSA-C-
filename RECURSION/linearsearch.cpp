#include<iostream>
using namespace std;
bool linearsearch(int arr[],int n,int key){
    // base case
   if(n== 0){
    return false;
   }
   if(arr[0] == key){
    return true;
   }
   else{
    bool remainingpart = linearsearch(arr+1,n-1,key);
      return remainingpart;
   }

   
    
    
    
}
int main(){
    int n = 5;
    int arr[n] = {1,2,3,4,5};
    int key = 4;
    bool ans = linearsearch(arr,n,key);
    cout << ans <<endl;
}