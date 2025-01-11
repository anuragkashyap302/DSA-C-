#include <iostream>
using namespace std;
// One function works for all data types. 
//template <typename T1, typename T2> 
//template <class T1, class T2>
template <class T1= char, typename T2>

float sum(T1 x, T2 y)
{
	return x+y;
}

int main()
{
	cout<< "Int sum is\n="<<sum(8,9)<<endl;
	cout<< "Float sum is\n="<<sum(8.2,9)<<endl;
	cout<< "Float sum is\n="<<sum(8,9.2)<<endl;
	cout<< "Float sum is\n="<<sum('a', 5)<<endl;
    cout<< "Float sum is\n="<<sum(8.3,'b')<<endl;
	 cout<< "Float sum is\n="<<sum<>(5, 6)<<endl;

	return 0;
}