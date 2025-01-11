// Program to illustrate the working of
// objects and class in C++ Programming

#include <iostream>
//using namespace std;

// create a class
class Room {

   public:
    double length;
    double breadth;
    double height;

    double calculateArea() 
    {
        return length * breadth;
    }

    double calculateVolume() 
    {
        return length * breadth * height;
    }
};

int main() {

    // create object of Room class
    Room room1;
    // name of the class (Room) name of the object (room1)

    // assign values to data members
    room1.length = 42.5;
    room1.breadth = 30.8;
    room1.height = 19.2;

    // calculate and display the area and volume of the room
    std::cout << "Area of Room =  " << room1.calculateArea() <<  std::endl;
                                // name of the object. name of the member function
    std::cout << "Volume of Room =  " << room1.calculateVolume() <<  std::endl;

    return 0;
}