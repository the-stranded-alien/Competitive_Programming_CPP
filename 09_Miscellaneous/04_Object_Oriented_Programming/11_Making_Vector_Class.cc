#include<iostream>
using namespace std;

// Define A Vector Class (User Defined Vector)
class Vector {
    int *arr;
    int curSize;
    int maxSize;
public:
    Vector(int defaultSize = 4) {
        maxSize = defaultSize;
        curSize = 0;
        arr = new int[maxSize];
    }
    void operator()(string s) { // Functor
        cout << "String : " << s << " -> () Got Overloaded\n";
    }
    void push_back(int data) {
        if(curSize == maxSize) { // Doubling
            int *oldArray = arr;
            arr = new int[2 * maxSize];
            maxSize *= 2;
            for(int i = 0; i < curSize; i++) arr[i] = oldArray[i];
            delete [] oldArray;
        }
        arr[curSize] = data;
        curSize++;
    }
    bool empty() {
        return (curSize == 0);
    }
    void pop_back() {
        if(!empty()) {
            curSize--;
        }
    }
    int at(int i) {
        return arr[i];
    }
    int getSize() {
        return curSize;
    }
    int getMaxSize() {
        return maxSize;
    }
    void print() {
        for(int i = 0; i < curSize; i++) cout << arr[i] << " ";
        cout << endl;
    }
    // Operators Over User Defined Class
    int& operator[](int i) {
        // Return By Reference
        return arr[i];
    }
};

// Cascading Of Operator
ostream& operator << (ostream &os, Vector &v) {
    v.print();
    return os;
}

istream& operator >> (istream &is, Vector &v) {
    // Input A Vector
    return is;
}

int main() {
    Vector v;
    for(int i = 0; i <= 3; i++) {
        v.push_back(i * i);
    }
    cout << v.getMaxSize() << endl;
    v.push_back(7);
    cout << v.getMaxSize() << endl;
    v.print();
    cout << v[3] << endl;
    // for(int i = 0; i < v.getSize(); i++) cout << v[i] << " ";
    cout << v;
    // Looking Like A Function, But It Is An Object
    // [Functor : Functional Objects]
    Vector fun;
    fun("Delhi");
    Vector v2;
    v2 = v;
    cout << v << v2;

    v[2] = 8;
    v[2] += 6;
    cout << v[2];

    return 0;
}