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

bool isidentical(node*r1 ,node*r2){
    //base case
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }

    // agar null nahi hai to left right compare karne jao
    bool left = isidentical(r1->leftchild,r2->leftchild);
    // dono trree ka left ek sath travel kiye
    bool right = isidentical(r1->rightchild,r2->rightchild);
    //dono ka right ek sath
    //call ke spectic node par value chek kar liye dono tree ka
    bool value = r1->data == r2->data;
    if(left && right && value){
        return true;
    }
    else{
        return false;

    }
}

int main() {
    node* root1 = NULL;
    node*root2 = NULL;
    //creating a tree
  //first tree
    root1 = buildtree(root1);
    // second tree
    root2 = buildtree(root2);

}