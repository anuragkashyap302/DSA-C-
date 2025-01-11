#include<iostream>
using namespace std;
int binarysearch(int num){
    int start= 0;
    int end = num;
    int ans  = -1;
     int mid =  start +(end - start)/2;
    while(start<=end){//jab tak startig chota hai tabhi tak na search karoge
       
        int square = mid*mid;
        if(square == num){
            return mid;
        }//right side jaana hai na 
        if(square < num){
            ans = mid;//mid ans bhi to ho skta hai kyki mid ka squre num se kam hai
            start = mid +1; //yaha end same hi rahega na privious case jaisa

        }
        else{//left side jaane ke liye yaha starting to same rahega privious case jaisa
            end = mid-1;//yaha ans store nahi hoga kyki squre abhi number bada hai na
        }
         mid =  start +(end - start)/2;//phir se mid ko nikale naye start and end ke mutabik
    }
    return ans;
}
int main(){
   int n;
   cin>>n;
int ans = binarysearch(n);
cout<<" ans is " << ans << endl;
    return 0;
}