#include<iostream>
#include<string>
using namespace std;
string removeall(string s ,string part){
    while(s.length() !=0 && s.find(part)<s.length()){
      //  s.erase(s.find(part), part.length);


    }  
    return s;
}
int main(){
  string s ,part; 
  cout<<" enter the string "<< endl;
      getline(cin, s);
      cout<<" enter the yiu want remove "<< endl;
      getline(cin , part);
      string re = removeall(s,part);
      cout <<" your string " << re << endl;
    
    
}
