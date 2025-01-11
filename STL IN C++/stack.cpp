#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<string> s;
    s.push("anurag");
    s.push("kashyap");
    s.push("raj");
    cout<<"top element"<<s.top()<<endl;
    s.pop();
     cout<<"top element"<<s.top()<<endl;

     cout<<"top element"<<s.size()<<endl;
     cout<<"empty or not"<<s.empty()<<endl;
    //jo sabse baad me jayega wo sabse phele baahr ayega 
// sadi me plate rakha jaana
//pop means top element ko remove karna top element alg alg bhi ho sakta hai na

}