#include<iostream>
using namespace std;
int power(int n){
    // base case
    if(n== 0){
        return 1;

    }
    int smallarproblem = power(n-1);
    int biggerproblem = n*smallarproblem;
    return biggerproblem;
    // in one line
   //return 2*power(n-1)
    
}
int main(){
    int n ;
    cin >> n;

    int ans = power(n);
    cout << ans <<endl;
}