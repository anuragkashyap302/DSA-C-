#include <iostream>
using namespace std;
 class A {
public:
	int a;
public:	
	A() // constructor
	{
		a = 15;
		cout<<"from class A\n";
	}
};
 class B :  virtual public  A {
 	public:
 	B() // constructor
	{
		//b = 20;
		cout<<"from class B\n";
	}
};
 class C :  virtual public   A {
	public:
     C(){
		cout<<"from class C\n";
	 }
};

class D :  virtual public  B, virtual public C {
	public:
	D() // constructor
	{
		//a = 15;
		cout<<"from class D\n";
	}
};

int main()
{
	D object; // object creation of class d
	//cout << "a = " << object.a << endl;
	//B ObjectB;
	//A ObjectA;
	//cout << "b = " << object.b << endl;

	return 0;
}