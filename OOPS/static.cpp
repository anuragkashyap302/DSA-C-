#include <iostream>
using namespace std;

class Employee {
    int id;
    
public:
    static int count;  // Declaration of static data member
    
    Employee(int id) {
        this->id = id;
        count++;  // Increment the static count whenever an object is created
    }

    void display() {
        cout << "Employee ID: " << id << endl;
    }

    // Static function to access static data member
    static void showCount() {
        cout << "Total Employees: " << count << endl;
    }
};

// Initialize the static data member outside the class
int Employee::count = 0;

int main() {
    Employee e1(101), e2(102), e3(103);
    
    e1.display();
    e2.display();
    e3.display();

    // Accessing static data member using static function
    Employee::showCount();  // Output: Total Employees: 3

    return 0;
}
