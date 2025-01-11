#include<iostream>
using namespace std;
void print(int n){
    // base case
    if(n== 0){
        return ;

    }
    cout<< n << endl;
    print(n-1); // tail recuriasion
    // ab ek baar 
    // print(n-1) phele call then print // head recursion
    //cout<< n<< endl;
    
}
int main(){
    int n ;
    cin >> n;

    cout << n <<endl;
    print(n);
}