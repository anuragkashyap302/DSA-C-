#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sumdigit = 0;
    int productdigit = 1;
    while(n>0){
        sumdigit = sumdigit + n%10;
        productdigit = productdigit*(n%10);
        n = n/10;


    }
    cout<< sumdigit <<endl;
    cout<< productdigit;
}