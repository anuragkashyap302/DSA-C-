// nested try blocks
// how to throw value within another catch block
#include<iostream>
using namespace std;
int main(){
	try{ //outer try block try block ko kam se kam ek handle to chaiye
		cout<<"Hello"<<endl;
		try //inner try block
		{
			cout<<"Inner try block"<<endl;
			throw 3;
			throw 6;
				
		}
		catch(int x)
		{
			cout<<"throw working in inner catch block"<< x <<endl;
			throw ; // throwing value within another catch block yaha kuch nahi bhi mention karoge to x throw ho jyage
		}
	}
	catch(int y){//outer try block catch block
		cout<<"outer try block"<< y<< endl;
	}
return 0;
}