#include<iostream>
#include<string>
#include<iterator>
using namespace std;

int main() {
    
    // String Init
    string s0;
    string s1("Hello");

    // String Assignment
    string s2 = "Hello World!";

    // Copy Constructor
    string s3(s2);
    string s4 = s3;

    // Initialising String Object From Array
    char a[] = {'a', 'b', 'c', '\0'};
    string s5(a);

    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;

    // Is Empty
    if(s0.empty()){
        cout << "s0 Is An Empty String" << endl;
    }

    // Append Characters in C++
    s0.append("I Love C++");
    cout << s0 << endl;

    // Using + Operator To Append
    s0 += " and Python";
    cout << s0 << endl;

    // Remove/Erase The Contents Of String Object
    // Length Function
    cout << s0.length() << endl;
    s0.clear();
    cout << s0.length() << endl;

    // Compare Two Strings;
    string sx = "Apple";
    string sy = "Mango";
    // Returns An Integer == 0 If Strings Are Equal
    // Returns An Integer > 0 or < 0, If Strings Are Not Equal
    // It Returns A Lexographical Difference.  
    cout << sx.compare(sy) << endl;
    cout << sy.compare(sx) << endl;
    cout << sx.compare(sx) << endl;

    // Using Overloaded Operators '<' or '>' For Comparisons
    if(sy > sx) cout << "Mango Is Lexically Greater Than Apple" << endl;

    // Accessing A Char of String
    cout << sx[0] << endl;

    // Find Sub-Strings
    string st = "I want to have apple juice";
    int idx = st.find("apple");
    cout << idx << endl;

    // Remove A Word From The String
    string word = "apple";
    int len = word.length();
    cout << st << endl;
    st.erase(idx, len+1);
    cout << st << endl;

    // Iterate Over All The Character in the String
    for(int i=0; i<sx.length(); i++){
        cout << sx[i] << "-";
    }
    cout << endl;

    // Iterators
    // '::' Scope Resolution Operator
    for(string::iterator it=sx.begin(); it!=sx.end(); it++) {
        cout << (*it) << ",";
    }
    cout << endl;

    // For Each Loop To Iterate
    for(char c : sx){
        cout << c << ".";
    }
    cout << endl;

    return 0;
}