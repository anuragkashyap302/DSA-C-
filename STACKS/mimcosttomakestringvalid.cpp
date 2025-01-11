#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

 int minimumcost(string &str){
    // odd wala possible nahi ahi
    if(str.length() % 2 == 1){
        return -1;
    }

    stack <char> s;
    for(int i = 0;i<str.length();i++){
        char ch = str[i];
        if(ch == '{'){
            s.push(ch);
        } 

        // ch is a colsed brace
        else{
            if(!s.empty() && s.top()== '{'){
                s.pop();
            }
            //llop me har bar check hoga agar colsed ko open mil gaya to pop nhi to
            //agar top bala open brace nhi hai to thus do
             else
            {
                s.push(ch);
            }
        }
    }

    // ab hum valid exprassion ko pop kar chuke khali invlid bacha hai stack me
 // a ko closed and b ko open braces ke count ke liye rakh liey
    int a = 0, b = 0;
        while(!s.empty()) {
            if(s.top() == '{') {
                b++;
            }
            else
            {
                a++;
            }
            s.pop();
        }
        // valid banee me inta reversal hi chiye dry run me check kar lo
		int ans = (a+1)/2 + (b+1)/2;
        return ans;
    
 }
int main(){
    //creation
    stack<int> s;
    //inserting
    


}