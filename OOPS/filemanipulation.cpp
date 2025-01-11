#include <iostream>
#include <iomanip>
using namespace std;
 
/*endl It is used to enter a new line with a flush.

setw(a) It is used to specify the width of the output.

setprecision(a) It is used to set the precision of floating-point values.

setbase(a) It is used to set the base value of a numerical number.*/

int main()
{
    float PI = 3.141233546;
    int num = 100;
    cout << "Entering a new line." << endl;
    cout << setw(2) << "Output" << endl;
   //cout << "Output" << endl;
    cout << setprecision(5) << PI << endl;
    cout << setbase(16) << num << endl; //sets base to 16
}