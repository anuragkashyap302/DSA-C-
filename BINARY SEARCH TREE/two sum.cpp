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


 bool twosuminBST(Node*root,int target){
    vector<int> ans;
    INORDER(root,ans);
    int i = 0; 
    int j = ans.size()-1;
    while(i<j){
        int sum = ans[i] + ans[j];
        if(sum == target){
            return true;
        }
       else if(sum> target){
            j--;
        }
        else{
            i++;
        }

    }
    return false;

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