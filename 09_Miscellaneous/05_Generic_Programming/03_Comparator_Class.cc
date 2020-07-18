#include<iostream>
#include<list>
#include<vector>
using namespace std;

// Templates + Iterators + Comparator
template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp) {
    while(start != end) {
        if(cmp((*start), key)) return start;
        start++;
    }
    return end;
}

class Book {
public:
    string name;
    int price;
    Book() { }
    Book(string n, int p) {
        this->name = n;
        this->price = p;
    }
};

class BookCompare {
public:
    // Functor (Functional Object)
    bool operator()(Book A, Book B) {
        if(A.name == B.name) return true;
        return false;
    }
};

int main() {
    Book b1("C++", 100);
    Book b2("Python", 120);
    Book b3("Java", 130);
    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);
    Book bookToFind("C++", 110);
    BookCompare cmp;
    // if(cmp(b1, bookToFind)) cout << "Same Books" << endl;
    list<Book>::iterator it = search(l.begin(), l.end(), bookToFind, cmp);
    if(it != l.end()) cout << "Book Found In The Library\n";
    else cout << "Book Not Found\n";
    return 0;
}