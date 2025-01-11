#include<iostream>
#include<queue>
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
  void LEVELORDERTRAVERSAL(Node*root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp = q.front();
        
        q.pop();
        if(temp == NULL){
            //purana level complete traverse ho chuka hai
            cout <<endl;
             if(!q.empty()){
            //queue still has some child node
            q.push(NULL);
        }

        }
       else{
        cout << temp->data << " ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
       }
    }

  }
  void INORDER(Node*root){
    if(root == NULL){
        return ;
    }
    INORDER(root->left);
    cout << root->data <<" ";
    INORDER(root->right);
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
 Node*minval(Node*root){
    Node*temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;

 }
 Node*maxval(Node*root){
    Node*temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;

 }
 bool isBST(Node*root,int min, int max){
    if(root== NULL){
    return true;
  }  
    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left,min,root->data);
        bool right = isBST(root->right,root->data,max);
        return left && right ;
    }
    else{
        return false;
    }

 }
 bool vaildBST(Node*root){
  //sabse chota and bada value pass kae diye
  //ab root se compare agar left gaye to range intmin se root tak
  // right gaye to range root se int max tak
  // agar ye foolw hote gaya antim tak to bst hai

  
  bool ans = isBST(root,INT16_MIN ,INT16_MAX);
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
     LEVELORDERTRAVERSAL(root);
   INORDER(root);

}