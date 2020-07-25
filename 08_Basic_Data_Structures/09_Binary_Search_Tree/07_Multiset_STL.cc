#include<iostream>
#include<set>
using namespace std;

// Multiset - Can Store Multiple
// Elements That Have Same Elements.

// All Elements Are Stored In A Specific Order
// -> Sorted According To Internal Comparison Object
// Values Once Inserted Can't Be Modified
// Associative Container -> Elements Are Refered By Their
// Value And Not By The Index.
// Underlying Data Structure Is BST.

typedef multiset<int>::iterator Itr;

class person_compare {
public:
    bool operator()(pair<string, int> p1, pair<string, int> p2) {
        return (p1.second < p2.second);
    }
};

int main() {
    
    int arr[] = {10,20,30,20,30,30,30,10,30};
    int n = sizeof(arr)/sizeof(int);
    multiset<int> m(arr,arr+n);

    // Iterate
    for(int x:m){
        cout << x << ", ";
    }
    cout << endl;

    // Erase 
    m.erase(20);
    for(int x:m){
        cout << x << ", ";
    }
    cout << endl;

    // Insert
    m.insert(80);
    for(int x:m){
        cout << x << ", ";
    }
    cout << endl;

    // Count
    cout << m.count(10) << endl;

    // Find 
    auto it = m.find(30);
    cout << (*it) << endl;

    // Get All Elements Which Are Equal To A Value
    pair<Itr, Itr> range = m.equal_range(30);
    for(auto it = range.first; it!=range.second; it++){
        cout << (*it) << " - ";
    }
    cout << endl;

    // Lower (>=) and Upper (>) Bound
    for(auto it=m.lower_bound(10); it!=m.upper_bound(77); it++){
        cout << (*it) << " - ";
    }
    cout << endl;

    // Multiset For Custom Class
    pair<string, int> p1 = make_pair("B", 100);
    pair<string, int> p2 = make_pair("A", 40);
    pair<string, int> p3 = make_pair("C", 120);
    pair<string, int> p4 = make_pair("D", 10);

    multiset<pair<string, int>, person_compare> multi;
    multi.insert(p1);
    multi.insert(p2);
    multi.insert(p3);
    multi.insert(p4);

    for(auto pr : multi) {
        cout << pr.first << " -> " << pr.second << endl;
    }



    return 0;
}