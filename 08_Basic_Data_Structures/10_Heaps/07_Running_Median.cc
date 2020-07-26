#include<iostream>
#include<queue>
using namespace std;

// Median In A Running Stream Of Integers !

int main() {
    priority_queue<int> leftHeap; // Max Heap
    priority_queue<int, vector<int>, greater<int> > rightHeap; // Min Heap
    int d;
    cin >> d; // First Element
    leftHeap.push(d);
    float median = d;
    cout << "Median : " << median << endl;
    cin >> d; // Second Element
    // Input All Elements
    while(d != -1) {
        if(leftHeap.size() > rightHeap.size()) {
            if(d < median) {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(d);
            }
            else rightHeap.push(d);
            median = ((leftHeap.top() + rightHeap.top()) / 2.0);
        }
        else if(leftHeap.size() == rightHeap.size()) {
            if(d < median) {
                leftHeap.push(d);
                median = leftHeap.top();
            }
            else {
                rightHeap.push(d);
                median = rightHeap.top();
            }
        }
        else {
            if(d > median) {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            else leftHeap.push(d);
            median = ((leftHeap.top() + rightHeap.top()) / 2.0);
        }
        cout << "Median : " << median << endl;
        cin >> d; // Third And Further Elements
    }    
    return 0;
}