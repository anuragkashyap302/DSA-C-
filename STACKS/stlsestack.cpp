#include<iostream>
#include<stack>
using namespace std;
int main(){
    //creation
    stack<int> s;
    //inserting
    s.push(2);
    s.push(3);
    s.pop();

    cout << " printing top element " << s.top() << endl;

    if(s.empty()){
        cout << "empty hai" << endl;

    }
    else{
        cout <<"empty nahi hai"<< endl;

    }

cout << " size of stack is " << s.size() << endl ;


}