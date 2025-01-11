#include <iostream>
using namespace std;

// Base class 1
class Base1 {
public:
    Base1() {
        cout << "Base1 Constructor" << endl;
    }
    ~Base1() {
        cout << "Base1 Destructor" << endl;
    }
};

// Base class 2
class Base2 {
public:
    Base2() {
        cout << "Base2 Constructor" << endl;
    }
    ~Base2() {
        cout << "Base2 Destructor" << endl;
    }
};

// Derived class from Base1 and Base2
class Derived : public Base1, public Base2 {
public:
    Derived() {
        cout << "Derived Constructor" << endl;
    }
    ~Derived() {
        cout << "Derived Destructor" << endl;
    }
};

int main() {
    Derived obj;  // Create an object of Derived class
    return 0;
}
