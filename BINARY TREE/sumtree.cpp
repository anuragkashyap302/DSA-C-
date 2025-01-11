#include<iostream>
#include<queue>
using namespace std;

class node{
   public:
   int data;
   node*leftchild;
   node*rightchild;
   public:

   // constructer
    node(int data){
    this->data = data;
    this->leftchild = NULL;
    this->rightchild = NULL;


   }
};

node* buildtree(node *root){
    cout<<"enter the data: " << endl;
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

 pair<bool ,int> issumtreefast(node*root){
    //base case
    if(root == NULL ){
        pair<bool,int> p = make_pair(true,0);
    }// leaf node
    if(root->leftchild == NULL && root->rightchild == NULL){
        pair<bool,int> p = make_pair(true,root->data);
    }
    //pahele kiya hua hua left jo bhi ans aaya uso pair mr stroe karl iye

    pair<bool,int> leftans = issumtreefast(root->leftchild);
    pair<bool,int> rightans = issumtreefast(root->rightchild);
    bool left = leftans.first;// aagr sum tree hoga tojh true ya false aaya hoga jo lefftans ke first box me stroe hoga usko extract kar liye
    bool right = rightans.first;

    //sum tree ka condtn bhi extract kar lo new variable me root ka sum donp subtree ke equal hona chiye
    bool condn = root->data == leftans.second + rightans.second;
    pair <bool ,int > ans;

    if(left && right && condn){
        ans.first = true;
        ans.second = root->data + leftans.second + rightans.second;
        // ans pair me first boox me true agar ye sab cond shi h to and second box me value left right and root node ka
    }
    else{
    ans.first = false;
    

    }
    return ans;
}

int main() {
    node* root = NULL;
    root = buildtree(root);
    pair< bool,int> ans = issumtreefast(root);

}