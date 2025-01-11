#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Node{
   public: 
   int data;
   Node*left;
   Node*right;
   //constructor
   Node(int data){
    this->data = data;
    this-> left== NULL;
    this->right == NULL;


   }
};
  void INORDER(Node*root,vector<Node*> &in){
    if(root == NULL){
        return ;
    }
    INORDER(root->left,in);
   in.push_back(root);
    INORDER(root->right,in);
  }
 Node* INSERTTOBST(Node*root,int d){
     // base case

     if(root == NULL){
        root = new Node(d);
        return root;
     }
     // left right ke liye call mar do conditon laga ke
     if(d > root->data){
        root->right =  INSERTTOBST(root->right,d);
     }
     else{
        root->left =  INSERTTOBST(root->left ,d);
     }
     return root;

 }


 Node*flatten(Node*root){
    vector<Node*> ans;
    INORDER(root,ans);
    int n = ans.size();
    Node*curr = root;
    for(int i = 1 ; i<n ; i++){
        Node*temp = ans[i];
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    // last nod ebach gaya
    curr->left = NULL;
    curr->right = NULL;
    return root;
 }
 



void takeinput(Node*&root){
    
    int data;
    cin >> data;
    while(data != -1){
      root =   INSERTTOBST(root,data);
      cin >> data;
    }
}
int main(){
    Node*root = NULL;
    cout <<" enter the data for BST"<< endl;
    takeinput(root);
    cout <<"Printing BST"<< endl;
  
}