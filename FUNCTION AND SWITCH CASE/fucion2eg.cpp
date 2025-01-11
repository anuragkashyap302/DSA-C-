#include<iostream>
using namespace std;
int fact(int n){
    int fact = 1;
    for(int i =1;i<=n;i++){
        fact = fact*i;
        
    }
    return fact;
}
int ncr(int n, int r){
    int nem = fact(n);
    int dem = fact(r)*fact(n-r);
    int ans = nem/dem;
    return ans;
}
int main(){
    int n,r;
    cin>>n>>r;
    int ans = ncr(n,r);
    cout << ans;

}