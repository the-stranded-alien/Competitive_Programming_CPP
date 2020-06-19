#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> d{1,2,3,10,14};
    // push_back O(1) for Most of the Times
    d.push_back(16);
    for(int x : d) cout << x << ", ";
    cout << endl;

    // pop_back - Removes The Last Element O(1)
    d.pop_back();
    for(int x : d) cout << x << ", ";
    cout << endl;

    // Insert Some Elements in the Middle
    // insert() O(N)
    d.insert(d.begin()+3, 100);
    for(int x : d) cout << x << ", ";
    cout << endl;
    d.insert(d.begin()+3, 4, 110);
    for(int x : d) cout << x << ", ";
    cout << endl;

    // Erase Some Elements in the Middle
    d.erase(d.begin()+3);
    for(int x : d) cout << x << ", ";
    cout << endl;
    d.erase(d.begin()+2, d.begin()+5);
    for(int x : d) cout << x << ", ";
    cout << endl;

    // Size
    cout << d.size() << endl;

    // Capacity
    cout << d.capacity() << endl;

    // We Avoid The Shrink
    // If the size is increasing then more
    // memory will be allocated
    d.resize(8);
    cout << d.capacity() << endl;

    // Remove All The Elements of Vector
    // Doesn't Delete The Memory Occupied by The Vector
    d.clear();
    cout << d.size() << endl;
    cout << d.capacity() << endl;

    // Empty
    if(d.empty()) cout << "This Is An Empty Vector\n";

    d.push_back(10);
    d.push_back(11);
    d.push_back(12);

    // front() -> Gives The Front Most Element
    cout << d.front() << endl;

    // back() -> Gives The Last Element
    cout << d.back() << endl;

    // Reserve
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int no;
        cin >> no;
        v.push_back(no);
        cout << "Changing Capacity : " << v.capacity() << endl; 
    }
    cout << "Capacity : " << v.capacity() << endl; 
    for(int x : v) cout << x << ", ";
    cout << endl;

    // To Avoid Doubling, We Will Use Reserve Function
    int m;
    cin >> m;
    vector<int> v2;
    v2.reserve(1000);
    for(int i=0;i<m;i++){
        int no;
        cin >> no;
        v2.push_back(no);
        cout << "Changing Capacity : " << v2.capacity() << endl; 
    }
    cout << "Capacity : " << v2.capacity() << endl; 
    for(int x : v2) cout << x << ", ";
    cout << endl;


    return 0;
}