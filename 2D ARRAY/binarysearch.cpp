#include<iostream>
using namespace std;
int main(){
    int arr[3][3];
    cout<<"element of arr" << endl;
    for(int i =0; i<3;i++){
        for(int j = 0; j<3;j++){
            cin >> arr[i][j];
        }
    }
     
    cout<< " printing arrRT " <<endl;
    for(int i =0; i<3;i++){
        for(int j = 0; j<3;j++){
            cout <<" "<<  arr[i][j];//rowwise
        }
        cout << endl;
    }
    int rows = sizeof arr / sizeof arr[0];
 int cols = sizeof arr[0] / sizeof arr[0][0];
 cout<<" row " << rows;
cout <<" col " << cols;
    
}  
