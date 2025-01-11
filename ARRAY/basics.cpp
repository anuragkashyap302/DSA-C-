#include<iostream>
using namespace std;
void printarray(int arr[],int size){
    cout<<"printing an array"<< endl;
    for(int i = 0;i<size;i++){
        cout<< arr[i]<<" ";

    }
    cout<<"printing done"<< endl;
}
int main(){
int number[15];
cout<<"value at 14 index"<< number[14]<<endl;

int second[20] = {2,7,11};
cout<<"value at second index"<<second[2]<<endl;

int third[15]={2,7};
printarray(third,15);

int fourth[15] = {0};//intilising location wih zero
printarray(fourth,15);

int fifth[15]={1};
printarray(fifth,15);

cout<<endl<<"everything is fine"<< endl <<endl;
//you can make any type of array
double firstdouble[15];
float firstfloat[10];
bool firstbool[9];




}