#include<iostream>
#include<queue>
using namespace std;
int main(){
    // max heap
    priority_queue<int> maxi;

    //min heap
    priority_queue<int,vector<int>, greater<int> > mini;

    maxi.push(1);
     maxi.push(3);
      maxi.push(2);
       maxi.push(4);
        maxi.push(0);
    cout<<" size " << maxi.size() << endl;
    int n = maxi.size();
    for(int i=0;i<n;i++){
        cout<<maxi.top()<<" ";
        maxi.pop();//print karne ke badd mitte bhii gaye top element

    }
    cout<<endl;
     mini.push(1);
     mini.push(3);
      mini.push(2);
       mini.push(4);
        maxi.push(0);
    cout<<" size " << mini.size() << endl;
    int n = mini.size();
    for(int i=0;i<n;i++){
        cout<<mini.top()<<" ";
        mini.pop();//print karne ke badd mitte bhii gaye top element

    }


}