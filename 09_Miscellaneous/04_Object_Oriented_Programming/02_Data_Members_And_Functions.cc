#include<iostream>
using namespace std;

class Car {
public:
    float price;
    int model_no;
    char name[20];
    void print() {
        cout << "Name : " << name << endl;
        cout << "Model Number : " << model_no << endl;
        cout << "Price : " << price << endl;
    }
    float get_discounted_price(float x) {
        return (price * (1.0 - x));
    }
    float apply_discount(float x) {
        price = price * (1.0 - x);
        return price;
    }

};

int main() {
    Car c;
    c.price = 100;
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';
    cout << "Name : " << c.name << " Model No. : " << c.model_no << " Price : " << c.price << endl;
    cout << "Enter The Discount You Want To Give : ";
    float discount;
    cin >> discount;
    // cout << c.get_discounted_price(discount) << endl;
    cout << c.apply_discount(discount) << endl;
    c.print();

    Car d, e;
    
    return 0;
}