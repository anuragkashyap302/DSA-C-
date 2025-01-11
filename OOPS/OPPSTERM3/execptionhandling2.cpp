#include<iostream>
using namespace std;
int main(){
	try{
		cout<<"before throw\n"<<endl;
		
		throw 0;
		cout<<"after throw\n"<<endl;
	}

	
	catch(int x){
		cout<<x<<"is printed\n";
	}
	catch(...){
		cout<<"pata nahi expection kya hai\n";
	}
	cout<<"---";

return 0;
}