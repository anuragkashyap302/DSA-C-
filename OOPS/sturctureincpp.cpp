/* This is a simple program to 
store information related to employees*/
#include <iostream> //Linker section // Header files
using namespace std; //Linker section

struct Person //class --> structure named person
{
    char name[50];
    int employee_no;
    float salary;
};
int main()
{
    Person p1; // a varible struc Person
    
    cout<< sizeof(Person);
    cout << "Enter Full name: ";
    cin.get(p1.name, 50);
    cout << "Enter employee_no: ";
    cin >> p1.employee_no;
    cout << "Enter salary: ";
    cin >> p1.salary;

    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p1.name << endl;
    cout <<"Age: " << p1.employee_no << endl;
    cout << "Salary: " << p1.salary;
    return 0;
}