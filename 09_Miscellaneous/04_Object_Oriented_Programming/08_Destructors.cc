#include<iostream>
#include<cstring>
using namespace std;

class Car {
private:
    float price;
public:
    int model_num;
    char *name;
    Car() {
        name = NULL;
    }
    Car(float p, int m, char *n) {
        price = p;
        model_num = m;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    // Copy Constructor For Deep Copy
    Car(Car &x) {
        cout << "Inside Copy Constructor\n";
        price = x.price;
        model_num = x.model_num;
        name = new char[strlen(x.name) + 1];
        strcpy(name, x.name);
    }
    void set_price(int p) {
        price = p;
    }
    void print() {
        cout << "Name : " << name << endl;
        cout << "Model Number : " << model_num << endl;
        cout << "Price : " << price << endl;
    }
    ~Car() {
        cout << "Inside Car Destructor " << name << endl;
        if(name != NULL) {
            delete [] name;
        }
    }
};

int main() {
    // Statically Created Car Object
    Car c(100, 200, "BMW"); // Parameterized Constructor
    Car d(c);
    d.name[0] = 'A';
    d.set_price(400);
    c.print();
    d.print();

    // Dynamically Created Car Object
    Car *e = new Car(10, 20, "Nano");
    e->print(); // or (*e).print();
    // Use Delete Keyword To Destruct Dynamically Created Objects
    delete e;
    return 0;
}