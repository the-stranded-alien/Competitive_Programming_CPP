#include<iostream>
using namespace std;

// Selection Sort
void selection_sort(int a[], int n) {
    for(int i = 0; i < (n - 1); i++) {
        // Find Out The Smallest Element Index In The Unsorted Part
        int min_index = i;
        for(int j = i; j <= (n - 1); j++) {
            if(a[j] < a[min_index]) min_index = j; // Updates Min Index
        }
        // After The Loop Swap Finally
        swap(a[i], a[min_index]);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; i++) cin >> a[i];
    selection_sort(a, n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}