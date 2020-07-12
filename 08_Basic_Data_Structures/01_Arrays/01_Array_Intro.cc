#include<iostream>
using namespace std;

int main() {
    // Init. An Array
    int a[10] = {1,2,3};
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    // Taking Input Into Array
    for(int i = 0; i < 5; i++) cin >> a[i];
    for(int i = 0; i < 10; i++) cout << a[i] << " ";
    // Size
    cout << sizeof(a) << endl;
    // Number Of Elements
    cout << (sizeof(a) / sizeof(int)) << endl;
    return 0;
}