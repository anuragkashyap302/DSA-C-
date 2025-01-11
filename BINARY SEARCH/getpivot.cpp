#include<iostream>
using namespace std;
int getpivot(int arr[],int size){
    int start= 0;
    int end = size-1;
    int mid = (start + end)/2;
    while(start<end){
        
        if(arr[mid]>= arr[0]){
            start = mid+1;
        }
        
        else{
            end = mid;
        }
        mid = (start+end)/2;//phir se mid ko nikale naye start and end ke mutabik
    }
    return start;
}
int main(){
    
    int odd[5] ={8,10,17,1,3};
    int start = getpivot(odd,5);
    cout << " pivot is at index " << start << endl;

    return 0;
}