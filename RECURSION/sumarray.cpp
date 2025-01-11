#include<iostream>
using namespace std;
int sumarray(int arr[],int n){
    // base case
   
   
    if(n== 0){
        return 0;

    }
    if(n== 1){
        return arr[0];
    }
    int remaningpart = sumarray(arr+1,n-1);
    int sum = arr[0] + remaningpart;
    return sum;
    
    
    
}
int main(){
    int n = 5;
    int arr[n] = {1,2,3,4,5};
    int ans = sumarray(arr,n);
    cout << ans <<endl;
}