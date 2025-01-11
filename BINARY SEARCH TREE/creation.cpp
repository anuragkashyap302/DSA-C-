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

 Node* deletefromBST(Node*root ,int target){
    // base case
    if(root == NULL){
        return NULL;

    }
    if(root->data == target){
        // target milne usco follwing case ho sak ta hai
        // 0 child
        if(root->left == NULL && root->right == NULL){
           delete root;
           return NULL;
        }
        // 1 child
        if(root->left != NULL && root->right == NULL){
            Node*temp = root->left;
           delete root;
           return temp;
        }
      if(root->left == NULL && root->right != NULL){
          Node*temp = root->right;
           delete root;
           return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
          int mini = minval(root->right)->data;//right wale part se mim val laye
          root->data = mini;// root ke sath replace karaye
           root->right = deletefromBST(root->right ,mini);
           // aage ke recsion call kar dite ho sakta aage bhi node ho jiska do child hai
           // recersion apne zero child ke case tak pahuch jaega call karyte karte
           // isko first case me taptedel kar dega
           return root;
        }

    }
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