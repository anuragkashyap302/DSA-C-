#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    //creation
    unordered_map<string,int> m;
    //insertion
    //1st ways
    pair<string , int> p = make_pair("babbar" , 3);
    m.insert(p);

    //2nd ways
    pair<string ,int> q("love" , 2);
    m.insert(q);
    //3rd ays
    m["mera"] = 1;
    // what will happen
    m["mera"]  = 2;
    //updateho jayaega mera ka value 2
    //first time kisi bhi key ka cration hota hai map ka
    // reptition me usi map me updation ho jata hai
    // unique or only one map for every key 

    //searcing
    cout<< m["mera"] << endl;
    cout<< m.at("babbar") <<endl;

    //not inserted key ko search karo
   // cout<< m.at["unknownkey"]<<endl;// ye line error dega kyki m me unkwon ke lyw kuch nahi hai

    cout<<m["unkwonkey"] << endl;//ye line chega kyki yaha automatic unkowm ke liye zero map ho jata hai
    cout<< m.at("unknownkey")<<endl; // ye line 0 output dega kyki uppar mapping ho chuka hai to m.at matlab
    // m par unkown ke liye kuch value hai yahi chhez line no 30 me missing tha

    cout << m.size() <<endl;
    cout<<m.count("love");//  inbulit fn hota hai
    m.erase("love");

    // traverse karna map ko to ek itrator bna ko itrate kargsa
    unordered_map<string ,int> :: iterator it = m.begin();
    while(it!= m.end()){
        cout << it->first <<" " << it->second << endl;
    }

}