#include<iostream>
#include<queue>
using namespace std;

// Priority Queue (Heap)
// 1. push -> O(log N)
// 2. pop  -> O(log N)
// 3. top  -> O(1)
// 4. empty

int main() {
    // Max Heap / Max Priority Queue
    priority_queue<int> pq_max;
    int n;
    cin >> n;
    int no;
    for(int i = 0; i < n; i++) {
        cin >> no;
        pq_max.push(no);
    }
    // Remove The Elements From The Heap
    while(!pq_max.empty()) {
        cout << pq_max.top() << " ";
        pq_max.pop();
    }
    cout << endl;
    // Min Heap / Min Priority Queue
    priority_queue<int, vector<int>, greater<int> > pq_min;
    for(int i = 0; i < n; i++) {
        cin >> no;
        pq_min.push(no);
    }
    // Remove The Elements From The Heap
    while(!pq_min.empty()) {
        cout << pq_min.top() << " ";
        pq_min.pop();
    }

    return 0;
}