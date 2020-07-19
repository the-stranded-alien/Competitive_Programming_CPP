#include<iostream>
#include<forward_list>
using namespace std;

// Forward_List => Singly Linked List
int main() {
    forward_list<int> singlyLL;
    singlyLL.push_front(10);
    singlyLL.push_front(20);
    singlyLL.push_front(30);
    singlyLL.push_front(40);
    singlyLL.push_front(50);
    for(auto x : singlyLL) cout << x << " ";
    cout << endl;
    return 0;
}