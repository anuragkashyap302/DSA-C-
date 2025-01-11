#include <iostream>
using namespace std;

class A {
public:
	void show()
	{
		cout << "Hello from A \n";
	}
};

class B :  public virtual A {
};

class C :  public virtual A {
};

class D : public  B, public  C {
};

class E: public D {
	
};

int main()
{
	E object;
	object.show();
}