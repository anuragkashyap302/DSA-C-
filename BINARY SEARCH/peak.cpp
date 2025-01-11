#include<iostream>
using namespace std;
int peakindex(int arr[],int size){
    int start= 0;
    int end = size-1;
    while(start<end){
        int mid = (start + end)/2;
        if(arr[mid]<arr[mid+1]){
            start = mid +1;
        }
        
        else{
               end = mid;
        }
        mid = (start+end)/2;
  
    
    //awlay peak start pe hi aayega ya to start or end same honge
}
return start;

}
int main(){
    int arr[4]={3,4,5,1};
    
   cout<<" peak indx " << peakindex(arr,4);
   

    return 0;
}