#include<iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 20;
    int *xptr;
    // Store The Address Of A Variable
    xptr = &x;
    cout << &x << endl;
    cout << xptr << endl;
    // Re-assign Another Address To The Pointer Variable 
    xptr = &y;
    cout << xptr << endl;
    return 0;
}