#include<iostream>
using namespace std;
void reverse(int arr[],int size){
    int start = 0;
    int end = size-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
    void printarray(int arr[],int size){
        for(int i=0;i<size;i++){
            cout << arr[i]<<" " ;

        }
    }


int main(){
    int size  =10;
    int arr[10]={5,7,-2,10,22,0,5,22,1,-2};
    printarray(arr,size);
cout<<endl;
    reverse(arr,size);
cout<<endl;
     printarray(arr,size);
    
    

}