#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;
class node{
    public:
    int data;
    node*leftchild;
    node*rightchild;
    // constructer
    public:
    node(int data){
        this->data == data;
        this->leftchild == NULL;
        this->rightchild == NULL;


    }
};

node*buildtree(node*root){
   cout<<"enter the data for the root"<< endl;
   int data;
   cin>> data;
   root = new node(data);
   if(data== -1){
    return NULL;

   }
   cout << "enter data for inserting in left of " << data << endl;
 root->leftchild = buildtree(root->leftchild);

    cout << "enter data for inserting in right of " << data << endl;
      root->rightchild = buildtree(root->rightchild);

      return root;

}

node*createparentmapping(node*root,int target,map< node* ,node*> &nodetoparent){
    node*res = NULL;
     queue<node*> q;
    q.push(root);
    //root ka parent to null hai na
    nodetoparent[root] = NULL;
    while(!q.empty()){
       node*front = q.front();
       q.pop();
       if(front->data == target){
        res = front;
       }
       if(front->leftchild){
        // front ke leftchild ko bata diye thumara baap front hai
        nodetoparent[front->leftchild] = front;
        q.push(front->leftchild);
       }
       if(front->rightchild){
        // front ke rightchild ko bata diye thumara baap front hai
        nodetoparent[front->rightchild] = front;
        q.push(front->rightchild);
       }
    }
    return res;
}
int burntree(node*target ,map< node* ,node*> &nodetoparent){
    map<node* ,bool> visited;
    // ek map baneye jo node visit kar gayr hai uska hisab
    // rakehaga
    queue<node*> q;
    q.push(target);
    visited[target] = true;
   int ans = 0;
    while(!q.empty()){
        bool flag = 0;
  int size  = q.size();

  for(int i = 0 ; i <size;i++){
    //process nebhirong node
    node*front = q.front();
    q.pop();
    if(front->leftchild && !visited[front->leftchild]){
        flag = 1;
    q.push(front->leftchild);
    visited[front->leftchild] = 1;
}
if(front->rightchild && !visited[front->rightchild]){
    flag =1;
    q.push(front->rightchild);
    visited[front->rightchild] = 1;
}
if(nodetoparent[front]&&!visited[nodetoparent[front]]){
     flag = 1;
    q.push(nodetoparent[front]);
    visited[nodetoparent[front]] = 1;
}
  }
  if(flag ==1){
     ans ++;
  }


    }
    return ans;

}

int mintimetoburn(node*root,int target){
// hume parnt se node ka mapping chiye brun karne ke liye
//aur taget jaha se shuru karna hai wo level order se nikl lo




   
    map< node* ,node*> nodetoparent;
    node*targetnode = createparentmapping(root,target,nodetoparent);
    int ans = burntree( targetnode ,nodetoparent );

}