#include<iostream>
using namespace std;
class Student{ //Student namm ka ek user define data type ban gaya ab tum usme kuch bhi store kar sakte ho
public:
   string name;
   int roll_no;
   float cgpa;
   //you can store any data type arr, vec, etc all comes under student class

   //defalut consturcter phele se maojud hota hai
   Student(){

   }

   //consturcter
   Student(string s , int r ){
    name = s;
    roll_no = r;
   // cgpa = g;
   }


};
int main(){
//     Student S1; 
//     S1.name = "lover boy";
//     S1.roll_no = 80;
//    S1.cgpa = 8.4;
//sab ko ek sath assign karna hai to constucter
 

 Student S1("anurag kashyap" , 80 ); //hogya kaaam 
 //order in calling and reciving in constuceter same hona chaiye jaruri nahi ki pahle nam hi ho bas calling and recving ka order same hona chaiye

  //agar defalut consturcter nahi doge to tum one by one intillize nahi kar sakter ho
  //srif upper wale tarike se kara sakter agar dono tarike se karna chate ho to dono parmetrized and defalut constucter de do

  //jarui nahi hai jita varible hai tum utna hi parameter ka consturcter bano kam bhi bana sakte ho aur baki parmerter bahar se de dana

 S1.cgpa = 8.4; 
 //ypu can overwrite also 
 //S1.name = "muso" //ab ye print hoga

    Student S2;
    S2.name = "lover boy";
    S2.roll_no = 40;
    S2.cgpa = 4.4;

     cout<<S1.name<<" "<<S1.roll_no<<" "<<S1.cgpa<<" "<<endl;
      cout<<S2.name<<" "<<S2.roll_no<<" "<<S2.cgpa<<" "<<endl;
   //  cout<<S2.name<<" "<<S2.roll_no<<" "<<S2.cgpa<<" "<<endl;


    return 0;
}