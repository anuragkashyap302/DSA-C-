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

int diameter(node*root){
    // base case
    if(root == NULL){
        return 0;
    }

    int op1 = diameter(root->leftchild);
    int op2 = diameter(root->rightchild);
    int op3 = hightoftree(root->leftchild) + hightoftree(root->rightchild) + 1;

    int ans = max(op1,max(op2,op3));
    return ans;
}



bool isblanced(node*root){
    // base case
    if(root == NULL){
        return true;
    }
     // agar left subtree balanced hoga to true degaa
     bool left = isblanced(root->leftchild);
     //agar right baleanced to true
     bool right = isblanced(root->rightchild);
     // tree ke balanced hone ka condition

     bool diff = abs (hightoftree(root->leftchild) - hightoftree(root->rightchild)) <= 1;

// order boht mateer karta hai recursion wo kaise kaam karta hai tumko pata hai dray run karo

     if (left && right && diff){
        return true;
     } 
     else{
        return false;
     }
}


// 2nd appproch

pair <bool,int> isfastblanced(node*root){
    // base case balned and hight ek sath
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
//yaha dono int phir bhi same kaam hi karega bool means 0 orb1
    pair< int ,int > left = isfastblanced(root->leftchild);
     pair< int ,int > right = isfastblanced(root->rightchild);

     bool leftans = left.first;//pair ke first me balaned hai ke nahi wo stroe hai uso excess kiye

     bool rightans = right.first;

     bool diff = abs(left.second - right.second)<=1;

  pair <bool ,int> ans;

     if (leftans && rightans && diff){
        ans.first = true;
     } 
     else{
         ans.first = false;
     }
    

}
pair<int ,int>diameterfast(node*root){
     // base case
    if(root == NULL){
       pair<int , int>p = make_pair(0 , 0);
       return p;
    }
     pair<int , int>ans;
     pair<int , int>left = diameterfast(root->leftchild);
      pair<int , int>right = diameterfast(root->rightchild);

      int op1 = left.first;
      int op2 = right.first;
      int op3 = left.second + right.second +1 ;
      ans.first = max(op1,max(op2,op3));
      ans.second = max(left.second , right.second) + 1;
      return ans;

      

}


int main(){

    node* root = NULL;
    //creating a tree

    root = buildtree(root);
    return 0;

}