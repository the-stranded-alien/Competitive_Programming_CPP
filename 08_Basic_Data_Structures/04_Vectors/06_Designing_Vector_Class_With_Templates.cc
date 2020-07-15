#include<iostream>
#include "06_Vector_With_Template.h"
using namespace std;

int main() {
    Vector<char> v;
    v.push_back(71);
    v.push_back(72);
    v.push_back(73);
    v.push_back(74);
    v.pop_back();
    v.push_back(80);
    cout << "Capacity : " << v.capacity() << endl;
    v.push_back(84);
    cout << "Capacity : " << v.capacity() << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}