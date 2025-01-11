//C++ program to access overridden function using pointer of Base type that points to an object of Derived class
#include <iostream>
using namespace std;
class Base {
   public:
     virtual void print() {
        cout << "Base Function" << endl;
    }
};
class Derived : public Base {
   public:
    void print () override{
        cout << "Derived Function" << endl;
    }
};
int main() 
{
//     Base *B1 = new Base();
//    B1->print();
//     Derived *derived1 = new Derived();
//     derived1->print();
//      Base *derived1 = new Derived();
//     derived1->print();
    // pointer of Base type that points to derived1
    Base derived2;
    Base* ptr;
    ptr = &derived2;
    // call function of Base class using ptr 
    ptr->print();  
}