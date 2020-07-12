#include<iostream>
using namespace std;

// Bubble Sort
void bubble_sort(int a[], int n) {
    // (n - 1) Iterations, (n - 1) Large Elements To The End.
    for(int itr = 1; itr <= (n - 1); itr++) {
        for(int j = 0; j <= (n - itr - 1); j++) {
            if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; i++) cin >> a[i];
    bubble_sort(a, n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}