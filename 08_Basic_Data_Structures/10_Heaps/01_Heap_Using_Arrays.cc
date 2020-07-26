#include<iostream>
#include<vector>
using namespace std;

class Heap {
private:
    vector<int> v;
    bool minHeap;
    bool compare(int a, int b) {
        if(minHeap) return (a < b);
        else return (a > b);
    }
    void heapify(int idx) {
        int left = 2 * idx;
        int right = (2 * idx) + 1;
        int min_idx = idx;
        int last = v.size() - 1;
        // Compare With Both Right & Left Children
        if(left <= last && compare(v[left], v[idx])) min_idx = left;
        if(right <= last && compare(v[right], v[min_idx])) min_idx = right;
        // Swap With The Smaller Children And Recursively Call The Function To Fix The Entire Heap
        if(min_idx != idx) {
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
        return; 
    }
public:
    Heap(int default_size = 10, bool type = true) {
        v.reserve(default_size);
        v.push_back(-1); // Blocking Index - 0
        minHeap = type; // Min_Heap -> true / Max_Heap -> false
    }
    void push(int d) {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx / 2;
        // Keep Pushing To The Top Till You Reach A Root Node Or Stop Midway
        // Because Current Element Is Already Greater / Lesser Than Parent. 
        while(idx > 1 && compare(v[idx], v[parent])) {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
    int top() {
        return v[1];
    }
    void pop() {
        // Swap First And Last Element
        int last_idx = v.size() - 1;
        swap(v[1], v[last_idx]);
        // Remove The Last Element
        v.pop_back();
        // Heapify
        heapify(1);
        return;
    }
    bool empty() {
        return (v.size() == 1);
    }
};

int main() {
    // Give Some Initial Size & Type (Min / Max Heap)
    Heap h_min;
    Heap h_max(10, false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int no;
        cin >> no;
        h_min.push(no);
        h_max.push(no);
    }
    cout << "Min Heap : ";
    while(!h_min.empty()) {
        cout << h_min.top() << " ";
        h_min.pop();
    }
    cout << "\nMax Heap : ";
    while(!h_max.empty()) {
        cout << h_max.top() << " ";
        h_max.pop();
    }
    return 0;
}
