#include<iostream>
#include<list>
#include<cstring>
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

    list<string> l3{"kiwi", "mango", "guava", "banana"};
    l3.push_back("orange");
    l3.push_back("lemon");
    l3.push_back("guava");

    for(string s:l3){
        cout << s << "-->";
    }
    cout << endl;

    // Remove Element By Value
    string f1;
    cin >> f1;
    l3.remove(f1);
    for(string s:l3){
        cout << s << "-->";
    }
    cout << endl;

    // Erase One Or More Elements By Index
    // auto it = l.begin() + 3; 
    // Direct Access Don't Work In Lists Unlike Vectors
    auto it = l3.begin();
    it++;
    it++;
    l3.erase(it);
    for(string s:l3){
        cout << s << "-->";
    }
    cout << endl;

    // Insert Elements In The List
    it = l3.begin();
    it++;
    l3.insert(it, "peach");
    for(string s:l3){
        cout << s << "-->";
    }
    cout << endl;
    return 0;
}