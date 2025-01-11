#include<iostream>
using namespace std;
#include<stack>
class queue{
int *arr;
int size;
int qfront ;
int qrear;
//consuteructur
public:
queue(){
    size = 6;
    arr = new int[size];
    qfront = 0;
    qrear = 0;

}
bool isempty(){
    if(qfront==qrear){
        return true;

    }
    else{
        return false;
    }

}
void enqueue(int data){
    if(qrear == size ){
        cout<<"queue is full"<<endl;

        
    }
    else{
        arr[qrear] = data;
        qrear++;

    }

}
int dequeue(){
    if(qfront==qrear){
        cout<<"que is empty"<<endl;
        return -1;

    }
    else{
        arr[qfront] = -1;
        qfront++;
        if(qfront==qrear){//agar pop karne ke baad front rear ek hi jagha aa jaye to shuru me bhej do nahi to empty batayega
            qfront = 0;
           qrear = 0;
        }

    }

}
int front(){
    if(qfront == qrear){
        return -1;

    }
    else{
        return arr[qfront];

    }

}
void queueDisplay()
{
    int i;
    if (qfront == qrear) {
        cout << "Queue is empty" << endl;
        return;
    }

    // Traverse front to rear (inclusive) and print elements
    for (i = qfront; i < qrear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}
void reverse() {
    if (qfront == qrear) {
        cout << "Queue is empty, nothing to reverse" << endl;
        return;
    }

    stack<int> s;
    // Push all elements of the queue onto the stack
    while (qfront != qrear) {
        s.push(arr[qfront]);
        dequeue();
    }

    // Pop elements from the stack and enqueue them back to the queue
    while (!s.empty()) {
        enqueue(s.top());
        s.pop();
    }

    // Reset qfront to 0 and qrear to the index of the last element in the queue
    qfront = 0;
    qrear = size; // Update qrear to the next available position
}

};









int main(){
    queue q;
    q.enqueue(4);
     q.enqueue(3);
      q.enqueue(1);
       q.enqueue(10);
       q.enqueue(2);
       q.enqueue(6);

       q.queueDisplay();
       q.reverse();
       q.queueDisplay();


    
   
    return 0;

}