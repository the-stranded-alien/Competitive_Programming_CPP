#include<iostream>
using namespace std;

void wave_sort(int a[], int n) {
    for(int i = 0; i < n; i += 2) {
        // Previous Element
        if(i != 0 and a[i] < a[i - 1]) swap(a[i], a[i - 1]);
        // Next Element
        if(i != (n - 1) and a[i] < a[i + 1]) swap(a[i], a[i + 1]);
    }
    return;
}

int main() {
    int a[] = {1, 3, 4, 2, 7, 8};
    int n = sizeof(a) / sizeof(int);
    wave_sort(a, n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}