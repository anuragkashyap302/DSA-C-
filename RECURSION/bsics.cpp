#include<iostream>
using namespace std;
int factorial(int n){
    // base case
    if(n== 0){
        return 1;
    }
    int chhoti = factorial(n-1);
    int badi = n*chhoti;
    return badi;
    // in one line
    // return n* factoiral(n-1);
    
}
int main(){
    int n ;
    cin >> n;

    int ans = factorial(n);
    cout << ans <<endl;
}