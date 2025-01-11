#include<iostream>
#include<queue>
#include<vector>
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

void traverseleft(node*root,vector <int> &ans){
    //base case
    //khali left bala print no leaf  no right kyki call hi sift root ka left kiya gaya
    //hai main function se suar ab jo hoga usi side hoga
    if(root == NULL || (root->leftchild == NULL && root->rightchild == NULL)){
        return;
    }

    ans.push_back(root->data);
    if(root->leftchild){
        traverseleft(root->leftchild,ans);

    }
    else {
        // right child bhi travese karna left side ka left pura travese kar jao
        traverseleft(root->rightchild,ans);
 // agar root kisi spsific root ka leftchild nhi h to ho sakta 
 //hai uska right child ho to travese karlo par hoga left side me hi
 // smjhe
    }

}

void traverseleaf(node*root ,vector <int> &ans){
    //base case
    if(root == NULL){
        return ;
    }

    if(root->leftchild ==NULL && root->rightchild ==NULL){
        ans.push_back(root->data);
        return; 
    }

 ///leaf to tree ke dono side ho sakta hai na
    traverseleaf(root->leftchild,ans);
    traverseleaf(root->rightchild,ans);
}

void traverseright(node*root,vector <int> &ans){
    //base case
   // call aaya hai root->rigtchild to jo bhi hoga right side me hi hoga
    if(root == NULL || (root->leftchild == NULL && root->rightchild == NULL)){
        return;
    }
    if(root->rightchild){
        traverseright(root->rightchild,ans);

    }
    else {
/// agar right child na ho tabhi left ek baar cheking ke liy

        traverseright(root->leftchild,ans);

    }
    // puara taravse kar gaye niche tak ab tum 
    //ab wapas jayega recusion tpo print karte jao 
    //right side to revese order me print hona hai na
    ans.push_back(root->data);

}
// main fun deko boundry ka wahi sab call hua left leaf right
vector <int> boundrytraversal(node*root){

    vector <int> ans ;
    if(root ==NULL){
        return ans;
    }
    //tin part me travesse kargne
    //phele lefttraves me jao khli left side leke
    traverseleft(root->leftchild,ans);
    // leaf node

    traverseleaf(root->leftchild,ans);
    traverseleaf(root->rightchild,ans);
    //leaf node to dono taraf ho akta hai

    // ab right
     traverseright(root->rightchild,ans);
     return ans;


}


int main(){
    node* root = NULL;
    //creating a tree

    root = buildtree(root);

}