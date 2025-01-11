#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    //constuctor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
         
    }
};
class INFO{
  public:
  int maxi;
  int mini;
  bool isBST;
  int size;
};


void INORDER(Node*root){
    if(root == NULL){
        return;
    }
    INORDER(root->left);
    cout<< root->data << " ";
    INORDER(root->right);
}
INFO solve(Node*root,int &ans){
     //base case
     if(root == NULL){
        //size 0 kar diye;
        return {INT16_MIN,INT16_MAX,true,0};
     }
     INFO leftans = solve(root->left ,ans);
     INFO rightans = solve(root->right,ans);
     // recusion pauch chuka ko last node tak call marte marte
     // yni hum cuur node pe hai yahi se ab sab call wapas
     //jayega
     INFO currnode;
     // leftans and rightans me joki NULL hone wala hai kyki hum last node pe khare hai size ,mini,maxi,sab kuch bhar diya hoga base case
     // to hume curr node me sab kuch store kar lena hai 
     //kyki ye node bhi kisi prev call ko return karega apna ans
     currnode.size = leftans.size + rightans.size + 1;
     currnode.maxi = max(root->data,rightans.maxi);//curr node ka max vale uske right wubtree ke ans ka maxmium value hoga
     currnode.mini = min(root->data ,leftans.mini);//mini is liye chiye kyki jis call pe hum abi hai usak root ka value right ke min se chota and left ke min se bada hona chiye
     if(leftans.isBST && rightans.isBST && leftans.maxi<root->data<rightans.mini){
        // agar ye sab condion satify hai matab cuurnode bst foolw kar raha hai
        currnode.isBST = true;
     }
     else{
        currnode.isBST = false;
     }
     //answer update
     if(currnode.isBST){
        ans = max(ans,currnode.size);
     }
     return currnode;

}
int LARGESTBST(Node*root){
    int maxsize = 0;
    INFO temp = solve(root,maxsize);
    return maxsize;
}





Node*INSERTTOBST(Node*root , int data){
    //basee case kya hai
    if(root == NULL){
        // nayya node bana do aur kya
        root = new Node(data);
    }
     if(data > root->data){
        root->right =  INSERTTOBST(root->right,data);
     }
     else{
        root->left =  INSERTTOBST(root->left ,data);
     }
     return root;

}

void takeinput(Node*&root){
    int data;
    cin>> data;
    while(data!= -1){
     root = INSERTTOBST(root ,data);
     cin >> data;
    }
}
int main(){
    Node*root = NULL;
    cout << "enter data for BST"<< endl;
    takeinput(root);
    INORDER(root);

}