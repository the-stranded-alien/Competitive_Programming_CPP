#include<iostream>
using namespace std;

// Insertion Sort
void insertion_sort(int a[], int n) {
    for(int i = 1; i <= (n - 1); i++) {
        int e = a[i];
        // Place The Current ELement At 'Right' Position In The Sorted Part
        int j = i - 1;
        while(j >= 0 && a[j] > e) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = e;
    }
    return;
}

int main() {
    int n;
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; i++) cin >> a[i];
    insertion_sort(a, n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}