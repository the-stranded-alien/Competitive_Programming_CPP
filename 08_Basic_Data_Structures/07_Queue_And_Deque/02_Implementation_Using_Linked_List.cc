#include<iostream>
#include<list>
using namespace std;

class Queue {
    int cur_size;
    list<int> l;
public:
    Queue() {
        cur_size = 0;
    }
    bool isEmpty() {
        return (cur_size == 0);
    }
    void push(int data) {
        l.push_back(data);
        cur_size += 1;
    }
    void pop() {
        if(!isEmpty()) {
            cur_size -= 1;
            l.pop_front();        
        }
    }
    int front() {
        return (l.front());
    }
};

int main() {
    Queue q;
    for(int i = 1; i <= 10; i++) {
        q.push(i);
    }
    while(!q.isEmpty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}