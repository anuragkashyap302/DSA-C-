#include<iostream>
using namespace std;
class kqueue {


    public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    public:
    kqueue(int n,int k){
        this -> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];
        for(int i= 0; i <k; i++){
            front[i]= -1;
            rear[i]=  -1;

        }


        next = new int [n];

        for(int i= 0;i < n; i++){
            next[i]= next[i+1];//agla khali spot bhar diye

        }
        next[n-1]= -1;
        arr = new int [n];
        freespot = 0;

    } 

    void enqueue(int data ,int qn){
        //overflow
        if(freespot == -1){
            cout<<"no empty spceis present"<<endl;
            return;

        }
        //find first inedex
        int index = freespot;
        //updatefreespot

        freespot = next[index];
        //cheak wheter first elemrnt

        if(front[qn-1] == -1){//nth queue ka front -1 hai to first element hai
        front[qn-1] = index;

        }

        else{
            //link new element to prev element of same queue
            next[rear[qn-1]] = index;
        }
        //update next
        next[index] = -1;//matlab jagah fulll
        //update rear
        rear[qn-1] = index;//rear to kisi bhi queue ka last inserted elemrnt pe hoga whi chep diye

        //push kar do abb rearpe
        arr[index] = data;//rear pe push ho gaya hai

         
    }

    int dequeue(int qn){
        //underflow
        if(front[qn-1] == -1){
            cout<<"uenfdERfloew"<< endl;
            return -1;
        }
        //find index to pop
        int index = front[qn-1];//kisi bhi nth queue ka front ho uski ko to pop karna hai
        //front ko aage badho lekin dhyan rahe front++ nhi karna hai kyki nth queue front ke baad 
        // dursa queue bhi chalu ho sakta hai na hamko chaiye nth quue ka next element to wo next me milega
        
        front[qn-1]= next[index];//next to element ka location rakhta hai aur khali spce bhi bata a hai

        // freeslot ko manage karo
        next[index] = freespot;
        freespot = index; //jaha se front pop hua wo bhi khali hai uso shuru me index me rakh liye the

           return arr[index];

    }
   

};

int main(){
  kqueue Q(10,3);//10 size me 3 que bna liye
  Q.enqueue(10,1);
  Q.enqueue(15,1);
  Q.enqueue(20,2);//dusre que me push iska apna front and rear hogawo kahi bhi ho sakta 10 size
  //jari nhi ki lagatar ho iska track front and rear array rahega apne apne quue ka
  Q.enqueue(25,1);

  cout<< Q.dequeue(1)<< endl;
  cout<< Q.dequeue(2)<< endl;//durse que se pop kiye 
  cout<< Q.dequeue(1)<< endl;
  cout<< Q.dequeue(1)<< endl;

  cout<< Q.dequeue(1)<< endl;



    return 0;
}