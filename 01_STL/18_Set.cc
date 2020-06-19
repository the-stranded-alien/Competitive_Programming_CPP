#include<iostream>
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
    cout <<  endl;

    // Erase An Element By Value
    s.erase(10);
    for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
        cout << (*it) << ", "; 
    }
    cout <<  endl;

    // Erase An Element Using Iterator
    auto it = s.find(11);
    s.erase(it);
    for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
        cout << (*it) << ", "; 
    }
    cout <<  endl;

    return 0;
}