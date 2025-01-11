#include<iostream>
#include<stack>
using namespace std;
void solve(stack <int> &s , int x){
    //base case
    if(s.empty()){
        s.push(x);
        cout  <<  " jisko dalna hai " <<   x  << endl;
        return;

    }
    // top wale stroe karke rakhana bhi tih hai
    int num = s.top();
    cout << " top ko hatte gaye" << endl;
     cout << num << endl;
    s.pop();//usko hsta dis

    // recursive call
    solve(s,x);
    cout << " wapas aate wqat recusrion se" << endl;
    cout << num << endl;
    s.push(num);//number jo stroe kiye uso dete gsye


}
stack<int> pushatbottom(stack<int>&mystack,int x){
    solve(mystack,x);
    return mystack;
}



int main(){
     stack<int> s;

    s.push(7);
    s.push(1);
    s.push(4);
     s.push(5);

    cout<<" before "<< endl;
    
   stack<int> res =  pushatbottom(s,9);
   cout<<" after "<< endl;
while(!s.empty()){
    cout << s.top() << endl;
    s.pop();
}
    return 0;

}