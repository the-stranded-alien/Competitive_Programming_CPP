#include<iostream>
#include<queue>
using namespace std;

// Implement a Stack Using 2 Queues
template<typename T>
class Stack {
    queue<T> q1;
    queue<T> q2;
public:
    void push(T x) {
        q1.push(x);
    }
    int size() {
        return (q1.size() + q2.size());
    }
    bool empty() {
        return (size() == 0);
    }
    void pop() {
        // Remove The Last Added Element From 'q1'
        // Have To Move First 'n - 1' Elements In 'q2'
        // Interchange The Names Of 'q1' & 'q2'
        if(q1.empty()) return;
        while(q1.size() > 1) {
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }
        // Remove The Last Element
        q1.pop();
        // Swap The Names Of 'q1' & 'q2'
        swap(q1, q2);
    }
    T top() {
        while(q1.size() > 1) {
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }
        // One Element In 'q1'
        T element = q1.front();
        q1.pop();
        q2.push(element);
        swap(q1, q2);
        return element;
    }
};

int main() {
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}