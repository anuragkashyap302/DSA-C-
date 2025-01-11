#include<iostream>
using namespace std;
int getmax(int arr[],int size){
    int maxi = INT8_MIN;
    for(int i=0;i<size;i++){
     //   if(arr[i]>max){
     //       max = arr[i];

     //   }
     maxi = max(maxi,arr[i]);//inbuilt functin hai if wala nahi likhna padega

    }
    return maxi;
    

}
int getmin(int arr[],int size){
    int mini = INT8_MAX;
    for(int i=0;i<size;i++){
    //    if(arr[i]<min){
    //        min = arr[i];
            
    //    }
    mini = min(mini,arr[i]);//maza aaya

    }
   return mini; 

}
int main(){
    
    int size;
    cin>>size;
    int arr[100];
    for(int i =0;i<size;i++){
        cin>>arr[i];

    }
    cout<<"max value"<<getmax(arr,size)<<endl;
    cout<<"min value"<<getmin(arr,size);

    
}