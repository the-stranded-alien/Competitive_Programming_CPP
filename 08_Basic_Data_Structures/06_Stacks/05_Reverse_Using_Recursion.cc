#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x) {
    // Base Case
    if(s.empty()) {
        s.push(x);
        return;
    }
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
    return;
}

void reverseStackRec(stack<int> &s) {
    // Base Case
    if(s.empty()) return;
    // Recursive Case
    // Pop Out The Top Element And Insert It At The Bottom Of 'Reversed Smaller Stack'
    int x = s.top();
    s.pop();
    // Recursive Reverse The Smaller Stack
    reverseStackRec(s);
    insertAtBottom(s, x);
    return;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverseStackRec(s);
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}