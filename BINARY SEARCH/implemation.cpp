#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key){
    int start= 0;
    int end = size-1;
    while(start<=end){//jab tak startig chota hai tabhi tak na search karoge
        int mid = (start + end)/2;
        if(arr[mid]==key){
            return mid;
        }//right side jaana hai na 
        if(key>arr[mid]){
            start = mid +1; //yaha end same hi rahega na privious case jaisa

        }
        else{//left side jaane ke liye yaha starting to same rahega privious case jaisa
            end = mid-1;
        }
        mid = (start+end)/2;//phir se mid ko nikale naye start and end ke mutabik
    }
    return -1;
}
int main(){
    int even[6]={2,4,6,8,12,18};
    int odd[5] ={3,8,11,14,16};
    int index = binarysearch(even,6,12);
    cout << " index of 12 is " << index << endl;

    return 0;
}