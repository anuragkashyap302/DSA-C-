#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int ,string> m;
     //sordet hota hai
     m[1] = "anurag";
     m[13] = "raj";
     m[2] = "kashyap";
     m.insert({5,"car"});
     cout<<"before erase"<<endl;
     for(auto i:m){
        cout<<i.first<<" "<<i.second<< endl;

     }
     cout<<"finding 13"<<m.count(13)<<endl;
     m.erase(2);
     cout<<"after erease"<<endl;
     for(auto i:m){
        cout<<i.first<<" "<<i.second<< endl;

     }
     auto it = m.find(5);
     for(auto i = it;i!=m.end();i++){
        cout<<(*i).first<<endl;

     }

}