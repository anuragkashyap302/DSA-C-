#include<iostream>
using namespace std;
class Student{ //Student namm ka ek user define data type ban gaya ab tum usme kuch bhi store kar sakte ho
public:
   string name;
   int roll_no;
   float cgpa;
   //you can store any data type arr, vec, etc all comes under student class

   //defalut consturcter phele se maojud hota hai
   Student(){ //cons1

   }

   //consturcter
   Student(string s , int r ){ //cons2
    name = s;
    roll_no = r;
   }

   Student(string s , int r, float g){ //cons3
    name = s;
    roll_no = r;
    cgpa = g;

   }
Student(int r , float g, string s){ //cons4
    name = s;
    roll_no = r;
    cgpa = g;

   }


};
int main(){

    //aisa assign defalut conasturter ke case me
//     Student S1; 
//     S1.name = "lover boy";
//     S1.roll_no = 80;
//    S1.cgpa = 8.4;
//sab ko ek sath assign karna hai to constucter
 
//ye assign hoga constructer 2 se
 Student S1("anurag kashyap" , 80);  
 S1.cgpa = 8.4;

//ye defalut consturceter se
    Student S2;
    S2.roll_no = 40;
    S2.name = "lover boy";
    S2.cgpa = 4.4;

    //ye assing hoga construceter 3 se

    Student S3("laudu" , 15 , 7.6);


     Student S4(36 , 6.4 , "juju"); //ye consturcter 4 se assing hoga
     //ye 3 se same hai parrmeter wise but order imp hai boss

  Student S5 = S1; //deep copy of s1
  //agar s5 me kuch change karnge to s1 me kuch cahnge nahi hoga
  S5.name ="cahange in deep copy";


  Student S6(S1); //copy consturter
  S6.name ="chane in copy constructer";
  //s1 me kuch change nahi hoga


     cout<<S1.name<<" "<<S1.roll_no<<" "<<S1.cgpa<<" "<<endl;
      cout<<S2.name<<" "<<S2.roll_no<<" "<<S2.cgpa<<" "<<endl;
     cout<<S3.name<<" "<<S3.roll_no<<" "<<S3.cgpa<<" "<<endl;


    return 0;
}