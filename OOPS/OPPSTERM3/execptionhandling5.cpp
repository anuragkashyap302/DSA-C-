// constructor and destructor 
#include<iostream>
using namespace std;
class test{
	public:
		test()
		{
			cout<<"I am the Constructor\n"<<endl;
		}
		~test() //destructor
		{
			cout<<"I am the Destructor\n"<<endl;
		}
};

int main(){
//test t;
	try{
		test t;
		cout<<"welcome to exception handling"<<endl;
		throw 10;
		cout<<"Testing Destructor\n"<<endl;
		// t ka life yahi tak hai isliye i am destructor yahi call ho jayega
	}
		catch(...){
			cout<<"kuch bhi throw karo pakad lunga"<<endl;
		}
	return 0;
}