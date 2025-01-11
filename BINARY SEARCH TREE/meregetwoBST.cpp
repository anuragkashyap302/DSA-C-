#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
   int data;
   Node*left;
   Node*right;
   //consucturter
   Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;

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
vector<int> mergetwovector(vector<int>&a,vector<int>&b){
    vector<int> ans(a.size()+b.size());
    int i = 0 , j = 0 ,k = 0;
    while(i<a.size() && j< b.size()){
        if(a[i]<b[i]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;

        }
    }
    while(i<a.size()){
        ans[k++] = a[i];
        i++;
    }
    while(j<b.size()){
        ans[k++] = b[j];
        j++;
    }
    return ans;
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
Node*mergetwoBST(Node*root1,Node*root2){
    // dono bst ka inorder nikal lo p[hele] and vector me store kar do
    vector<int> bst1;
    vector<int> bst2;
    INORDER(root1,bst1);
    INORDER(root2,bst2);
    //ab dono merrsge kardo be
    vector<int> mergedvector = mergetwovector(bst1,bst2);
    // sorted vector yani inordee se bst banana aata hai bana dlao 
     int s = 0 ; 
     int e = mergedvector.size() -1;
     // inorder to bst me s nd e ki jarruta hogi 
     return inordertoBST(s,e,mergedvector);
     


}
Node*INSERTTOBST(Node*&root,int d){
    //base case
    if(root== NULL){
        root = new Node(d);

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
void takeinput(Node*&root){
    int data;
    cin>> data;
    while(data!= -1){
        root = INSERTTOBST(root,data);
    }
}
int main(){
    Node*root = NULL;
    cout<<"enter data for BST"<< endl;
    takeinput(root);

}