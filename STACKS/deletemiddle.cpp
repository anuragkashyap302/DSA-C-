#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>&inputstack,int count,int size){
    //base case
    if(count == size/2){
        inputstack.pop();
        return;

    }
    int num = inputstack.top();
    inputstack.pop();
    //recursive call
    solve(inputstack,count+1,size);
    inputstack.push(num);


}
void deletemiddle(stack<int>&inputstack,int n){
    int count = 0;
    solve(inputstack,count,n);

}



int main(){
    stack <int> st;
    st.push(7);
    st.push(1);
    st.push(4);
     st.push(5);
     deletemiddle(st,4);



    return 0;

}