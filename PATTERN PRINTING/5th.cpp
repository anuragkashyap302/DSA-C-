#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
  /*  for(int i=1;i<=n;i++){
        for(int j =i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
}*/
//we can done by while loop also
int i =1;
while(i<=n){
    int j = i;
    while(j>=1){
        cout<<j;
        j = j-1;
    }
    cout<<endl;
    i=i+1;
}
}/*  2nd method
for(int i=1;i<=n;i++){
        for(int j =1;j<=i;j++){
            cout<<i-j+1;
        }
        cout<<endl;
    }
}
*/

