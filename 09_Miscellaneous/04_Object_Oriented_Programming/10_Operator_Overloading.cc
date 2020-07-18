#include<iostream>
using namespace std;

class Complex {
    int real;
    int img;
public:
    // Constructor
    Complex() {
        real = 0;
        img = 0;
    }
    // Parameterized Constructor
    Complex(int r, int i) {
        real = r;
        img = i;
    }
    // Copy Constructor
    Complex(Complex &c) {
        real = c.real;
        img = c.img;
    }
    // Setters & Getters
    void setReal(const int r) {
        real = r;
    }
    void setImg(const int i) {
        img = i;
    }
    int getReal() const {
        return real;
    }
    int getImg() const {
        return img;
    }
    void add(const Complex &x) {
        real += x.real;
        img += x.img;
    }
    // Operator Overloading
    void operator+(const Complex &x) {
        real += x.real;
        img += x.img;
    }
    void operator!() {
        img *= -1;
    }
    int operator[](string s) {
        // cout << real << " + " << img << "i " << s << endl;
        if(s == "real") return real;
        else return img;
    }    
    void print() const {
        if(img > 0) cout << real << " + " << img << "i\n";
        else cout << real << " - " << (-img) << "i\n";
    }
};
// Overloading << and >> Operator For Input and Output
// Cascasding Of Operators
istream& operator>>(istream& is, Complex &c) {
    int r1, i1;
    is >> r1 >> i1;
    c.setReal(r1);
    c.setImg(i1);
    return is;
}

ostream& operator<<(ostream& os, Complex &c) {
    c.print();
    return os;
}

int main() {
    Complex c1(5, 3);
    Complex c2;
    c2.setReal(1);
    c2.setImg(4);
    c1.print();
    c2.print();
    // c1.add(c2);
    c1 + c2;
    !c1;
    c1.print();
    cout << c1["real"] << endl;
    cout << c1["img"] << endl;

    Complex d;
    cin >> d;
    cout << d;

    
    Complex d1, d2;
    cin >> d1 >> d2;
    cout << d1 << d2;
    return 0;
}