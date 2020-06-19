#include<iostream>
#include<unordered_map>
using namespace std;

// Implementation Of Hashtable

// Insertion(), Erase(), Find() Work 
// In O(1) Time On Average !!
// When Hashtable Grows Big And Rehashing 
// Is Done It Takes O(N) Time

int main() {

    unordered_map<string, int> um;

    // Insert
    um.insert(make_pair("mango", 100));

    pair<string, int> p;
    p.first = "apple";
    p.second = 120;
    um.insert(p);

    um["banana"] = 20;

    // Search
    string fruit;
    cin >> fruit;

    // auto it = m.find(fruit);
    unordered_map<string, int>::iterator it = um.find(fruit);
    if(it!=um.end()){
        cout << "Price Of " << fruit << " Is " << um[fruit] << endl;
    }
    else {
        cout << "Fruit Is Not Present." << endl;
    }

    // Another Way To Find A Particular Map
    // It Stores Unique Keys Only Once
    if(um.count(fruit)){
        cout << "Price Of " << fruit << " Is " << um[fruit] << endl;
    }
    else {
        cout << "Fruit Is Not Present." << endl;
    }

    // Erase
    um.erase(fruit);
    if(um.count(fruit)){
        cout << "Price Of " << fruit << " Is " << um[fruit] << endl;
    }
    else {
        cout << "Fruit Is Not Present." << endl;
    }

    // Update The Value
    um["banana"] = 20;
    um[fruit] += 20;
    if(um.count(fruit)){
        cout << "Price Of " << fruit << " Is " << um[fruit] << endl;
    }
    else {
        cout << "Fruit Is Not Present." << endl;
    }

    // Iterate Over All The Key Value Pairs
    um["litchi"] = 60;
    um["pineapple"] = 80;

    for (auto it=um.begin(); it!=um.end(); it++){
        cout << "Fruit : " << (*it).first << " & Price : " << (*it).second << endl;
    }

    for (auto it=um.begin(); it!=um.end(); it++){
        cout << "Fruit : " << it->first << " -> Price : " << it->second << endl;
    }

    // For Each Loop
    for (auto p:um){
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}