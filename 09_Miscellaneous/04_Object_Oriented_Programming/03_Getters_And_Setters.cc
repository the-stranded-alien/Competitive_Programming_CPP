#include<iostream>
using namespace std;

class Car {
private:
    float price;
public:
    int model_no;
    char name[20];
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
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';
    c.set_price(100);
    c.print();
    return 0;
}