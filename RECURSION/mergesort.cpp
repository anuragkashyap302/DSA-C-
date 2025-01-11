#include<iostream>
using namespace std;
void merge(int*arr,int s,int e){
    int mid =(s+e)/2;
// ye dhayan rahe hum array ka indexing change nahi kar rahe khai value nkal ke usko alag alag tod rahe hai single block me kar rahe hai
 // copy dek phele barr sorted hone ek ek length ka array ayga
//ek left se ek right se
    int len1 = mid - s +1; //left wale subpart ka lenght hai jo ki merge ke liye aaya hai starting me to single bolck hoga
    // dry run karke check kar lo
    int len2 = e - mid; //right wale sbpart ka legth end se lekar mid tak
   

   // naya array bna lo length ke value ka jo sorted hone aaaya hai
   int*first = new int[len1];
   int*second = new int[len2];

   // copy karo values naye array me
   // jtna size ka array sort hone aayega dono side se dymalicaly memoery allocte ho jayega har baar
   //phele baar ek ek length aayega phir wo dono sorted way merde hoke phir do do length ka aayega
   //copy dekh be


   int mainarrayindex = s;
   for(int i=0; i<len1; i++) { //left wala part first aary me copy kiye
        first[i] = arr[mainarrayindex++];
    }

    mainarrayindex = mid+1; //right wala subpart duse array me copy kiye
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainarrayindex++];
    }

    //merge 2 array in sorted ways
    int index1 = 0;
    int index2 = 0;
    mainarrayindex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainarrayindex++] = first[index1++];
        }
        else{
            arr[mainarrayindex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainarrayindex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainarrayindex++] = second[index2++];
    }

    delete []first;
    delete []second;


}
void mergesort(int *arr ,int s ,int e ){
//base case
if(s>=e){
    return;
}
int mid = s + (e-s)/2;
//left part ko sort karo matlab har baar mid nikal ke single block tak pahuco 
   mergesort(arr ,s,mid);
   //right part ko sort karo isko bhi sigle bolk tak torte jao mid nikal nikal ke
   mergesort(arr,mid+1 ,e );
   // dono part ko merge kar do sorted way me
//jis recsion call me merge function call hoga usi samy ka s, mid, end 
// jayega merge function me
//e.g torte torte last pacha single bolck ab merge function cal hoga
// to s = 0 and e = 0 hai kyki single  block hai and so on 


   merge(arr,s,e);

}
   
    
    
    

int main(){
    int n = 5;
    int arr[n] = {3,6,2,9,1};
    mergesort(arr, 0 , n-1 );
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
    
}