#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node*leftchild;
    node*rightchild;
    // consuctructer
    public:
    node(int data){
     this->data = data;
     this->leftchild = NULL;
     this->rightchild = NULL;

    }

    
};

node* buildtree(node*root){
        cout<<"enter the data"<< endl;
        int data;
        cin >> data;
        root = new node(data);

        if(data == -1){
            return NULL;
        }
       cout << "enter data for inserting in left of " << data << endl;
       root->leftchild = buildtree(root->leftchild);

  cout << "enter data for inserting in right of " << data << endl;
      root->rightchild = buildtree(root->rightchild);

      return root;

    }


    void solve(node*root,int len,int& maxlen,int sum,int &maxsum){
   //base case
   if(root == NULL){
    //root null matalb ya to kuch nahi hai ya hum pura tarvel kar cheke hai
    if(len> maxlen){
        //agar tavel kiye to len amd sum to inc  hoga uso maxlen ans maxsum ne stroe kar die

        maxlen = len;
        maxsum = sum;
    }
    else if(len == maxlen){//agar do path equal hai phir bhi sum max wala chiye
    
        maxsum= max(sum ,maxsum);
    }
    //agar tavel nahi hua hai to simple return;
    return;
   }
   sum = sum + root->data;
   //har ek call len inc kar diye sum ka formula upr likh diye
   solve(root->leftchild,len+1,maxlen,sum,maxsum);
   solve(root->rightchild,len+1,maxlen,sum,maxsum);
   

    }

    int sumoflognestpath(node*root){
        int len  =0;
        int maxlen = 0;
        int sum = 0;
        int maxsum = INT16_MIN;

        solve(root,len,maxlen,sum,maxsum);
        return maxsum;

    }

    int main(){
        node*root = NULL;
        root = buildtree(root);
    }
