#include<iostream>
#include<deque>
using namespace std;

// ARRAYSUB - subarrays (SPOJ)
// Given an array and an integer k, find the maximum for each
// and every contiguous subarray of size k.
// Deque (With Sliding Window Technique)

int main() {
    int n;
    int a[100005];
    int k;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> k;
    // Processing First 'k' Elements Separately
    deque<int> Q(k); // Atmost Size Will Be 'k'
    int i;
    for(i = 0; i < k; i++) {
        while(!Q.empty() && a[i] > a[Q.back()]) Q.pop_back();
        Q.push_back(i);
    }
    // Processing The Remaining Elements
    for(; i < n; i++) {
        cout << a[Q.front()] << " ";
        // 1. Remove The Elements Which Are Not The Part Of The Window
        while((!Q.empty()) && (Q.front() <= (i - k))) Q.pop_front();
        // 2. Remove The Elements Which Are Not Useful And Are In Window
        while((!Q.empty()) && (a[i] >= a[Q.back()])) Q.pop_back();
        // 3. Add The New Elements (Expansion)
        Q.push_back(i);
    }
    // Print Last Element
    cout << a[Q.front()] << endl;
    return 0;
}