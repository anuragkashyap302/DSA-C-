#include<iostream>
using namespace std;
class A{ //Abstract class
public:
	virtual void show() = 0; //pure virtual function
	void display(){
		cout<<"Hi: I am base class function";
	}
};
class B : public A{
public:
	void show(){
		cout<<"I am derived class";
	}
};
int main(){
	//A objA; // object of virtual class not allowedd
	//objA.display();
	B objB;
    objB.display();
    objB.show();
	A *ptr; //you can use B*ptr also
	ptr = &objB;
	ptr->display(); // ye base class ka function ka jo ki drived class pointer se acess kar rahe hai
    ptr->show();
	return 0;
}

// #include <iostream>
// using namespace std;

// // Base class
// class Animal {
// public:
//     // Virtual function to allow overriding
//     virtual void sound() {
//         cout << "Animal makes a sound" << endl;
//     }
// };

// // Derived class
// class Dog : public Animal {
// public:
//     // Overriding the sound function
//     void sound() override {
//         cout << "Dog barks" << endl;
//     }
// };

// // Another derived class
// class Cat : public Animal {
// public:
//     // Overriding the sound function
//     void sound() override {
//         cout << "Cat meows" << endl;
//     }
// };
// //you csn create apointer to abstarct class and then create a objcet of drived class
// int main() {
//     Animal* animal1 = new Dog();  // Base pointer to derived class object
//     Animal* animal2 = new Cat();  // Base pointer to another derived class object
    
//     animal1->sound();  // Calls Dog's sound function
//     animal2->sound();  // Calls Cat's sound function
    
//     delete animal1;
//     delete animal2;
    
//     return 0;
// }
