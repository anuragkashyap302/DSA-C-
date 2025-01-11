#include<iostream>
using namespace std;
class queue{
int *arr;
int size;
int qfront ;
int qrear;
//consuteructur
public:
queue(){
    size = 100001;
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


};

int main(){
   
    return 0;

}