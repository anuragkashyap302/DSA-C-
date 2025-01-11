//define your own exceptions by inheriting and overriding exception class functionality. 

#include <iostream>  
#include <exception>  
using namespace std;  
class MyException : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "Attempted to divide by zero!\n";  
        }  
};  
int main()  
{  
    try  
    {  
        int x, y;  
        cout << "Enter the two numbers : \n";  
        cin >> x >> y;  
        if (y == 0)  
        {  
            MyException z;  
            throw z;  
        }  
        else  
        {  
            cout << "x / y = " << x/y << endl;  
        }  
    }  
    catch(exception& e)  
    {  
        cout << e.what();  
    }  
}  


#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Custom exception class inheriting from std::exception
class CustomException : public std::exception {
private:
    string message;
public:
    CustomException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

void testFunction(int num) {
    if (num < 0) {
        throw CustomException("Negative number is not allowed in custom exception");
    }
    cout << "Number is: " << num << endl;
}

int main() {
    try {
        testFunction(-1);
    }
    catch (const CustomException& e) {
        cout << "Caught custom exception: " << e.what() << endl;
    }

    return 0;
}
