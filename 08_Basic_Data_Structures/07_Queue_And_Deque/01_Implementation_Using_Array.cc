#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int cur_size;
    int max_size;
public:
    Queue(int default_size = 5) {
        arr = new int[default_size];
        cur_size = 0;
        max_size = default_size;
        front = 0;
        rear = max_size - 1;
    }
    bool full() {
        return (cur_size == max_size);
    }
    bool empty() {
        return (cur_size == 0);
    }
    void push(int data) {
        if(!full()) {
            rear = (rear + 1) % max_size;
            arr[rear] = data;
            cur_size++;
        }
    }
    void pop() {
        if(!empty()) {
            front = (front + 1) % max_size;
            cur_size--;
        }
    }
    int frontElement() {
        return arr[front];
    }
    ~Queue() {
        if(arr != NULL) {
            delete [] arr;
            arr = NULL;
        }
    }
};

int main() {
    Queue q;
    for(int i = 1; i <= 6; i++) {
        q.push(i);
    }
    q.pop();
    q.pop();
    q.push(7);
    while(!q.empty()) {
        cout << q.frontElement() << " ";
        q.pop();
    }
    return 0;
}