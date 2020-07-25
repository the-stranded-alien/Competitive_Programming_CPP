#include<iostream>
#include<climits>
#include<set>
using namespace std;

// Unique Elements And Elements Are Ordered !!

// Uses Red-Black Tree or BST
// O(log N) Time 
// You Can't Update Any Element

int main() {

    int arr[] = {10,20,11,9,8,11,10};
    int n = sizeof(arr)/sizeof(int);

    set<int> s;
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }

    // Iterate Over Set
    for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
        cout << (*it) << ", "; 
    }
    cout << endl;

    // Erase An Element By Value
    s.erase(10);
    for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
        cout << (*it) << ", "; 
    }
    cout << endl;

    // Erase An Element Using Iterator
    auto it = s.find(11);
    s.erase(it);
    for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
        cout << (*it) << ", "; 
    }
    cout << endl;

    // Using Pair With Set
    set<pair<int, int> > st;
    st.insert(make_pair(10, 1));
    st.insert(make_pair(10, 5));
    st.insert(make_pair(20, 1));
    st.insert(make_pair(20, 100));
    st.insert(make_pair(5, 1));
    st.insert(make_pair(5, 3));

    st.erase(st.find(make_pair(5, 3)));
    st.insert(make_pair(5, 4));
    for(auto p : st) {
        cout << p.first << " " << p.second << endl;
    }

    auto itr = st.lower_bound(make_pair(20, 1));
    cout << itr->first << ", " << itr->second << endl;

    auto itr2 = st.upper_bound(make_pair(10, INT_MAX));
    cout << itr2->first << ", " << itr2->second << endl;
    return 0;
}