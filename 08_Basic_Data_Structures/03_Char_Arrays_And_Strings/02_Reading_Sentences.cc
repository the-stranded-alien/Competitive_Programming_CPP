#include<iostream>
using namespace std;

// cin.get() reads a single character
void readline(char a[], int maxLen, char delim = '\n') {
    int i = 0;
    char ch = cin.get();
    while(ch != delim) {
        a[i++] = ch;
        if(i == maxLen - 1) break;
        ch = cin.get();
    }
    a[i] = '\0';
    return;
}

int main() {
    char arr[1000];
    readline(arr, 1000);
    cout << arr << endl;
    char arr2[1000];
    cin.getline(arr2, 1000, '$');
    cout << arr2 << endl;
    return 0;
}