#include<iostream>
using namespace std;

int main() {
    char a[][10] = {{'a','b','\0'},{'d','e','f','\0'}};
    cout << a[0] << endl;
    cout << a[1] << endl;

    char b[][10] = {"ab", "def", "ghi", "hello"};
    cout << b[0] << endl;
    cout << b[1] << endl;
    cout << b[2] << endl;
    cout << b[3] << endl;

    char c[10][10];
    c[0][0] = 'A';

    // Read A List Of Strings And Store Them In A 2D Character Array
    int n;
    cin >> n;
    char chArr[100][1000];
    cin.get(); // Consume Extra 'Enter'
    for(int i = 0; i < n; i++) {
        cin.getline(chArr[i], 1000);
    }
    // Print All Strings
    for(int i = 0; i < n; i++) cout << chArr[i] << endl;

    return 0;
}