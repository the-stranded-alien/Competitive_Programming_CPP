#include<iostream>
#include<list>
using namespace std;

// Some More Functions In The List

int main() {

    list<string> l{"kiwi", "mango", "guava", "banana"};
    l.push_back("orange");
    l.push_back("lemon");
    l.push_back("guava");

    for(string s:l){
        cout << s << "-->";
    }
    cout << endl;

    // Remove Element By Value
    string f;
    cin >> f;
    l.remove(f);
    for(string s:l){
        cout << s << "-->";
    }
    cout << endl;

    // Erase One Or More Elements By Index
    // auto it = l.begin() + 3; 
    // Direct Access Don't Work In Lists Unlike Vectors
    auto it = l.begin();
    it++;
    it++;
    l.erase(it);
    for(string s:l){
        cout << s << "-->";
    }
    cout << endl;

    // Insert Elements In The List
    it = l.begin();
    it++;
    l.insert(it, "peach");
    for(string s:l){
        cout << s << "-->";
    }
    cout << endl;

    return 0;
}