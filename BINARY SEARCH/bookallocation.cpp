#include<iostream>
using namespace std;
bool ispossible(int arr[],int n,int m,int mid){
    int studentcount = 1;
    int pagesum  = 0;//phle stu.ko abhi tak koi pages nhi diye hai
    for(int i = 0; i<n; i++){
        if(pagesum + arr[i] <=mid){ //agar page ka sum mid se kam hai to 1st. stu. ko dete jayiye
            pagesum += arr[i];
        }
        else{
            studentcount++;
            if(studentcount > m || arr[i]>mid){
                return false;

            }
             pagesum  =0;//phir se dusre stu.ke liye counting start
             pagesum = arr[i];//jaha 1st stu. ka counting khatam wahi se dusre ks chalu
        }

    }
    return true;
}
   int bookallocate(int arr[],int n ,int m){
     int sum = 0;
      int s = 0;
    for(int i = 0; i<n;i++){
        sum = sum + arr[i];    }
   
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e){
        
     if(ispossible(arr,n,m,mid)){
        ans = mid;
        e = mid-1;
     }
     else{
        s = mid +1;
     }

mid = s + (e-s)/2;

    }
    return ans;

   }
int main(){
    int arr[4]={10,20,30,40};
  
   int ans = bookallocate(arr,4,2);
   cout<< ans ;


    return 0;
}