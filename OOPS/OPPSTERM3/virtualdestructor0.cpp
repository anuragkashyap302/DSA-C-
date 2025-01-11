#include<iostream>
using namespace std;
class base {
public:
	base(){
		cout<<"I am base class constructor"<<endl;
	}
    virtual ~base(){
		cout<<"I am base class destructor"<<endl;
	}
};
class derived:public  base{
public:
	derived(){
				cout<<"I am derived class constructor"<<endl;
	}
	~derived(){
		cout<<"I am derived class destructor"<<endl;
	}
};
int main(){
	base *ptr = new derived; //pointer of base class and creating the object of dervied class;
   // derived objB;
	//base *ptr;
	//ptr = &objB;
	delete ptr;
	return 0;
}
