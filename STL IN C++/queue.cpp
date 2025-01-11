#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string> q;
    q.push("anurag");
    q.push("kashyap");
    q.push("raj");
    cout<<"top element"<<q.front()<<endl;
    q.pop();
     cout<<"top element"<<q.front()<<endl;

     cout<<"size"<<q.size()<<endl;
     cout<<"empty or not"<<q.empty()<<endl;
   //jo sabse phle aaya wahi sabse upar
   // sadi me line
   // isme top element alag hai satack se



}