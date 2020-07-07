#include<iostream>
using namespace std;

int partition(int *a, int s, int e) {
    // Inplace (Can't Take Extra Space)
    int i = s - 1;
    int j = s;
    int pivot = a[e];
    for(; j <= e - 1;) {
        if(a[j] <= pivot) {
            // Merge The Smaller Element In The Region 1
            i = i + 1;
            swap(a[i], a[j]);
        }
        // Expand The Larger Region
        j = j + 1;
    }
    // Place The Pivot Element In The Correct Index
    swap(a[i + 1], a[e]);
    return (i + 1);
}

void quickSort(int *arr, int s, int e) {
    // Base Case
    if(s >= e) return;
    // Recursive Case
    int p = partition(arr, s, e);
    // Left Part
    quickSort(arr, s, p - 1);
    // Right Part
    quickSort(arr, p + 1, e);
    return;
}

int main() {
    int arr[] = {2, 7, 8, 6, 1, 5, 4};
    int n = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}