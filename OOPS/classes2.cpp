#include<iostream>
using namespace std;
class Car{ //Car namm ka ek user define data type ban gaya ab tum usme kuch bhi store kar sakte ho
public:
   string name;
   int price;
   float seats;
   string type;
   //you can store any data type arr, vec, etc all comes under student class


};

void print(Car c){ 
    //ye fundtion object recive kar raha hai lekin ye ek alag object c hai 
//wo nahi hai jo haum pass kar rahe hai
  cout<<c.name<<" "<<c.price<<" "<<c.seats<<" "<<c.type<<" "<<endl;

}
void change(Car c){
    c.name = "swift";
    //chane nahi hoga

}
int main(){
    Car C1; // car data type ka ek varible like int , float
    C1.name = "audi";
    C1.price = 8000000;
   C1.seats= 4;
   C1.type = "sedan";
    //you can take input of any member of class
    Car C2; // car data type ka ek varible like int , float
    C2.name = "fortuner";
    C2.price = 4000000;
   C2.seats= 8;
   C2.type = "suv";

   Car C3; // car data type ka ek varible like int , float
    C3.name = "scorpio";
     C3.price = 1000000;
   C3.seats= 6;
   C3.type = "belan";

   // bar bar har object ke liye alag se sab kuch assign karwana pad raaha hai that why we use consturcter

     //sab ko ek ek print nahi karna hai ek function bano and usme object pass kar do
       print(C1);
      print(C2);
       print(C3);
       change(C1);//pass by value ho raha hai 
       //agar pass by referece karna hai to &ka use kar lo
       cout<<"printing after changig the name by passing by value"<<endl;

       print(C1);

     


    return 0;
}