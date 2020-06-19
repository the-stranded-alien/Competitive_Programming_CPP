#include<iostream>
#include<list>
using namespace std;

// List -> Doubly Linked List
// Useful When Insert And Delete From Front & Middle

// Some Useful Methods
// push_back
// push_front
// pop_back
// pop_front
// insert
// erase(idx)
// remove(num)

int main() {

    list<int> l;

    // Init
    list<int> l1{1,2,3,10,8,5};
    // Different Datatype
    list<string> l2{"apple", "guava", "mango", "banana"};
    l2.push_back("pineapple");

    // Iterate Over The List And Print The Data
    for (string s:l2){
        cout << s << "-->";
    }
    cout << endl;

    // Sorting In List 
    l2.sort();
    for (string s:l2){
        cout << s << "-->";
    }
    cout << endl;

    // Reversing The List
    l2.reverse();
    for (string s:l2){
        cout << s << "-->";
    }
    cout << endl;

    // Pop_Front
    cout << l2.front() << endl;
    l2.pop_front();
    for (string s:l2){
        cout << s << "-->";
    }
    cout << endl;

    // Add To Front Of The List
    l2.push_front("kiwi");
    for (string s:l2){
        cout << s << "-->";
    }
    cout << endl;

    // Pop_Back
    cout << l2.back() << endl;
    l2.pop_back();
    for (string s:l2){
        cout << s << "-->";
    }
    cout << endl;

    // Iterating Over List Using Iterators
    for(auto it=l2.begin(); it!=l2.end(); it++){
        cout << (*it) << " -> ";
    }
    cout << endl;

    return 0;
}