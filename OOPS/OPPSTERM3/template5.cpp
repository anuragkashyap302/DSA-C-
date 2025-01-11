#include <iostream>
using namespace std;

template <class T > 
T func(T x) 
{
	cout<<"template wala";
	return x;
}
template <class T> 
int  func(int x) 
{
	cout<<"int wala karne aaye hai";
	return x;
}
int main()
{
	cout << func(3) << endl; // apne hisab se function call ho jayrga
	cout << func(3.5) << endl;
	return 0;
}