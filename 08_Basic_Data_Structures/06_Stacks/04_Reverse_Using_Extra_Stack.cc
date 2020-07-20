#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n) {
    for(int i = 0; i < n; i++) {
        s2.push(s1.top());
        s1.pop();
    }
    return;
}

void reverseStack(stack<int> &s1) {
    stack<int> s2; // Helper Stack
    int n = s1.size();
    for(int i = 0; i < n; i++) {
        // Pick The Element At Top & Insert It At The Bottom
        int x = s1.top();
        s1.pop();
        // Transfer (n - i - 1) Elements From Stack 's1' Into Stack 's2'
        transfer(s1, s2, (n - i - 1));
        // Insert The Element 'x' In 's1'
        s1.push(x);
        // Transfer Again (n - i - 1) Elements From 's2' to 's1' 
        transfer(s2, s1, (n - i - 1));
    }
    return;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverseStack(s);
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}