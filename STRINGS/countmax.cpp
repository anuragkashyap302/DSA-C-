#include<iostream>
using namespace std;
 char getmaxi(string s){
    int arr[26] = {0};
    for(int i =0;i<s.length(); i++){
        char ch = s[i];
        //lowercase
        int number = 0;//arr ke sabhi element zero kar diye
        if(ch>='a'&& ch<='z'){
            number = ch - 'a';//lowercase
        }
        else{
            number = ch - 'A';//uppercase
        }
        arr[number]++;//char ke hisab se arr ke idx me count + karte gye
    }
    //find max occ charceter now
    int maxi = -1;int ans =0;//wahi purna method max nikaj]lne kq
    for(int i =0;i<26;i++){
        if(maxi<arr[i]){
            ans = i;//wo idx jimse max number hai wo stroe
            maxi = arr[i];
        }
    }
    char finalans = 'a' + ans; //number ko char me chage kar diye
      return finalans;
    }
int main(){
    string s;
    cin>> s;
    cout<< getmaxi(s);
}