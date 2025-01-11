#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Display from Base class (no arguments)" << endl;
    }
};

class Derived : public Base {
public:
    void display(int x) {
        cout << "Display from Derived class with argument: " << x << endl;
    }
};

int main() {
    Derived obj;
   // obj.display();  // This will result in a compiler error
  //  obj.display(5); // Calls Derived class's display(int)
  //  obj.Base::display(); // Calls Base class's display() with no arguments
    return 0;
}
