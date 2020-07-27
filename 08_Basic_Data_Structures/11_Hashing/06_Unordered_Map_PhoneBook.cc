#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<string, vector<string> > phonebook;
    phonebook["abcde"].push_back("9110");
    phonebook["abcde"].push_back("9111");
    phonebook["abcde"].push_back("9112");
    phonebook["abcde"].push_back("9113");
    phonebook["abcde"].push_back("9114");
    phonebook["xyzxy"].push_back("8210");
    phonebook["xyzxy"].push_back("8211");
    phonebook["xyzxy"].push_back("8212");
    phonebook["xyzxy"].push_back("8213");

    for(auto p : phonebook) {
        cout << "Name : " << p.first << " --> ";
        for(auto num : p.second) cout << num << ", "; 
        cout << endl;
    }

    string name;
    cin >> name;
    if(phonebook.count(name) == 0) cout << "Absent\n";
    else {
        for(string s : phonebook[name]) cout << s << " - ";
        cout << endl;
    }
    
    return 0;
}