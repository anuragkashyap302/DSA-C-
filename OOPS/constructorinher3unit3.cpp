//Base class Parameterized Constructor in Derived //class Constructor
#include <iostream>
using namespace std;
class Base
{ 
    int x;
    public:
    //default constructor
    Base(){
    cout << "Base default Constructor\n";
    }
    Base(int i) // parameterized constructor
    { 
        x = i;
        cout << "Base Parameterized Constructor\n";
    }
};
class Derived: public Base
{ 
    int y;
    public:
    	
    Derived():Base(){
    	cout<<"This is derived class default construcrtor\n";
	}
    // parameterized constructor
    Derived(int j):Base(j)
    { 
        y = j;
        cout << "Derived Parameterized Constructor\n";
    }
};
int main()
{   Base d1;
 	//Base d2(11);
 	Derived d2;
    Derived d(10);
}