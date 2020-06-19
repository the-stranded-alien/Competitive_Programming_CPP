#include<iostream>
#include<queue>
using namespace std;

// Build Using "Heap"

// Complete Binary Tree With Heap Property

// Push O(log N)
// Pop O(log N)
// Top O(1)
// Empty

int main() {

    // Max Priority Queue
    priority_queue<int> pq_max;
    for(int i=1; i<=5; i++){
        int no;
        cin >> no;
        pq_max.push(no);
    }

    // Remove The Elements From The Heap
    while(!pq_max.empty()) {
        cout << pq_max.top() << " ";
        pq_max.pop();
    }
    cout << endl;
    
    // Min Priority Queue
    priority_queue<int, vector<int>, greater<int> > pq_min;
    for(int i=1; i<=5; i++){
        int no;
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