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

void levelordertraversal(node* root){
     queue<node*> q;
     q.push(root);//pura root node push ho gaya
     q.push(NULL);
     while(!q.empty()){
        node * temp = q.front();
        q.pop();

        if(temp == NULL){
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);

            }
        }

        else{
            cout << temp->data << " ";
            if(temp->leftchild){
                q.push(temp->leftchild);
            }
            if(temp->rightchild){
                q.push(temp->rightchild);
            }
            
        }
     }
}

void inordertraversal(node*root){
    //base case
    if(root == NULL){
        return ;
    }
    inordertraversal(root->leftchild);
    cout << root-> data << " ";
    inordertraversal(root->rightchild);
}

void preordertraversal(node*root){
    //base case
    if(root == NULL){
        return ;
    }
    cout << root-> data << " ";
    preordertraversal(root->leftchild);
    preordertraversal(root->rightchild);
}

void postordertraversal(node*root){
    //base case
    if(root == NULL){
        return ;
    }
    postordertraversal(root->leftchild);
     postordertraversal(root->rightchild);
    cout << root-> data << " ";
    
   
}

void bulidtreefromlevelorder(node* &root){
    queue <node*> q;
    cout << "enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        cout << "enter left node for :" << temp->data << endl;
        int leftdata;
        cin >> leftdata ;

        if(leftdata != -1){
            temp->leftchild = new node(leftdata);
            q.push(temp->leftchild);

        }

        cout << "enter right node for :" << temp->data << endl;
        int rightdata;
        cin >> rightdata ;

        if(rightdata != -1){
            temp->rightchild = new node(rightdata);
            q.push(temp->rightchild);
            

        }
    }
}

vector< int> zigzagtraversal(node*root){
    vector <int> result;
    if(root== NULL){
        return result;
    }

    queue<node*> q;
    q.push(root);
    //ek flag bana liye jo ki batayga ki inserting kis taraf se honi chiye
    bool lefttoright = true;
      while(!q.empty()){
        int size = q.size();
        vector <int> ans(size);

        // har ek leval ko process karo
        for(int i =0; i<size; i++){
            node* frontnode = q.front();
            q.pop();
            // normal insret or reverse insert
            int index = lefttoright ? i : size - i -1 ;
           ans[index] = frontnode->data;


           if(frontnode->leftchild){
            q.push(frontnode->leftchild);
           }

           if(frontnode->rightchild){
            q.push(frontnode->rightchild);
           }

        }
        //yaha tak ek level print ho gya hoga 
        // ab direction reverse kar do
        lefttoright = !lefttoright;
        for(auto i: ans){
            result.push_back(i);
        }
      }
      //yaha tak while loop chelga jab tak q empty na ho jaye samjhe
      return result ;
}




int main() {
    node* root = NULL;
    //creating a tree

    root = buildtree(root);

}