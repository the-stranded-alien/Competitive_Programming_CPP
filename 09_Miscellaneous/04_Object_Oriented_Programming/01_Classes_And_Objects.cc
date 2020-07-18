#include<iostream>
using namespace std;

// Equivalent To Defining A New Datatype
class Car {
    int price;
    int model_no;
    char name[20];
};

int main() {
    // Create An Object
    Car c;
    cout << sizeof(c) << endl;
    cout << sizeof(Car) << endl; // Size Of Memory Taken When We Create A 'Car' Object

    // Store Information About Max 20 Cars
    Car arr[20];

    return 0;
}