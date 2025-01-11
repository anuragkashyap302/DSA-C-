#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> v;
    cout<<"capicity"<<v.capacity();

    v.push_back(1);
    cout<<"capicitty"<<v.capacity();

     v.push_back(2);
    cout<<"capicitty"<<v.capacity();

     v.push_back(3);
    cout<<"capicitty"<<v.capacity();

    cout<<"size"<<v.size();
    cout<<"element at second index"<<v.at(2);

    cout<<"fornt"<<v.front();
    cout<<"back"<<v.back();
    cout<<"print v";
    
    v.pop_back();
    v.clear();





}