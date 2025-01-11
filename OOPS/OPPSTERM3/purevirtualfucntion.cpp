// C++ program to calculate the area of a square and a circle
#include <iostream>
using namespace std;
// Abstract class
class Shape {
   protected:
    float dimension;
   public:
    void getDimension() {
        cin >> dimension;
    }
    // pure virtual Function
    virtual float calculateArea() = 0; // do nothing function
};

// Derived class
class Square : public Shape {
   public:
   float calculateArea() {
     cout<<"sqare ka karne aaya "<<endl;
      return dimension * dimension;
    }
};

// Derived class
class Circle : public Shape {
   public:
    float calculateArea() {
        cout<<"circle ka karne aaya "<<endl;
        return 3.14 * dimension * dimension;
    }
   // virtual float calculateArea() = 0;
};
int main() {
   // Shape shape;// cannot make the object of abstarct class
	Square square;
    Circle circle;
// ulta pulta kar diye result dekaho aur maze lo
    cout << "Enter the length of the square: ";
    square.getDimension();
    cout << "Area of square: " << circle.calculateArea() << endl;

    cout << "\nEnter radius of the circle: ";
    circle.getDimension();
    cout << "Area of circle: " << square.calculateArea() << endl;

    return 0;
}