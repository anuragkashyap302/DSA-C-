#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
  /*  int count = 1;
    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cout<<count<<" ";
            count = count +1;
            
        }
        cout<<endl;
    }
}*/
//we can done by while loop also
int i =1;
int count  =1;
while(i<=n){
    int j = 1;
    while(j<=n){
        cout<<count;
        j = j+1;
        count = count +1;
    }
    cout<<endl;
    i=i+1;
}
}