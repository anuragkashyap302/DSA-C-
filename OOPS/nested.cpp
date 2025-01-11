//A member function can be called by using its name inside another member function of the
//same class. This is known as nesting of member functions.

#include <iostream>
using namespace std;
class set
{
int m,n;
public:
	void input(void);
	void display (void);
	int largest(void);
};
int set::largest (void)
{
	if(m>n)
	return m;
	else
	return n;
}
void set::input(void)
{
	cout<<"input values of m and n:";
	cin>>m>>n;
}
void set::display(void)
{
	input();
	cout<<"largestvalue="<<largest()<<"\n";
	//largest();
}
int main()
{
	set A;
//	A.input( );
	A.display( );
	return 0;
}