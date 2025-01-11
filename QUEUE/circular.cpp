#include<iostream>
using namespace std;
class circularqueue{
int *arr;
int size;
int qfront ;
int qrear;
//consuteructur
public:
circularqueue(){
    size = 100001;
    arr = new int[size];
    qfront = -1;
    qrear = -1;

}
bool isempty(){
    if(qfront==qrear){
        return true;

    }
    else{
        return false;
    }

}
bool enqueue(int data){
    if((qfront==0&&qrear==size-1) || (qrear==(qfront-1)%(size-1))){
        cout<<"queue is full"<<endl;
        return false;


        
    }
    else if(qfront==-1){
       qfront= qrear =0;
       arr[qrear] = data;

    }
    else if(qrear == size-1&&qfront!=0){
        qrear = 0;
        arr[qrear] = data;


    }
    else{//normal
        qrear++;
        

    }
    arr[qrear] = data;
    return true;


}
int dequeue(){
    if(qfront==-1){
        cout<<"que is empty"<<endl;
        return -1;

    }
    int ans = arr[qfront];
    arr[qfront] = -1;
    if(qfront==qrear){//single element
    qfront =qrear =-1; 
        

    }
    else if(qfront== size-1){//front last me hai to usko zero pahucho
        qfront = 0;
    }
    else{
        qfront++;
    }
    return ans;

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