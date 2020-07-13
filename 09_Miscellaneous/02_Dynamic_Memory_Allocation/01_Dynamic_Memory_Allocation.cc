#include<iostream>
using namespace std;

int main() {
    // Static Memory Allocation 
    // Allocation + Deallocation Is Done By The Compiler
    int b[100];
    cout << sizeof(b) << endl;
    cout << b << endl; // Value Comes From Symbol Table
    // Here, 'b' Can Not Be Overwritten, 'b' Is A Part Of Read Only Memory.

    // Dynamic Memory Allocation
    int n;
    cin >> n;
    int *a = new int[n]; // Allocation
    cout << sizeof(a) << endl;
    cout << a << endl; // Value Comes From Variable 'a' That Is 
    // Created Inside The Static Memory, Can Be Overwritten.
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cout << a[i] << endl;
    }
    delete [] a; // Deallocation

    // Init With Some Value , Say 0
    int *c = new int[100]{0};
    
    return 0;
}