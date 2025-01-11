#include<iostream>
using namespace std;

class MyClass {
public:
    int data;
    void show() {
        cout << "Data: " << data << endl;
    }
};

int main() {
    MyClass obj;
    obj.data = 5;

    int MyClass::*ptrData = &MyClass::data;  // Pointer to data member
    void (MyClass::*ptrFunc)() = &MyClass::show;  // Pointer to member function

    cout << "Using .* operator: " << obj.*ptrData << endl;  // Access data member

    MyClass* pObj = &obj;
    (pObj->*ptrFunc)();  // Using ->* operator to call member function
}
