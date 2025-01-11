#include<iostream>
using namespace std;
 string replace(string s ,int ans){
  string temp ;
  for(int i = 0; i<ans ; i++){
    if(s[i] == ' ' ){
     temp.push_back('@');
      temp.push_back('4');
      temp.push_back('0');


    }
    else {
      temp.push_back(s[i]);
    }
  }
  return temp;

}
int main(){
  string s;
    getline(cin, s);
    int ans = s.length();
    cout<< " length is " << ans << endl;
     string re = replace(s,ans);
     cout<< " io bahi ans " << endl << re ;
    
}
