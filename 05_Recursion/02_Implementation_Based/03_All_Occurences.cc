#include<iostream>
using namespace std;

// Store The Occurences As Well
int storeOccur(int *a, int i, int n, int key, int *out, int j) {
    // Base Case
    if(i == n) return j;
    // Recursive Case
    if(a[i] == key) {
        out[j] = i;
        // Increment 'j' To Accomodate Current Occurence
        return storeOccur(a, i + 1, n, key, out, j + 1);
    }
    // 'j' Remains Unchanged
    return storeOccur(a, i + 1, n, key, out, j);

}

// Print Occurences
void allOccur(int *a, int i, int n, int key) {
    if(i == n) return;
    if(a[i] == key) cout << i << " ";
    allOccur(a, i + 1, n, key);
    return;
}

int main() {
    int arr[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
    int key = 7;
    int n = (sizeof(arr) / sizeof(int));
    allOccur(arr, 0, n, key);
    cout << endl;
    int output[100];
    int cnt = storeOccur(arr, 0, n, key, output, 0);
    cout << "Count : " << cnt << endl;
    for(int k = 0; k < cnt; k++) {
        cout << output[k] << " ";
    }
    return 0;
}