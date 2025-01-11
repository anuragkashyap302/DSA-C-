#include<iostream>
using namespace std;
int partition(int arr[], int s ,int e){
    int pivot = arr[s]; //harek caall me pivot element us partion array ka first element hi hoga
   //jitne element pivot se chote hai count kar lo uuse ek aage pivot ka sahi position hoga
  

   
    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

     //pivot ko right place pe place kar do
     int pivotindex = s + cnt;
    swap(arr[pivotindex], arr[s]);

  // ab pivot ke left me usse chota and right me uuse bada rakh do
  int i =s , j =e ;
  while(i<pivotindex && j> pivotindex){
     while(arr[i] <= pivot) //left me bada nil jaye pivot se to ruk jao
        {
            i++;
        }

        while(arr[j] > pivot) { //right me chota mil jaye pivot se to ruk jao
            j--;
        }
        //dona ko swap kar do 

        if(i < pivotindex && j > pivotindex) {
            swap(arr[i++], arr[j--]);
        }
  }
  return pivotindex;

}
void quicksort(int arr[],int s ,int e){
    // base case
    if(s>=e){
        return;
    }
    // partion karne ke liye ek element ko usko sahi jagah pe rakh do
    // uske left me usse chota and usse bada right me akh do

    // us element ka index khoj ke lao jaha pivot ko rkhoge
     
     int p = partition(arr,s,e);
     //left part sort karo
    quicksort(arr, s, p-1);

    //right wala part sort karo
    quicksort(arr, p+1, e);

    //recusinon se phle hi p variable bnaye hai to har caal me wo phir naya ek local variable banega
    // kyki har caal me pivoat elemrnt and uska postion alag alg hoga na
    //dry run karlo yaar 

}
int main(){
    int arr[10] = {2,4,1,6,9,9,9,9,9,9};
    int n = 10;

    quicksort(arr,0,n-1);
    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}