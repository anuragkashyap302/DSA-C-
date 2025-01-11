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
vector <int> verticalorder(node*root){
    //ek map bakiye joki hd and level and level ka vector list stroe kare
    //har level pe value milaga hd ke liye usko usi me map karna hai jaise e.g me
    // 1st level me -1 hd ke liye 2 mila 1hd ke  3 mila
    //sabhi ko apne specfic hd e map kar diye

    map <int ,map< int ,vector<int>>> nodes ;

    //que joki level andd hd ka pair rakega aur node ko bhi store karega

 queue <pair <node*,pair<int,int>>> q;
    vector<int > ans;
    
if(root == NULL){
        return ans;
    }
    //que me phela level and hd push kar do root ke sath
    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        //temp me queue ka pura front store kar lie
        // pair<node*,pair<int , int> > is pure chhez ko ek variable man ke cholo
        // jaise calass me bhit chhez store hota hai

        pair<node*,pair<int , int> > temp =  q.front();
       node*frontnode = temp.first;
       int hd = temp.second.first;

       int lvl = temp.second.second;
       //yaha clear ho gaya na pair ke andar pair hai

       nodes[hd][lvl].push_back(frontnode->data);
       // us hd and level ka jo bhi hai wo q ke front me hai usko push karo

       //left me jao que me push karo usak leftchid
       //and usko hd and uska level
       if(frontnode->leftchild){
        q.push(make_pair(frontnode->leftchild,make_pair(hd-1,lvl+1)));

       }
     if(frontnode->rightchild){
        q.push(make_pair(frontnode->rightchild,make_pair(hd+1,lvl+1)));
        
       }

       for(auto i:nodes){
        for(auto j :i.second){
            for(auto k: j.second){
                ans.push_back(k);

            }
        }
       }
       return ans;

    }

}
int main() {

    node* root = NULL;
    root = buildtree(root);
    

}