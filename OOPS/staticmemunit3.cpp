


#include<iostream>
using namespace std;
class staticMember {
public: 
	static int a; //Static member declaration
	int b; //Normal member
	void get() {
		cout<<"a = "<< a <<endl;
		cout<<"b = "<< b <<endl;
	}
};
int staticMember::a= 11;

//type name of the class:: name of the variable = value
 //Defined with intial value "0"

int main(){
	staticMember:: a = 100; // name of the class :: static var name = vale;
	cout<<"a = "<< staticMember::a <<endl;
	staticMember obj;
	obj.b = 10;
	obj.get();
	return 0;
}