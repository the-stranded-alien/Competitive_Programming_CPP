#include<iostream>
using namespace std;

int lastOccurence(int *a, int n, int key) {
    // Base Case
    if(n == 0) return -1;
    // Recursive Case
    int idx = lastOccurence(a + 1, n - 1, key);
    if(idx == -1) {
        if(a[0] == key) return 0;
        else return -1;
    }
    // Otherwise If 'idx' Returned By Subproblem Is Not -1.
    return (idx + 1);
}

int main() {
    int arr[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
    int key = 7;
    int n = (sizeof(arr) / sizeof(int));
    cout << lastOccurence(arr, n, key) << endl;
    return 0;
}