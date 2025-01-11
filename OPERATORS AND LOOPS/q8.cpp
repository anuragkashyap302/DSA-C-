#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a = 1;
    for(int i =0;i<=30;i++){
        int ans = pow(2,i);
        if(ans==n){
          a = 0; 
           cout<<"yes"; 
        break;
       
        }
        
     // apne se banaya hua fell proud  
        
        
    }
    if(a==1){
        cout<<"no";
    }
    
    
    
        }
    
