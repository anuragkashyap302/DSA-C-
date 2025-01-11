#include<iostream>
#include<map>
using namespace std;

class node{

    public:
    int data;
    node* next;

    //conustructer
    node(int data){
        this-> data = data;
        this -> next = NULL;
    }
    //destructor
    ~node(){
        int value = this->data;
        //memory free
        if(this->next!= NULL){
            delete next;
            this->next = NULL;
        }
      cout << " memory is free for node with data " << value << endl;  
    }

};
void antmedaliye(node*&tail,int d){
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
   
}

 void shurumedaliye(node*&head , int d){
    node* temp = new node(d);
    temp-> next = head;
    head = temp;
 }
 void print(node*&head){
    node*temp = head;
    while (temp!= NULL)
    {
        cout<< temp->data<<" ";
        temp = temp->next;
        
    }
    cout<< endl;
    
     }
     void kahibhidaliye(node*&tail ,node*&head ,int position ,int d){
        // starting me insertion
  if (position==1){
      shurumedaliye(head,d);
      return;
  }
  node*temp = head;
   int cnt = 1;

   while(cnt<position-1){
    temp = temp->next;
    cnt++;
   }
   // ending me insertion
   if(temp->next == NULL){
    antmedaliye(tail,d);
    return;
   }
   //creating a node for d
   node*nodetoinsert = new node(d);
   nodetoinsert->next = temp->next;
   temp->next = nodetoinsert;
  }
  void deletion(node*&head,int pos){
      if(pos == 1){
        node*temp = head;
        head = head->next;
        temp->next = NULL;
        delete(temp);

      }
      else{
        node*curr = head;
        node*prev = NULL;
        int cnt = 1;
        while(cnt<pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete(curr);
      }

  }
  bool isCircularList(node*& head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}
bool detectloop(node*head){
    if(head==NULL){
        return false;
    }
    map<node*,bool> visited; //ek map create kardiye jisme visted element ka record rsheaga
    
    node*temp = head; //traverse karne ke liyea
    while(temp!=NULL){
        //cheking if cycle is prsdent or not
        if(visited[temp]==true){//agar phele se visted hua to true dega
            cout<< "cycle is present for element at"<< temp->data<<endl;
         return true;
        }
        visited[temp] = true;//agar phele se visited nhi hai to ab kar do condn cheking ke bad
     temp = temp->next;
    }
    return false;// agar yaha tak pachuac gaye matalab loop nahi mila 

}
node* floyddetectloop(node*head){
    if(head == NULL)
        return NULL;

    node* slow = head;
    node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout << "present at " << slow -> data << endl;
            return slow;
        }
    }
    return NULL;
}

    node* getStartingNode(node* head) {

    if(head == NULL) 
        return NULL;

    node* intersection = floyddetectloop(head);
    node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

    }

void removeLoop(node* head) {

    if( head == NULL)
        return;

    node* startOfLoop = getStartingNode(head);
    node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
}

int main(){
    node* node1 = new node(10);
    //cout << node1 -> data << endl;
   // cout<< node1 -> next << endl;
    // head pointed to node1 in starting
    node* head = node1;
    node* tail = node1;
    print(head);
   // shurumedaliye(head,12);
   antmedaliye(tail,12);
    print(head);
   // shurumedaliye(head,15);
    antmedaliye(tail,15);
    antmedaliye(tail,22);

  //  tail->next = head->next;//cycle banene ke liye

  
  //  detectloop(head);

   // print(head);
 // kahibhidaliye(tail,head,4,22);
  // print(head);
  // cout <<" head " << head->data << endl;
  // cout <<" tail " << tail->data << endl;
  if(floyddetectloop(head) != NULL) {
        cout << "Cycle is present " << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }

    node* loop = getStartingNode(head);

    cout << "loop starts at " << loop -> data  << endl;

    removeLoop(head);
    print(head);

    /*
    print(head);

    if(isCircularList(head)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }
    */

   



    return 0;


}