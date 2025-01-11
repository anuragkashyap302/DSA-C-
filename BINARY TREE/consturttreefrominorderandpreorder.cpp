#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
    public:
  int data;
  node *leftchild;
  node*rightchild;
  // consutrectur
  public:
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
int findposition(int in[],int element,int n){
   for(int i = 0;i<n;i++){
    if(in[i]==element){
        return i;
    }
   }
   return -1;
}

node*solve(int in[],int pre[],int prestartidx,int inorderstart,int inorderend,int n){
    // baase case
   if ( prestartidx>=n || inorderstart>inorderend){
   return NULL;

    }
    //root ka data preorder ke first element se le liye aur aage bada diye

    int element = pre[prestartidx++];
    node*root = new node(element);
    //inoreder se root ka position nikal lo
    //wahi se left right decide hoga na
    int position = findposition(in,element,n);
//recursive call mar do left right ke liye
// left part inorder me jo root mila uske tak hi hoga
root->leftchild = solve(in,pre,prestartidx,inorderstart,position-1,n);
// right part root ke baadd bala element hoga yani pos+1 se end tak
root->rightchild = solve(in,pre,prestartidx,position+1,inorderend,n);

return root;
}

node*constructfromPreandIn(int pre[],int in[],int n){
    int prestartidx = 0;
    int inorderend = n-1;
    int inorderstart = 0;
   node*ans = solve(in,pre,prestartidx,inorderstart,inorderend,n);
   return ans;
}

int main(){
    node*root = NULL;
    root = buildtree(root);

}

