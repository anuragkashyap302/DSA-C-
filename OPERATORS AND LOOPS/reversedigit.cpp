#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sumdigit ;
    int productdigit = 1;
    while(n>0){
        sumdigit =  n%10;
        cout<<sumdigit;
       n = n/10;

    }
    
}

/*2nd method*
ans = 0;
digit = n%10;
ans = (ans*10)+digit;
n = n/10;



*/