#include<iostream>
using namespace std;
void rowwisesum(int arr[][3], int row ,int col){
    for(int i =0; i<row;i++){
        int sum = 0;
        for(int j = 0; j<col;j++){
           sum+= arr[i][j];
           }
           cout<<" sum ids " << sum << endl;
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
    rowwisesum(arr,3,3);
    
}  
