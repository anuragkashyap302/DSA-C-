#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node*prev;
    node*next;
    
    //constructor
    node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
// destructor
    ~node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }

};
void shurumedaliye(node*&head,int data){
    node* temp = new node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;

}

void antmedaliye(node*&tail,int data){//agar head se karna ho temp ko next tak dorate jao jaha null mile de do
    node* temp = new node(data);
    tail->next = temp;
    temp->prev = tail;
   tail = temp;


}
void kahibhidaliye(node*&head,int pos,int data){
     node* temp = head;
     if(pos==1){
        shurumedaliye(head,data);
     }
      node* nodetoinsert = new node(data);
      for(int i = 1; i<pos-1;i++){
        temp = temp->next;


      }
      nodetoinsert->next = temp->next;
      temp->next->prev = nodetoinsert;
      temp->next = nodetoinsert;
      nodetoinsert->prev = temp;
      
     
     


}




   void print (node*&head){
    node*temp = head;
    while (temp!= NULL)
    {
        cout<< temp->data<<" ";
        temp = temp->next;
        
    }
    cout<< endl;
    
     }
int main(){
    node* head = NULL;
    node* tail = NULL;
    print(head);

    return 0;

}