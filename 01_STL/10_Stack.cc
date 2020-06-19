#include<iostream>
#include<stack>
using namespace std;

// LIFO -> Last In First Out Order Is Followed

// Most Important Methods
// push(d)
// pop()
// top()
// empty()

int main() {

    stack<int> s;

    for(int i=0; i<=5; i++){
        s.push(i);
    }

    // Loop
    while(!s.empty()){
        cout << s.top() << ", ";
        s.pop();
    }
    cout << endl;

    return 0;
}