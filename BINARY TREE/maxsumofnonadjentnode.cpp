#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
  int data;
  node*leftchild;
  node*rightchild;
  //constructer
  public :
  node(int data){
    this->data = data;
    this->leftchild = NULL;
    this->rightchild = NULL;

  }
};

node*buildtree(node*root){
    cout <<"enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    cout <<"enter data for leftchild of" << data << endl;
    root->leftchild = buildtree(root->leftchild);

     cout << "enter data for inserting in right of " << data << endl;
      root->rightchild = buildtree(root->rightchild);

      return root;

}


int main(){
    //creating a tree
    node*root = NULL;
    root = buildtree(root);


}