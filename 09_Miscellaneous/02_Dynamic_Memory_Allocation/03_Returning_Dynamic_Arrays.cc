#include<iostream>
using namespace std;

// Incase Of Static Array
// int *fun() {
//     int a[] = {1, 2, 3, 4, 5};
//     cout << a << endl;
//     cout << a[0] << endl;
//     // We Should Never Return Address Of A Local Variable 
//     return a;
// }

// Returning Dynamic Array
int *fun() {
    int *a = new int[5];
    a[0] = 11;
    a[1] = 2;
    cout << a << endl;
    cout << a[0] << endl;
    return a;
}

int main() {
    int *b = fun();
    cout << b << endl;
    cout << b[0] << endl;

    // Let Us Clear The Array 'a' By Delete 'b'
    delete [] b;
    
    return 0;
}