#include <iostream>
using namespace std;
// One function works for all data types. This would work
//template <typename T> //first method
template <class T> // second method
//return_type name_of_the_function(parameter)
T sum(T x, T y) 
{
	return x+y;
}
int main()
{
	cout << sum(3.2, 1.2) << endl; // 
	cout << sum(3.0, 7.0)<< endl; //
	cout << sum(3.22, 4.22)<< endl; // 
	return 0;
}