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

node*solve(int in[],int post[],int postlastidx,int inorderstart,int inorderend,int n){
    // baase case
   if ( postlastidx<=0 || inorderstart>inorderend){
   return NULL;

    }
    //root ka data postorder ke last element se le liye aur aage bada diye

    int element = post[postlastidx--];
    node*root = new node(element);
    //inoreder se root ka position nikal lo
    //wahi se left right decide hoga na
    int position = findposition(in,element,n);
//recursive call mar do left right ke liye
//phele right solve hoga post ke case me copy dekh lo
root->rightchild = solve(in,post,postlastidx,position+1,inorderend,n);
// left part inorder me jo root mila uske tak hi hoga
root->leftchild = solve(in,post,postlastidx,inorderstart,position-1,n);
//post me right se left scan karte hue ch;te hai

return root;
}

node*constructfromPreandIn(int post[],int in[],int n){
    int postlastidx = n-1;
    int inorderend = n-1;
    int inorderstart = 0;
   node*ans = solve(in,post,postlastidx,inorderstart,inorderend,n);
   return ans;
}

int main(){
    node*root = NULL;
    root = buildtree(root);

}

