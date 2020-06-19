#include<iostream>
#include<unordered_map>
using namespace std;

// Custom Class As Key, Need To Do 2 Things !!
// 1. Write Your Own Hash Function.
// 2. Overload "==" Operator.

class Student{
public:
    string firstName;
    string lastName;
    string rollNo;

    Student(string f, string l, string no) {
        firstName = f;
        lastName = l;
        rollNo = no;
    }

    bool operator==(const Student &s) const {
        return rollNo == s.rollNo?true:false;
    }
};

class HashFn{
public:
    size_t operator()(const Student &s) const {
        return s.firstName.length() + s.lastName.length();
    }
};

int main() {

    unordered_map<Student, int, HashFn> student_map;

    Student s1("Mno", "Def", "163");
    Student s2("Xyz", "Abc", "120");
    Student s3("Mno", "Abcd", "178");
    Student s4("Xyz", "Abc", "179");

    // Add Student-Marks To Hashmap
    student_map[s1] = 100;
    student_map[s2] = 120;
    student_map[s3] = 11;
    student_map[s4] = 45;

    // Iterate Over All Students
    for(auto s:student_map){
        cout << s.first.firstName << " Roll : " << s.first.rollNo;
        cout << " Marks : " << s.second << endl;
    }

    // Find Value For Some Key
    cout << student_map[s3] << endl;

    return 0;
}