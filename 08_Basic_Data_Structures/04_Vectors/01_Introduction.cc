#include<iostream>
#include<vector>
using namespace std;

int main() {
    // Create & Initialise a Vector
    vector<int> vec_a;
    vector<int> vec_b(5, 10); // Five Integers With Value 10.
    vector<int> vec_c(10, 0); // Init A Vectors Of Zeros (n, 0);
    vector<int> vec_d(vec_b.begin(), vec_b.end());
    vector<int> vec_e{1, 2, 3, 10, 14};

    // How To Iterate Over The Vector
    for(int i = 0; i < vec_c.size(); i++) cout << vec_c[i] << " ";
    cout << endl;
    for(auto it = vec_b.begin(); it != vec_b.end(); it++) cout << (*it) << " ";
    cout << endl;
    for(vector<int>::iterator itr = vec_b.begin(); itr != vec_b.end(); itr++) cout << (*itr) << " ";
    cout << endl;
    for(int x : vec_e) cout << x << " ";
    cout << endl;
    
    // More Functions 
    // Take Input From User
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int no;
        cin >> no;
        v.push_back(no); // Push_Back : Adds An Element To The End Of The Vector
    }
    for(int x : v) cout << x << " ";
    cout << endl;

    // Understand At Memory Level, What Are Differences In The Two (vec_e & v) :
    cout << "Information About Vector 'v' : \n";
    cout << v.size() << endl;
    cout << v.capacity() << endl; // Size Of Underlying Array
    // Maximum Number Of Elements A Vector Can Hold In The Worst Case Acc. To Available Memory
    cout << v.max_size() << endl; 
    cout << "Information About Vector 'vec_e' : \n";
    cout << vec_e.size() << endl;
    cout << vec_e.capacity() << endl;
    cout << vec_e.max_size() << endl; 
    return 0;
}