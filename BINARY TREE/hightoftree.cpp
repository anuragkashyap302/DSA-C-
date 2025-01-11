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




void inordertraversal(node*root){
    //base case
    if(root == NULL){
        return ;
    }
    inordertraversal(root->leftchild);
    cout<< root->data <<" ";
    inordertraversal(root->rightchild);
}

int hightoftree(node*root){
    //base case
    if(root == NULL){
        return 0;
    }

    int left = hightoftree(root->leftchild);
    int right = hightoftree(root->rightchild);
    int ans = max(left,right) + 1;
    return ans;
}

int main() {
    node* root = NULL;
    //creating a tree

    root = buildtree(root);

}