#include <iostream>  
using namespace std;

int main()  
{  
    int size;  // variable declaration  
    cout << "Enter the size of the array: ";     
    cin >> size;  // Input the size of the array
    
    int *arr = new int[size];  // creating an array with the specified size
    
    cout << "\nEnter the elements: ";  
    for(int i = 0; i < size; i++)   // for loop  
    {  
        cin >> arr[i];  
    }  
    
    cout << "\nThe elements that you have entered are: ";  
    for(int i = 0; i < size; i++)    // for loop  
    {  
        cout << arr[i] << ", ";  
    }  
    
    delete[] arr;  // deleting the dynamically allocated array
    return 0;  
}
