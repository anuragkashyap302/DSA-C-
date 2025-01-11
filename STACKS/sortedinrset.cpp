#include<iostream>
#include<stack>
using namespace std;

void sortedinsert(stack<int>&s,int num){
  //base case
    if(s.empty() || (!s.empty() && s.top() < num) ) {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    //recursive call
    sortedinsert(s,num);
    s.push(n);
   
   
}

void sortstack(stack<int>&s ){
    // base case
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();
    sortstack(s);
    sortedinsert(s,num);
    
}



int main(){
    //creation
    stack<int> s;
    //inserting
    s.push(3);
    s.push(-7);
    s.push(9);
    s.push(-2);
    s.push(5);
    sortstack(s);
    while(!s.empty()){
    cout << s.top() << endl;
    s.pop();
}

    
    


}