#include <iostream>
#include <string>
#include <climits> // for INT_MIN
using namespace std;

int secondLargestDigit(const string& str) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (char ch : str) {
        if (isdigit(ch)) {
            int digit = ch - '0';
            if (digit > largest) {
                secondLargest = largest;
                largest = digit;
            } else if (digit > secondLargest && digit < largest) {
                secondLargest = digit;
            }
        }
    }

    return secondLargest == INT_MIN ? -1 : secondLargest;
}

int main() {
    string str = "2947578";
    int result = secondLargestDigit(str);
    
    if (result != -1) {
        cout << "The second largest digit is: " << result << endl;
    } else {
        cout << "There is no second largest digit." << endl;
    }
    
    return 0;
}
