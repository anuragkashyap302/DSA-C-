#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

string firstnonrepeating(string a){
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";
    
    for(int i = 0; i < a.length(); i++){
        char ch = a[i];
        // Increment count
        count[ch]++;
        // Push into the queue
        q.push(ch);
        while (!q.empty()){
            if(count[q.front()] > 1){
                // Repeating character
                q.pop();
            }
            else{
                // Non-repeating character
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    string a = "aabc";
    string ans = firstnonrepeating(a);
    cout << ans;

    return 0;
}
