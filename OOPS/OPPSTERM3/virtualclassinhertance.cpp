#include <iostream>
using namespace std;
class A {
public:
	void show()
	{
		cout << "Hello form A \n";
	}
};
// HrInheritance
class B : public A {
};
class C : public A {
};
class D : public B, public C {//Multiple
};
int main()
{
	D object;
	 //object.show();
     //error show is ambigous
     // beacuse d drived show from b and c both
}