#include <iostream>
using namespace std;

class Test {
private:
    int data;  // Static member (belongs to the class itself)

public:
    // Static display function
     void showData() {
        cout << "Data: " << Test::data << endl;  // Correct: accessing static member via Test::data
    }
};


// Initialize the static member outside the class
//int Test::data = 100;

int main() {
 //   Test::showData();  // Displays "Data: 100"

    return 0;
}
