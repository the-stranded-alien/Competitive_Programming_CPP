#include<iostream>
#include<vector>
using namespace std;

// Vector : Container

// Vectors Are Dynamic Arrays That
// Can Grow and Shrink in Size.

int main() {

    // Different Methods To Create And Initialise A Vector
    vector<int> a;
    // 5 Integers With Value 10
    vector<int> b(5, 10);
    // Initialize A Vector of Zeros (n,0)
    vector<int> bo(10, 0);
    // Copy Some Other Vector
    vector<int> c(b.begin(),b.end());
    // Initialize With Some Values
    vector<int> d{1,2,3,10,14};

    // Iterate Over The Vector
    for(int i=0; i<c.size(); i++){
        cout << c[i] << ", ";
    }
    cout << endl;

    for(auto it = b.begin(); it!=b.end(); it++) {
        cout << (*it) << ", ";
    }
    cout << endl;

    for(vector<int>::iterator itr = d.begin(); itr!=d.end(); itr++){
        cout << (*itr) << ", ";
    }
    cout << endl;

    for(int x : d){
        cout << x << ", ";
    }
    cout << endl;

    // Taking User Input In Vector
    vector<int> v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int no;
        cin >> no;
        // push_back() -> Adds An Element
        // To The Back End Of The Vector.
        v.push_back(no);
    }
    // Doubling Of Memory Is A Expensive Operation

    for(int x : v){
        cout << x << ", ";
    }
    cout << endl;

    // Understand At Memory Level, What
    // Are The Differences In The Two:
    // Vectors v and d

    cout << v.size() << endl; // => 5 (On Entering 5 Elements)
    // capacity() -> Size of Underlying Array
    cout << v.capacity() << endl; // => 8
    // max_size() -> Maximum number of elements a vector 
    // can hold in the worst case according to available
    // memory in the system
    cout << v.max_size() << endl;

    cout << d.size() << endl; // => 5
    cout << d.capacity() << endl; // => 5
    cout << d.max_size() << endl;

    return 0;
}