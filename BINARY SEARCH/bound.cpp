#include<iostream>
using namespace std;
int firstocc(int arr[],int size,int key){
    int s = 0;
    int e = size -1;
    int mid = s+(e-s)/2;
    int ans =-1;
    while(s<=e){
        if(arr[mid]==key){
             ans = mid;
            e = mid -1;//agar element mid me hi mil gya to aur phle se bhi to start ho skta hai na isiliyse left chale gya
            //right nahi gye kyuki first occ lena hai aur agar nahi mila hai uske liye niche case hai na..
        }
        else if(key>arr[mid]){//right me jao
            s = mid + 1;// end same rahega start update ho jayeaga

        }
        else if(key<arr[mid]){
            e = mid -1;


        }
        mid = s + (e-s)/2;//update bhi to karna hai
    }
    return ans;
}
// last occurence ke liye function // 
int lastocc(int arr[],int size,int key){
    int s = 0;
    int e = size -1;
    int mid = s+ (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(arr[mid]==key){
             ans = mid;
            s = mid +1;//agar element mid me  mil gya aur last kha tak hai wo dekhene ke liye right me chle end same rahega s update hoga
            //left nahi gye kyuki last occ lena hai aur array sorted hai to wo last me hi miliga
        }
        else if(key > arr[mid]){//right me jao
            s = mid + 1;// end same rahega start update ho jayeaga

        }
        else if(key < arr[mid]){//left me jao
            e = mid - 1;


        }
        mid = s+(e-s)/2;//update bhi to karna hai
    }
    return ans;
}

int main(){
    int arr[10]={1,2,3,3,3,3,3,3,3,4};
    cout<< " first occurence of 3 is at index " <<firstocc(arr,10,3) << endl;
     cout<< " last occurence of 3 is at index " <<lastocc(arr,10,3);

}
