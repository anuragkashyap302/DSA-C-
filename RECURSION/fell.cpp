#include<iostream>
using namespace std;
void reachhome(int src ,int dest){
    cout << " source "  << src << " destinstion " << dest << endl;
    // base case
    if(src== dest){
        cout<<" pachuch gaya " <<endl;
        return;
    }
    // processsing
    src++;
    //recurise call
    reachhome(src ,dest);
}
int main(){

    int dest = 10;
     int src = 1;
     cout<<endl;
     reachhome(src,dest);


}