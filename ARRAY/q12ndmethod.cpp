#include<iostream>
using namespace std;
void reverse(int arr[],int size){
    for(int i =0;i<size;i+=2){
        if(i+1<size){
            swap(arr[i],arr[i+1]);

        }
        
        
    }
}
    void printarray(int arr[],int size){
        for(int i=0;i<size;i++){
            cout << arr[i]<<" " ;

        }
    }


int main(){
    int size  =6;
    int arr[6]={1,2,7,8,5,6};//even case
    int brr[5]={11,3,9,76,43};//odd case
    printarray(arr,size);
cout<<endl;
    reverse(arr,size);
cout<<endl;
     printarray(arr,size);
cout<<endl;
         printarray(brr,5);
cout<<endl;
    reverse(brr,5);
cout<<endl;
     printarray(brr,5);
    
    

}