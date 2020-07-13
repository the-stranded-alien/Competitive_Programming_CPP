#include<iostream>
using namespace std;

void increment(int *aptr) {
    *aptr = *aptr + 1;
    cout << "Inside Function : " << *(aptr) << endl;
    return; 
}

int main() {
    int a = 10;
    increment(&a); 
    cout << "Inside Main : " << a << endl;
    return 0;
}