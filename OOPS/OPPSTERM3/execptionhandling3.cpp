// Program to handle any type of thrown 
//value using single catch block

#include<iostream>
using namespace std;
int main()
{	int a;
	try{
		cout<<"Testing any exception\n"<<endl;
		cout<<"Enter any number"<<endl;
		cin>>a;
		if(a==1) 
			throw 10;
		else if (a == 2)
			throw 'a';
		else 
			throw 1.2;
	}
	catch (...) //...
	{
		cout<<"Received the thrown value"<<endl;
	}
}