#include<iostream>
using namespace std ;
#include<stack>
#include<string.h>

int main(){
    stack <char> st;
    string str = "((a+b))";
    for(int i = 0; i<str.length();i++){
        char ch = str[i];
        if(ch == '('|| ch=='+'|| ch=='-'|| ch=='*'|| ch=='/'){
            st.push(ch);
            
        }
        else{
            bool isredunand = true;
            if(ch == ')'){
                
                while(st.top()!='('){
                    char top = st.top();
                    if(top=='+'|| top=='-'|| top=='*'|| top=='/'){
                        isredunand = false;

                    }
                    st.pop();
                }
            }

        }

    }
}