#include<iostream>
using namespace std;

class Cricketer{
    public:
   string name;
   int runs;
   //constucter
   Cricketer(string name , int runs){
  

    //that'why we use this keyword
    this->name = name;
    this->runs = runs;
    //this jo hi wo class varible ko refer kar deata hi confusion dur kar deta hai
   }
   void Print(int runs){
   cout<<name<<" "<<runs<<endl;
   cout<<this->name<<" "<<this->runs<<" "<<endl;
   //this use karne se aage dikkat nahi aayegga agr koi paran=meter same varible ka
   //recive karge print function me toh bhi kyki this toh object varible ko refer karta hai
   }

//kuch bhi function bana sakte ho
   int matches(){
    return runs/50;
   }
};


void print(Cricketer c){ 
    //ye fundtion object recive kar raha hai lekin ye ek alag object c hai 
//wo nahi hai jo haum pass kar rahe hai
  cout<<c.name<<" "<<c.runs<<endl;

}
int main(){
    Cricketer C1("Virat Kohli" , 25900);
     Cricketer C2("Rohit Sharma" , 15900);
     C1.Print(5); //bina koi parameter ke jaise class ke object ko treat karter the waise hi karna hai;
     C2.Print(7);
    return 0 ;

}