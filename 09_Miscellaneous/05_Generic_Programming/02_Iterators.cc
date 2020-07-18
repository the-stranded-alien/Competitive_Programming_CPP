#include<iostream>
#include<list>
#include<vector>
using namespace std;

// Templates + Iterators
template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key) {
    while(start != end) {
        if((*start) == key) return start;
        start++;
    }
    return end;
}

int main() {
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(3);
    int key = 5;
    auto it = search(l.begin(), l.end(), key);
    if(it == l.end()) cout << "Element Not Present\n";
    else cout << (*it) << endl;
    return 0;
}