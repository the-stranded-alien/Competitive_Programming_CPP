#include<iostream>
#include<cstring>
using namespace std;

class Car {
private:
    float price;
public:
    int model_no;
    string name;
    Car() { }
    Car(float p, int m, string n) {
        price = p;
        model_no = m;
        name = n;
    }
    // Copy Constructor
    Car(Car &x) {
        cout << "Copy Constructor Called\n";
        price = x.price;
        model_no = x.model_no;
        name = x.name;
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
    Car c;
    Car d(222, 333, "Audi");
    c.model_no = 112;
    c.name = "BMW";
    c.set_price(100);
    cout << "Car 'c' : \n";
    c.print();
    cout << "Car 'd' : \n";
    d.print();

    // Using Copy Constructor
    Car e(d);
    cout << "Car 'e' : \n";
    e.set_price(456);
    e.print();
    // Another Way Of Calling Copy Constructor
    Car f = e;
    cout << "Car 'f' : \n";
    f.print();
    return 0;
}