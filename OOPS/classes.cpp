#include<iostream>
using namespace std;
class Student{ //Student namm ka ek user define data type ban gaya ab tum usme kuch bhi store kar sakte ho
public:
   string name;
   int roll_no;
   float cgpa;
   //you can store any data type arr, vec, etc all comes under student class


};
int main(){
    Student S1; // Student data type ka ek varible like int , float
    S1.name = "lover boy";
    S1.roll_no = 80;
   S1.cgpa = 8.4;
    //you can take input of any member of class
   // cin>>S1.cgpa;

    Student S2; // Student data type ka ek varible like int , float
    S2.name = "lover boy";
    S2.roll_no = 40;
    S2.cgpa = 4.4;

     cout<<S1.name<<" "<<S1.roll_no<<" "<<S1.cgpa<<" "<<endl;
     
     cout<<S2.name<<" "<<S2.roll_no<<" "<<S2.cgpa<<" "<<endl;


    return 0;
}