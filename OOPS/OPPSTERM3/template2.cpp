#include <iostream>
using namespace std;
// One function works for all data types. 
template <class Z = int> // agar int aaya toh thik nahi to apne hisab se set kar lunga
Z myMax(Z x, Z y)
{
	return (x > y) ? x : y;
}
int main()
{
	cout << myMax(3, 7) << endl; // Call myMax for int
	cout << myMax(3.0, 7.0)<< endl; // call myMax for double
	cout << myMax('z', 'e')	<< endl; // call myMax for char
	return 0;
}