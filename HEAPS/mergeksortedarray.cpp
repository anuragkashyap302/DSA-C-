#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class node{
    public:
    int data;
    int i ;
    int j;
    node(int data , int row ,int col ){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};
// apne hisab ka pririty que banye jarut ke hisb se

vector<int> mergeksortedarray(vector<vector<int>>&karrays,int k){
   priority_queue<node* ,vector<node*> ,compare> minheap; 
    //saare array k first element inserst 
    for (int i = 0; i < k; i++) {
        if (!karrays[i].empty()) {
            node* temp = new node(karrays[i][0], i, 0);
            minheap.push(temp);
        }
    }
     //sab array ka first element dal gya
    vector<int> ans;
    //ab compre karke ans me push karte jao
    while(minheap.size() > 0){
        node*temp = minheap.top();
        ans.push_back(temp->data);
        minheap.pop();
        int i = temp->i;
        int j = temp->j;
        // same i th arry ka agla data yani [i][j+1] chota to usko minheap me push
        // har baar cheak karte jao
        if(j+1 <karrays[i].size()){
            node*next = new node(karrays[i][j+1],i,j+1);
            minheap.push(next);
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> karrays = {
        {2, 6, 12},
        {1, 9},
        {23, 34, 90, 2000}
    };
    int k = karrays.size();

    vector<int> result = mergeksortedarray(karrays, k);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}