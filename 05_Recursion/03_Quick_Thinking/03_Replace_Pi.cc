#include<iostream>
using namespace std;

void replacePi(char a[], int i) {
    // Base Case
    if(a[i] == '\0' or a[i + 1] == '\0') return;
    // Recursive Case
    // Look For 'Pi' For Current Location
    if(a[i] == 'p' && a[i + 1] == 'i') {
        // Shifting + Replacement With "3.14"
        int j = i + 2;
        // Take 'j' To The End Of The Array
        while(a[j] != '\0') j++;
        // Shifting (From Right To Left)
        while(j >= i + 2) {
            a[j + 2] = a[j];
            j--;
        }
        // Replacement + Recursive Call For Remaining Part
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        replacePi(a, i + 4);
    }
    else {
        // Go To The Next Position
        replacePi(a, i + 1);
    }
    return;
}

int main() {
    char a[1000];
    cin >> a;
    replacePi(a, 0);
    cout << a << endl;
    return 0;
}