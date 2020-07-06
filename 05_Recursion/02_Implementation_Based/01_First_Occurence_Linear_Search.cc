#include<iostream>
using namespace std;

int firstOccurence(int *a, int n, int key) {
    // Base Case
    if(n == 0) return -1;
    // Recursive Case
    if(a[0] == key) return 0;
    int i = firstOccurence(a + 1, n - 1, key);
    // If The Next Function Call Returns -1 Then Return -1 !!
    if(i == -1) return -1;
    return (i + 1);
}

// Linear Search In Different Style.
// Converted Iterative Approach To Recursive Code
int linearSearch(int *a, int i, int n, int key) {
    // Base Case
    if(i == n) return -1;
    // Recursive Case
    if(a[i] == key) return i;
    return linearSearch(a, i + 1, n, key);
}

int main() {
    int arr[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
    int key = 7;
    int n = (sizeof(arr) / sizeof(int));
    cout << firstOccurence(arr, n, key) << endl;
    cout << linearSearch(arr, 0, n, key) << endl;
    return 0;
}