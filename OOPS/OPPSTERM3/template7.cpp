#include <iostream>
using namespace std;
// Class template
template <class T>
class Number {
private:
    // Variables of type T
    T a, b;
public:
    void getNumbers() {
        cin >> a >> b;
    }
    T sum();
};
// Define sum function outside the class template
template <class T>
T Number<T>::sum() {
    return a + b;
}

int main() {
    // Create object with int type
    Number<int> numberInt;
    
    //Name of the class name of the object;
    
    cout << "Enter two Integer numbers" << endl;
    numberInt.getNumbers();
    cout << "Sum of Integer numbers = " << numberInt.sum() << endl;

    // Create object with double type
    Number<double> numberDouble;
    
    cout << "Enter two double numbers" << endl;
    numberDouble.getNumbers();
    cout << "Sum of double numbers = " << numberDouble.sum() << endl;
    return 0;
}