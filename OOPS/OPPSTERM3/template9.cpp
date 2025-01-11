#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Array {
private:
	T* ptr;
	int size;
public:
	 Array(T arr[], int s);//constrcutur
	void print();
};
template <typename T> 
Array<T>::  Array(T arr[], int s)
{
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++)
		ptr[i] = arr[i];
}
template <typename T> 
void Array<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << " " << *(ptr + i);
	cout << endl;
}
int main()
{
	int arr[5] = {1, 2, 3, 4, 5 };
	char s[5] = {'h','e','l','l','o'};
	Array<char> b(s, 11);
	Array<int> a(arr, 5);
	a.print();
	b.print();
	return 0;
}



#include <iostream> 

using namespace std; 

template <class T> class Test 
{ 
private: 
T val; 
public: 
static int count; 
Test() 
{ 
	count++; 
} 
// some other stuff in class 
}; 

template<class T> 
int Test<T>::count = 0; 

int main() 
{ 
Test<int> a; // value of count for Test<int> is 1 now 
Test<int> b; // value of count for Test<int> is 2 now 
Test<double> c; // value of count for Test<double> is 1 now 
cout << Test<int>::count << endl; // prints 2 
cout << Test<double>::count << endl; //prints 1 
	
getchar(); 
return 0; 
} 
