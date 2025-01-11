#include<iostream>
using namespace std;
/* local variable is same as a member's name */
class Test
{
public:
	int x;
public:
	void set (int x) //(int x)
	{
	// The 'this' pointer is used to retrieve the object's x
	// hidden by the local variable 'x'
	//	x = x; // second
	//this->x = x; //
   //(*this).x = x;
	}
	void print() 
	{ 
		cout << "x = " << x << endl;
	}
};
int main()
{
	Test obj;
	obj.set(15);
	obj.print();
	return 0;
}



#include<iostream>
using namespace std;
// this pointer
class thisPtr{
	int a, b;
public:
	void show(){
		a = 9;
		b = 10;
		cout<<"object address is\t"<<this<<endl;
		cout<<"a ="<<this->a<<endl;
		cout<<"b ="<<this->b<<endl;
	}
};
int main(){
	thisPtr obj;
	obj.show();
	return 0;
}