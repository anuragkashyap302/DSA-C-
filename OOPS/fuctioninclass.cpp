
# include<iostream>
using namespace std;
class item // item is name of the class
{
	int number;
	float cost;
public:
	void getdata ( int a, float b);
	void putdata (void)
		{
			cout<<"Number\t"<<number<<endl;
			cout<<"Cost\t"<<cost<<endl;
		}
};
// return type class name :: function name
void item :: getdata (int a , float b)
	{
		number=a;
		cost=b;
	}

int main ( )
{
	item x; // Object 1 // name of the class
	// name of  object or class variable
	cout<<"Updating from Object x"<<endl;
	x.getdata(100,299.95);
	x.putdata();
	
	item y; // Object 2
	cout<<"Updating from Object y"<<endl;
	y.getdata(200,175.5);
	y.putdata();
	
	return 0;
}