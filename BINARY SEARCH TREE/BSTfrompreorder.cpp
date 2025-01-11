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
  void INORDER(Node*root){
    if(root == NULL){
        return ;
    }
    INORDER(root->left);
   cout<< root->data;
    INORDER(root->right);
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
 
Node*solve(int mini ,int maxi ,vector<int>&pre,int i){
    //base case
    if(i>= pre.size()){
        return NULL;
    }
    // hae ek call me mimi and maxi value phir se genrate ho rha hai
    // recsion ki property
    // isiliye ye base case hai ye mat smjhna mini hardam
    // INT_MIN ke hi baraber rahega wo har ek call me
    // badlega & then compare with curr value
    // phir recusion ke call ke anusar wapis
    if(pre[i]<mini || pre[i]>maxi){
        return NULL;
    }
    // same as jaise isbst chek karte the usi se bst bana diye
    Node*root =new Node(pre[i++]);// har ek idx ke lie new node
    root->left = solve(mini,root->data,pre,i);
    root->right = solve(root->data,maxi,pre,i);

 }
 Node*BSTfrompreorder(Node*root,vector<int> pre){
    int mini = INT16_MIN;
    int maxi = INT16_MAX;
    int i = 0;
    return solve(mini,maxi,pre,i);
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