/* Function overloading example. Where we can have
 * more than one functions with same name but different
 * number, type or sequence of arguments
 */
#include <iostream>
using namespace std;
int sum(int, int);
float sum(float, float);
float sum(int, float);
int main()
{
   int num1, num2, x;
   float num3, num4, y;
   cout<<"Enter two integer numbers: ";
   cin>>num1>>num2;
   //This will call the first function
   cout<<"Result: "<<sum(num1, num2)<< endl;

   cout<<"Enter two float numbers: ";
   cin>>num3>>num4;
   //This will call the second function
   cout<<"Result: " <<sum(num3, num4)<< endl;

   cout<<"Enter one int and one float number: ";
   cin>>x>>y;
   //This will call the third function
   cout<<"Result: " <<sum(x, y)<< endl;
   return 0;
}
int sum(int a, int b){
   return a+b;
}
float sum(float a, float b){
   return a+b;
}
/* Remember that sum of int and float is float
 * so the return type of this function is float
 */
float sum(int a, float b){
   return a+b;
}