#include<iostream>
using namespace std;

// Bubble Sort Recursively
void bubble_sort(int a[], int n) {
    // Base Case
    if(n == 1) return;
    // Recursive Case
    // After You Have Moved The Largest Element In The Current
    // Part To The End Of The Array By Pairwise Swapping.
    for(int j = 0; j < (n - 1); j++) {
        if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    }
    bubble_sort(a, n - 1);
    return;
}

void bubble_sort_recursive(int a[], int j, int n) {
    // Base Case
    if(n == 1) return;
    if(j == n - 1) {
        // Single Pass Of The Current Array Has Been Done
        return bubble_sort_recursive(a, 0, n - 1);
    }
    // Recursive Case
    if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    bubble_sort_recursive(a, j + 1, n);
    return;
}

int main() {
    int a[] = {5, 4, 3, 1, 2};
    int n = 5;
    bubble_sort_recursive(a, 0, n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}