#include<iostream>
#include<vector>
using namespace std;

int main() {
    // Create & Initialise The Vector
    vector<int> d{1, 2, 3, 10, 14};
    
    // push_back() : O(1) Mostly
    d.push_back(16);
    for(int x : d) cout << x << " ";
    cout << endl;
    
    // pop_back() - Removes The Last Element O(1)
    d.pop_back();
    for(int x : d) cout << x << " ";
    cout << endl;

    // Insert Some Elements In The Middle : O(N)
    d.insert(d.begin() + 3, 4, 100); // (Index, No. of Times, Value)
    for(int x : d) cout << x << " ";
    cout << endl;

    // Erase Some Elements In The Middle
    d.erase(d.begin() + 2);
    d.erase(d.begin() + 2, d.begin() + 5); // Erasing In Range
    for(int x : d) cout << x << " ";
    cout << endl;

    // Size
    cout << d.size() << endl;

    // Underlying Capacity
    cout << d.capacity() << endl;

    // We Avoid Shrinking
    // Resize
    d.resize(8);
    cout << d.capacity() << endl;
    // If Size Is Increasing Then More Memory Will Be Allocated
    d.resize(18);
    cout << d.capacity() << endl;
    cout << d.size() << endl;

    // Remove All Elements, Doesn't Delete The Memory Occupied By The Array
    d.clear();
    cout << d.size() << endl;

    // Empty
    if(d.empty()) cout << "Empty Vector" << endl;

    d.push_back(10);
    d.push_back(11);
    d.push_back(12);
    d.push_back(13);

    // Front Element
    cout << d.front() << endl;

    // Last Element
    cout << d.back() << endl;

    // Reserve
    int n;
    cin >> n;
    vector<int> v;
    v.reserve(1000);
    for(int i = 0; i < n; i++) {
        int no;
        cin >> no;
        v.push_back(no);
        cout << "Changing Capacity : " << v.capacity() << endl;
    }
    cout << "Capacity : " << v.capacity() << endl;
    for(int x : v) cout << x << " ";
    cout << endl;
    // Should Use Reserve !!

    return 0;
}