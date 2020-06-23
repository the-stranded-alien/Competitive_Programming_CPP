#include<iostream>
#include<cstring>
using namespace std;

// Subsequences/Subsets of a String

void filterChars(int n, char a[]) {
    int j = 0;
    while(n > 0){
        int last_bit = (n & 1);
        if(last_bit){
            cout << a[j];
        }
        j++;
        n = (n >> 1);
    }
    cout << endl;
}

void printSubsets(char a[]) {
    int n = strlen(a);
    for(int i = 0; i < (1 << n); i++) {
        filterChars(i, a);
    }
    return;
}

int main() {
    char str[100];
    cout << "Enter String : ";
    cin >> str;
    printSubsets(str);
    return 0;
}