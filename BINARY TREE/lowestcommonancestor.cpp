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

    node* LCA(node*root,int n1 ,int n2){
      //base case
      if(root== NULL){
        return NULL;

      }
      if(root->data == n1 || root->data == n2){
        return root;
      }
      node*leftans = LCA(root->leftchild ,n1,n2);
      node*rightans = LCA(root->rightchild ,n1,n2);

      // dono side ka ans non null tabhi return root kar do
      // matlab wahi ans hai
      if(leftans!= NULL && rightans != NULL){
           return root;

      }
      // koi ek non null matalab  n1 and n2 me koi mil gaya hai usko return kar duye
      else if(leftans!=NULL && rightans == NULL){
        return leftans;
      }
      else if(leftans==NULL && rightans != NULL){
        return rightans;
      }
      else{
        return NULL;

      }
      

    }