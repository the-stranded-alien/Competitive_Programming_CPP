#include<iostream>
#include<map>
#include<cstring>
using namespace std;

// It's Similar To Map, Only Difference
// Is That It Can Contain Elements, Where
// Multiple Keys Can Have Same Value !

// Due To Underlying Self-Balancing BST,
// insert(), find(), erase() Take O(log N) Time !!

int main() {

    multimap<char, string> mm;
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char ch;
        string s;
        cin >> ch >> s;
        mm.insert(make_pair(ch,s));
    }

    // Printing The Entire Map
    for(auto p:mm){
        cout << p.first << " And " << p.second << endl;
    }
    cout << endl;

    // Erase A Particular Key
    auto it = mm.begin();
    mm.erase(it);
    for(auto p:mm){
        cout << p.first << " And " << p.second << endl;
    }
    cout << endl;

    // Iterating Over A Selected Range Using Bounds
    auto it2 = mm.lower_bound('b');
    auto it3 = mm.upper_bound('d');
    for(auto it4=it2; it4!=it3; it4++){
        cout << it4->second << endl;
    }
    cout << endl;

    // Search For Particular Element And Delete It
    auto f = mm.find('c');
    if(f->second=="cat"){
        mm.erase(f);
    }
    for(auto p:mm){
        cout << p.first << " And " << p.second << endl;
    }
    cout << endl;

    return 0;
}