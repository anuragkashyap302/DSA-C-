// Example to demonstrate without catch block
#include<iostream>
using namespace std;
int main(){
	try{
		try{
			throw 23;
		}

		catch(int y){
			cout<<"mai andar balla \n";
			
		}
		throw ;
		
	}
	catch(int x){
            cout<<"catch ke andar aaya\n";
	}
	cout<<"Testing catch block \n"<<endl;
	return 0;
}