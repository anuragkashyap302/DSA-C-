#include<iostream>
#include<stack>
using namespace std;

bool isvalidparan(string expresion){
    stack<char> s;
    for(int i= 0;i<expresion.length();i++){
        char ch = expresion[i];
        // agar opning braket mile to tush do
        //closing mile top stacktop chek and pop
if(ch == '('|| ch=='{'|| ch=='['){
    s.push(ch);

}
else{
    //for closing
    if(!s.empty()){
        // top wale char ko top me stroe kar ke current char ko match karo
        char top = s.top();
// baract match hona chaiye na pop hone ke liye

            if (ch== ')' && top =='(' || ch== '}' && top =='{' || ch== ']' && top =='['){
            s.pop();//pp kar do
        }


        else{
            return false;
        }
    }
    else{
        return false;// unbalaencd expresion agar matach nahi hua aur staaak bhi empaty nahi hai
    }
}


    }
    if(s.empty()){
        return true;//pura procaess karne baad stack aagar empty hua to true
    }
    else{
        return false;
    }
}

int main(){
    
    return 0;

}