// for sum array
#include<iostream>
using namespace std;
template <class T>
//template <typename T>
T sum(T a[], float size)
{
	T add = 0;
	for (int i=0; i<size; i++)
	{
		//cout<<a[i]<<endl;
		add = add + a[i];
	}
	return add;
}
int main(){
	int a[5] = {2,3,4,5,6};
	float b[5] = {2.3, 3.4, 4.5, 5.6, 7.7};
	cout<<"sum of array is = \t"<<sum(a,5)<<endl;
	//cout<<a[6]<<endl;
	cout<<"sum of array is = \t"<<sum(b,5)<<endl;
	return 0;
}