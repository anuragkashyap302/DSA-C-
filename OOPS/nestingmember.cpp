//A member function can be called by using its name inside another member function of the
//same class. This is known as nesting of member functions.
#include<iostream>
using namespace std;
class set
{
	int m,n;
public:
	void input(void);
	void display (void);
	void largest(void);
};
void set::largest(void)
{
	if(m>n)
		cout<<"Largest:"<<m<<endl;
		//return m;
	else
		cout<<"Largest:"<<n<<endl;
		//return n;
}
void set::input(void)
{
	cout<<"input values of m and n:";
	cin>>m>>n;
}
void set::display(void)
{
	largest();
}
int main()
{
	set A; //class name name of the object
	A.input(); //name of the object.name of the function
	A.display();
	return 0;
}