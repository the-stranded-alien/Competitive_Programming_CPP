#include<iostream>
#include<cstring>
using namespace std;

// Const Data Members
// Const Parameters
// Const Functions
// Initialisation List

class Car {
private:
    float price;
public:
    int model_num;
    char *name;
    const int msp;
    // Initialisation List
    Car() : msp(99) {
        name = NULL;
    }
    Car(float p, int m, char *n, int minprice = 99) : price(p), msp(minprice) {
        price = p;
        model_num = m;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    // Copy Constructor For Deep Copy
    Car(const Car &x) : msp(x.msp) {
        cout << "Inside Copy Constructor\n";
        price = x.price;
        model_num = x.model_num;
        name = new char[strlen(x.name) + 1];
        strcpy(name, x.name);
    }
    void operator=(Car &x) {
        cout << "Inside Copy Assignment Operator\n";
        price = x.price;
        model_num = x.model_num;
        name = new char[strlen(x.name) + 1];
        strcpy(name, x.name);
    }
    float get_discounted_price(const float x) {
        return price * (1.0 - x);
    }
    float apply_discount(const float x) {
        price = price * (1.0 - x);
        return price;
    }
    void set_price(int p) {
        price = p;
    }
    float get_price() const {
        return price;
    }
    void print() const {
        cout << "Name : " << name << endl;
        cout << "Model Number : " << model_num << endl;
        cout << "Price : " << price << endl;
        cout << "Min. Selling : " << msp << endl;
    }
};

int main() {
    Car c(100, 200, "BMW"); // Parameterized Constructor
    Car d; // Constructor
    d = c; // Copy Assignment Operator
    d.set_price(400);
    d.name[0] = 'A';
    c.print();
    d.print();
    return 0;
}