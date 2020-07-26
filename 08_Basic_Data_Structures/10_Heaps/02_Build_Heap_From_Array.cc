#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v) {
    for(int x : v) cout << x << " ";
    cout << endl;
}

// Build Heap - Top Down Approach, O(N x log N) Time & Inplace.
void buildHeap(vector<int> &v) {
    for(int i = 2; i < v.size(); i++) {
        int idx = i;
        int parent = (i / 2);
        while(idx > 1 && (v[idx] > v[parent])) {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = (parent / 2);
        }
    }
    return;
}

// Build Heap Optimised Approach -> Bottom Up Approach, O(N) Time & Inplace.
void heapify(vector<int> &v, int idx) {
    int left = 2 * idx;
    int right = (2 * idx) + 1;
    int min_idx = idx;
    int last = v.size() - 1;
    // Compare With Both Right & Left Children
    if(left <= last && (v[left] > v[idx])) min_idx = left;
    if(right <= last && (v[right] > v[min_idx])) min_idx = right;
    // Swap With The Smaller Children And Recursively Call The Function To Fix The Entire Heap
    if(min_idx != idx) {
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx);
    }
    return; 
}
void buildHeapOptimised(vector<int> &v) {
    for(int i = ((v.size() - 1) / 2); i >= 1; i--) heapify(v, i);
    return;
}

int main() {
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    print(v);
    // buildHeap(v);
    // print(v);
    buildHeapOptimised(v);
    print(v);
    return 0;
}