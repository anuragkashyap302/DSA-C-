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

    void solve(node*root,vector<int> &ans,int k,int &count){
      if(root == NULL){
        return;
      }
      ans.push_back(root->data);
      //left
      solve(root->leftchild,ans,k,count);
      solve(root->rightchild,ans,k,count);
      //chek for k sum

      int size = ans.size();
      int sum = 0;
      for(int i= size-1;i>=0;i--){
        //ans wale vector ko peche sae check karna chlu kiye
        //sabse last elemnt last me add hua hoga
        //usme aage wala jodte jayge k ke eual hoga last wala
        //ko pop kar denge rest elemnt prev call ke liye chala jayega
        sum = sum + ans[i];
        if(sum == k){
          count++;

        }

      }
      //copy me example hai
      ans.pop_back();


      
    }

    int ksum(node*root,int k){
      vector<int> ans;
      int count = 0;

        solve(root,ans,k,count);
        return count;
    }

    int main() {

    node* root = NULL;
    root = buildtree(root);
    

}

    