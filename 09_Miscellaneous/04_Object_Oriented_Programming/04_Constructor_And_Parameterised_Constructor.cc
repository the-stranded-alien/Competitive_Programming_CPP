#include<iostream>
#include<cstring>
using namespace std;

class Car {
private:
    float price;
public:
    int model_no;
    string name;
    // Overwritting Constructor
    Car() {
        cout << "Inside Car Constructor\n";
    }

    // Parameterised Constructor
    Car(float p, int m, string n) {
        price = p;
        model_no = m;
        name = n;
    }
    Car(float p) {
        price = p;
    }

    void set_price(float p) {
        int msp = 111;
        if(p > 0) price = p;
        else price = msp;
    }
    float get_price() {
        return price;
    }
    void print() {
        cout << "Name : " << name << endl;
        cout << "Model Number : " << model_no << endl;
        cout << "Price : " << price << endl;
    }
};

int main() {
    // Create An Object
    Car c; // Make A Call To The Constructor Function Present Inside The Class
    Car d(222, 333, "Audi");
    c.model_no = 112;
    c.name = "BMW";
    c.set_price(100);
    c.print();
    d.print();
    return 0;
}