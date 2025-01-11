#include<iostream>
using namespace std;
void reverse(int arr[],int size){
    int i = 0;
    int j = i+1;
    while(i<size){
        swap(arr[i],arr[j]);
       i = i+2;
       j= j+2;
    }
}
    void printarray(int arr[],int size){
        for(int i=0;i<size;i++){
            cout << arr[i]<<" " ;

        }
    }


int main(){
    int size  =6;
    int arr[6]={1,2,7,8,5,6};
    printarray(arr,size);
cout<<endl;
    reverse(arr,size);
cout<<endl;
     printarray(arr,size);
    
    

}