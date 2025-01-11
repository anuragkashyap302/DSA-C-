#include<iostream>
using namespace std;

class Cricketer{
    public:
   string name;
   int runs;
   //constucter
   Cricketer(string name , int runs){
  //  name = name;
  //  runs = runs;
    // class varible and constturter varible same rakhe pe output me  garbage value aa rahar hai compiler cofuse ho gaya hai
    //error nahi aayega koi bas garbage value print hogi
    //kyki c1 ke string and runs me pucha hi nahi consturcter call
    //main se constructer call hua uske naame me naame chla gya and runs me runs jab waha se c1 ke dabbe me jjane ki bari aayi to 
    //gdbd ho gaya

    //that'why we use this keyword
    this->name = name;
    this->runs = runs;
    //this jo hi wo class varible ko refer kar deata hi confusion dur kar deta hai
   }
};

void change(Cricketer* c){
 //   c.name = "anurag"; //agar pass by value hai to change nahi hoga
// y;aha kuch chnge karnge to origanl me kuch nahi hoga
//agar karna cahate ho to pass by refece karke derfrence kar do
 // (*c).runs = 35000;//ab change ho jayega
  c->runs = 44000; //same kaam karga
//c me avg pada hai jis adress pe pada hia waha jake change kar do yaha c us c1 ko hi recvice kiya hai pass by refrence
}

int main(){
    Cricketer C1("Virat Kohli" , 25900);
     Cricketer C2("Rohit Sharma" , 15900);

     //object pointer
     Cricketer*P1 = &C1;
    //  //p1 me c1 ka sba kuch store ho gya
    //  //same int pointer ki tarah ab p1 se c1 ko acess kar saker hai

    //  cout<<C1.runs;
    //  cout<<(*P1).runs<<endl;//c1 .runs hi hai

    //  //ab tum c1 ka data change bhi kar sakter ho thoruch p1 same as int 
    //  (*P1).name = "p1 se cahnge";
    //  cout<<C1.name<<endl;//p1 se c1 ke sath kuch bhi kar sakter hai

    cout<<C1.runs<<endl;
    change(&C1); //ab change ho jyega pass by refeece

    //change karne ka dusra method
    P1->runs = 45000; //ab c1 ka change ho jayega
     cout<<C1.runs<<endl;


     return 0 ;

}