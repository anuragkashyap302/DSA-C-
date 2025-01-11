#include<iostream>
using namespace std;
bool search(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}
int main(){
    int arr[10]={5,7,-2,10,22,0,5,22,1,-2};
    cout<<"enter the element to search for"<<endl;
    int n;
    cin>>n;
    bool found = search(arr,10,n);
    if(found){
        cout<<"key is preasnt"<<endl;
    }
    else cout<<"key is absent";
    

}