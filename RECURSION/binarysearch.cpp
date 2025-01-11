#include<iostream>
using namespace std;
bool binarysearch(int arr[],int s ,int e,int n,int key){
    // base case
    int mid = s +(e-s)/2;
   if(s>e){
    return false;
   }
   if(arr[mid] == key){
    return true;
   }
   if(arr[mid] < key){
    // search in right 
    binarysearch(arr,mid+1 ,e ,n,key);
   }
   else{
    binarysearch(arr,s,mid-1,n, key);
   }
   

   
    
   
    
}
int main(){
    int n = 5;
    int arr[n] = {1,2,3,4,5};
    int key = 4;
    bool ans = binarysearch(arr,0,n-1,n,key);
    cout << ans <<endl;
}