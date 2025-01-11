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

Node*LCAinBST(Node*root,Node*p ,Node*q){
   //base case
   if(root == NULL){
    return NULL;
   }
   if(root->data < p->data && root->data < q->data){
    // p and q right me hai to ancestor bhi right me hi hoga
    return LCAinBST(root->right,p,q);
   }
   if(root->data > p->data && root->data > q->data){
    // p and q left me me hai to ancestor bhi left me hi hoga
    return LCAinBST(root->left,p,q);
   }
   if(root->data > p->data && root->data < q->data || root->data < p->data && root->data > q->data ){
    // p and q root ke left right me hai root hi uska coomaon ancestor hai

    return root;
   }

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