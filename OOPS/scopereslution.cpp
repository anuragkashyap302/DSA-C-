#include <iostream>
using namespace std;

int x = 100;  // Global variable

int main() {
    int x = 50;  // Local variable in main()
    cout << "Local x in main(): " << x << endl;
    cout << "Global x accessed with :: operator: " << ::x << endl;

    {
        int x = 20;  // Local variable in inner block
        cout << "Local x in inner block: " << x << endl;
        cout << "Global x accessed with :: operator: " << ::x << endl;
    }

    cout << "Local x in main() after inner block: " << x << endl;
    cout << "Global x accessed with :: operator: " << ::x << endl;

    return 0;
}
