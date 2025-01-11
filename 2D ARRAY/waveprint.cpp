#include<iostream>
using namespace std;
void waveprint( int arr[][3],int row,int col){
    for(int j = 0; j<col;j++){
        if(j&1){// odd index - bootom to top
            for(int i =row-1;i>=0;i--){
                cout<< arr[i][j] <<" ";
  // isme odd idx wala col print hoga i and j element ke idx hai
            }
        }
        else{ //even idx - top to bootom
            for(int i = 0;i<row;i++){
                cout << arr[i][j] <<" ";
            }
  // isme even idx wala  col print    hoga      
        }
    }
}
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
    waveprint(arr,3,3);
}  
