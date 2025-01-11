#include<iostream>
#include<queue>
using namespace std;
int main(){
    //create a queqe
    queue<int> q;
    q.push(11);
    cout<<"fornt of queue is " << q.front()<< endl;


    q.push(13);
    q.push(15);

    cout<<"size of queue is " <<q.size() <<endl;

    q.pop();

    cout<<"fornt of queue is " << q.front()<< endl;
    cout<<"size of queue is " <<q.size() <<endl;

    q.pop();
    q.pop();
    cout<<"size of queue is " <<q.size() <<endl;
    if(q.empty()){
        cout<<" quee is empty " << endl;

    }
    else{
        cout<<"queue is not empty  " << endl;
    }


}
