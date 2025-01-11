#include<iostream>
using namespace std;
void saydigit(int n,string arr[]){
    // base case
    if(n == 0){
        return ;
    }
    // proccesing
    int digit = n%10;
    n = n/10;
    // cout<< arr[digit]; // isme ulta print hoga kyki rec abhi first call me hi yani abhi l;ast digit nilke hai phele usko pri nt kiye phir call
    //to ulta aa jayega
    // recusive caal
    saydigit(n,arr);//print isk baad karaye kyki solve karte katrte base case tak pauchega yani first digit hoga recusion
    //ke last call me phele wahi print karna hai kyki recuroson wahi se chali hoga remaininig line ke liye complete karke
    //phir priv call me jayega ek baar dry run kar ho jayega
    cout<< arr[digit] << " ";

}

int main(){
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin>> n;
    cout <<endl; 
    saydigit(n,arr);
}