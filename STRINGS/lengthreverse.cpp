#include<iostream>
using namespace std;
char uppertolower( char ch){
  if( ch>='a'&& ch<='z'){
    return ch;

  }
  else{
    char temp = ch -'A' + 'a' ;
    return temp;
     }
}
bool palindrome(char a[] , int ans){
    int s = 0;
    int e = ans -1;
    while(s<=e){
        if(uppertolower( a[s] ) != uppertolower( a[e]) ){
            return 0;
        }
        else {
            s++; e--;
        }
    }
    return 1;
}
void reverse(char name[],int ans){
    int s = 0;
    int e = ans -1;
    while(s<e){
        swap(name[s++],name[e--]);
    }


}
int length(char name[]){
    int count = 0;
    for(int i = 0; name[i]!=0;i++){
        count++;
    }
   return count;
}
int main(){
    char name[20];
    cout<< " enter the name " << endl;
    cin>> name;
    cout<< " your name is " << name << endl;
     int ans = length(name);
     cout << " the length is " << ans << endl;
     reverse(name,ans);
     cout<< " your name is " << name << endl;
     cout<<" charecter is" << uppertolower('b') << endl;
     cout<<" CHARTER IS "<< uppertolower ('B') << endl;
     cout << " string is palindrome or not " <<  palindrome(name,ans) << endl ;


}