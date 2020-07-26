#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

// Functional Object -> Functor
class Fun {
public:
    void operator()(string s) {
        cout << "Having Fun Inside Operator() Fn !!, With String : " << s << endl;
    }
};

class Person {
public:
    string name;
    int age;
    Person() {

    }
    Person(string n, int a) {
        name = n;
        age = a; 
    }
};

class PersonCompare {
public:
    bool operator()(Person A, Person B) {
        return (A.age < B.age); // Top 'K' Old Persons
        // return (A.age > B.age); // Top 'K' Young Persons
    }
};

int main() {
    // Fun f; // Constructor
    // f("C++"); // Overloaded ( ) Operator = Function Call Where 'f' Is An Object
    int n;
    cin >> n;
    priority_queue<Person, vector<Person>, PersonCompare > pq;
    for(int i = 0; i < n; i++) {
        string name;
        int age;
        cin >> name >> age;
        Person p(name, age);
        pq.push(p);
    }
    // while(!pq.empty()) {
    //     cout << "Name : " << pq.top().name << "& Age : " << pq.top().age << endl;
    //     pq.pop();
    // }

    int k = 3; // Top 'K' Young / Old Persons
    for(int i = 0; i < k; i++) {
        Person p = pq.top();
        cout << "Name : " << p.name << " & Age : " << p.age << endl;
        pq.pop();
    }
    return 0;
}