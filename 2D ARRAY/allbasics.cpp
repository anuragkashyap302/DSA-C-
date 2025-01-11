#include<iostream>
using namespace std;
bool ispresent(int arr[][3],int target, int row ,int col){
    for(int i =0; i<row;i++){
        for(int j = 0; j<col;j++){
           if(target == arr[row][col]){
            return 1;
           }
        }
    }
    return 0;

}
int main(){
    int arr[3][3];
    int target;
    cout<<"element of arr" << endl;
    for(int i =0; i<3;i++){
        for(int j = 0; j<3;j++){
            cin >> arr[i][j];
        }
    }
     cout << " your target" << endl;
     cin >> target ;

    cout<< " printing arrRT " <<endl;
    for(int i =0; i<3;i++){
        for(int j = 0; j<3;j++){
            cout <<" "<<  arr[i][j];//rowwise
        }
        cout << endl;
    }
    cout << " your tafet is " << ispresent(arr,target,3,3);
}  
