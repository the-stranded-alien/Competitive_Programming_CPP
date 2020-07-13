#include<iostream>
using namespace std;

int main() {
    int x = 10;
    cout << &x << endl;
    float y = 10.5;
    cout << &y << endl;
    // Doesn't Work For Character Variables
    char ch = 'A';
    cout << &ch << endl;
    // Explicit Typecasting From char* to void*
    cout << (void *) &ch << endl;
    return 0;
}