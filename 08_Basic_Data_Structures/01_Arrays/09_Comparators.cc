#include<iostream>
using namespace std;

bool compare(int a, int b) {
    return (a > b); // Ascending
}

// Passing Function As Parameter To Another Function
void bubble_sort(int a[], int n, bool (&cmp)(int a, int b)) {
    // (n - 1) Iterations, (n - 1) Large Elements To The End.
    for(int itr = 1; itr <= (n - 1); itr++) {
        for(int j = 0; j <= (n - itr - 1); j++) {
            if(cmp(a[j], a[j + 1])) swap(a[j], a[j + 1]);
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; i++) cin >> a[i];
    bubble_sort(a, n, compare);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}