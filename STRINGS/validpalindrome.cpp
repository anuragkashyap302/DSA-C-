#include<iostream>
using namespace std;
bool valid(char ch){
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
        return 1;
    }
    return 0;
}
char uppertolower( char ch){
  if(( ch>='a'&& ch<='z')||(ch >= '0' && ch<='9')){
    return ch;

  }
  else{
    char temp = ch -'A' + 'a' ;
    return temp;
     }
}
bool palindrome(string a){
    int s = 0;
    int e = a.length() -1;
    while(s<=e){
        if(( a[s] ) != ( a[e]) ){
            return 0;
        }
        else {
            s++; e--;
        }
    }
    return 1;
}
bool newvalid(string s){
    //faltu charter hatado
    string temp ;
    for(int i = 0;i<s.length();i++){
        if(valid(s[i])){
            temp.push_back(s[i]);//agar char vaild hai to temp string me dall do
        }


    }
    //lowercase me convert kardo temp string ko
    for(int i =0;i<temp.length();i++){
        temp[i]= uppertolower(temp[i]);
    }
    return palindrome(temp);
}

int main(){
 string s = "Anurag" ;

  cout<<  newvalid(s);
  
  
}