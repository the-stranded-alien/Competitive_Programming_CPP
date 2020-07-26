#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v) {
    for(int x = 1; x < v.size(); x++) cout << v[x] << " ";
    cout << endl;
    return;
}

void heapify(vector<int> &v, int idx, int size) {
    int left = 2 * idx;
    int right = (2 * idx) + 1;
    int min_idx = idx;
    int last = size - 1;
    // Compare With Both Right & Left Children
    if(left <= last && (v[left] > v[idx])) min_idx = left;
    if(right <= last && (v[right] > v[min_idx])) min_idx = right;
    // Swap With The Smaller Children And Recursively Call The Function To Fix The Entire Heap
    if(min_idx != idx) {
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx, size);
    }
    return; 
}

void buildHeap(vector<int> &v) {
    for(int i = ((v.size() - 1) / 2); i >= 1; i--) heapify(v, i, v.size());
    return;
}

void heapsort(vector<int> &arr) {
    buildHeap(arr);
    int n = arr.size();
    // Remove (n - 1) Elements From The Heap
    while(n > 1) {
        swap(arr[1], arr[n - 1]);
        // Remove The Element From The Heap But Not From The Array
        n--;
        heapify(arr, 1, n);
    }
    return;
}

int main() {
    vector<int> vec;
    vec.push_back(-1);
    int n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }
    heapsort(vec);
    print(vec);
    return 0;

}