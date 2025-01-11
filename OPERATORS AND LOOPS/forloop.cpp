#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    //for(int i=0;i<=n;i++) ka alternative
    //jari nahi hai for loop me sab kuch hi likha jai
    int i = 1;
    for(; ;){
        if(i<=n){
            cout<<i<< endl;
        }
        else{
            break;
        }
        i++;
    }
}