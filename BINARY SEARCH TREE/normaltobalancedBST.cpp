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
  void INORDER(Node*root,vector<int> &in){
    if(root == NULL){
        return ;
    }
    INORDER(root->left,in);
   in.push_back(root->data);
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
 Node*inordertoBST(int s ,int e, vector<int>&in){
  // base case 
  if(s>e){
    return NULL;
  }
  int mid = (s+e)/2;
  Node*root = new Node(in[mid]);
  root->left = inordertoBST(s,mid-1,in);
  root->right = inordertoBST(mid+1,e,in);
  return root;
 }

 Node*normaltobalanced(Node*root){
    vector<int> in;
    INORDER(root,in);
    int e = in.size() -1;
    return inordertoBST(0,e,in);
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