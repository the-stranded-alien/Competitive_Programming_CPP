#include<iostream>
#include<queue>
using namespace std;

// FIFO -- First In First Out Order Is Followed

// Most Important Methods Are -
// Push
// Pop
// Front
// Empty

int main() {
    
    queue<int> q;

    for(int i=1; i<=5; i++) {
        q.push(i);
    }

    while(!q.empty()){
        cout << q.front( ) << " <- ";
        q.pop();
    }

    return 0;
}