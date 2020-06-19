#include<iostream>
#include<map>
#include<string>
using namespace std;

// Maps --> Associative Containers That 
// Stores Mapping Between Key-Value Pairs

// Important Methods
// Insert Key-Value Pair : insert((k,v))
// Query(k) -> find() function
// Delete(k) -> erase() function

// Map Maintains A Self-Balancing BST
// All The Objects Are Ordered According To The Key

int main() {

    map<string, int> m;

    // Insert
    m.insert(make_pair("mango", 100));

    pair<string, int> p;
    p.first = "apple";
    p.second = 120;
    m.insert(p);

    m["banana"] = 20;

    // Search
    string fruit;
    cin >> fruit;

    // auto it = m.find(fruit);
    map<string, int>::iterator it = m.find(fruit);
    if(it!=m.end()){
        cout << "Price Of " << fruit << " Is " << m[fruit] << endl;
    }
    else {
        cout << "Fruit Is Not Present." << endl;
    }

    // Another Way To Find A Particular Map
    // It Stores Unique Keys Only Once
    if(m.count(fruit)){
        cout << "Price Of " << fruit << " Is " << m[fruit] << endl;
    }
    else {
        cout << "Fruit Is Not Present." << endl;
    }

    // Erase
    m.erase(fruit);
    if(m.count(fruit)){
        cout << "Price Of " << fruit << " Is " << m[fruit] << endl;
    }
    else {
        cout << "Fruit Is Not Present." << endl;
    }

    // Update The Value
    m["banana"] = 20;
    m[fruit] += 20;
    if(m.count(fruit)){
        cout << "Price Of " << fruit << " Is " << m[fruit] << endl;
    }
    else {
        cout << "Fruit Is Not Present." << endl;
    }

    // Iterate Over All The Key Value Pairs
    m["litchi"] = 60;
    m["pineapple"] = 80;

    for (auto it=m.begin(); it!=m.end(); it++){
        cout << "Fruit : " << (*it).first << " & Price : " << (*it).second << endl;
    }

    for (auto it=m.begin(); it!=m.end(); it++){
        cout << "Fruit : " << it->first << " -> Price : " << it->second << endl;
    }

    // For Each Loop
    for (auto p:m){
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}