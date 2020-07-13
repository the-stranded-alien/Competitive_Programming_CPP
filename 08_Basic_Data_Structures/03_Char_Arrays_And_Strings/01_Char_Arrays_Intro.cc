#include<iostream>
using namespace std;

int main() {
    int b[] = {1,2,3};
    cout << b << endl; // Address (Default)

    char a[] = {'a','b','c','d','e','\0'};
    cout << a << endl; // Contents (Specially Overloaded Operator)

    // Input & Output
    char s[10];
    cin >> s;
    cout << s;

    char s1[] = {'H','e','l','l','o'}; // Ends With Some Garbage
    char s2[] = "Hello";

    cout << s1 << " " << sizeof(s1) << endl;
    cout << s2 << " " << sizeof(s2) << endl;

    return 0;
}