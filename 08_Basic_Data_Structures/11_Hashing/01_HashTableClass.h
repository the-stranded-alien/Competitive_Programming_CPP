#include<iostream>
#include<cstring>
using namespace std;

// Implement A HashMap
// Separate Chaining Technique
template<typename T>
class Node {
public:
    string key;
    T value;
    Node<T> *next;
    // Constructor
    Node(string key, T val) {
        this->key = key;
        this->value = val;
        this->next = NULL;
    }
    // Destructor
    ~Node() {
        if(next != NULL) {
            delete next; // Recursively Deletes All Further Nodes.
        }
    }
};

template<typename T>
class HashTable {
private:
    Node<T> **table; // Pointer To An Array Of Pointers
    int current_size;
    int table_size;
    // Hash Function
    int hashFn(string key) {
        int idx = 0;
        int p = 1;
        for(int j = 0; j < key.length(); j++) {
            idx = (idx + ((key[j] * p) % table_size));
            idx = (idx % table_size);
            p = ((p * 27) % table_size);
        }
        return idx;
    }
    void rehash() {
        Node<T> **oldTable = table;
        int oldTableSize = table_size;
        table_size = (2 * table_size); // Approximation, Better To Find The Next Prime.
        table = new Node<T>*[table_size];
        for(int i = 0; i < table_size; i++) table[i] = NULL;
        current_size = 0;
        // Shift The Elements From Old Table To New Table.
        for(int i = 0; i < oldTableSize; i++) {
            Node<T> *temp = oldTable[i];
            while(temp != NULL) {
                insert(temp->key, temp->value);
                current_size++;
                temp = temp->next;
            }
            if(oldTable[i] != NULL) delete oldTable[i]; // Recursive Destructor Called Automatically.
        }
        delete [] oldTable;
        return;
    }
public:
    // Constructor
    HashTable(int ts = 7) {
        table_size = ts;
        table = new Node<T>*[table_size];
        current_size = 0;
        // Initially All Buckets Don't Have A Linked List And Are Denoted By NULL !
        for(int i = 0; i < table_size; i++) table[i] = NULL;
    }
    // Insert
    void insert(string key, T value) {
        // Get The Index Using The Hash Function.
        int idx = hashFn(key);
        // Create A New Node For The (Key, Value) Pair.
        Node<T> *n = new Node<T>(key, value);
        // Insert At Head Of The Linked List With id = idx.
        n->next = table[idx]; // Place Old Head In Next Of New Node
        table[idx] = n; // Place Address Of New Node In Table
        current_size++;
        // Rehashing
        float load_factor = (current_size / (1.0 * table_size));
        if(load_factor > 0.7) rehash();
        return;
    }
    // Print (Just For Our Observation)
    void print() {
        for(int i = 0; i < table_size; i++) {
            cout << "Bucket : " << i << " --> ";
            Node<T> *temp = table[i];
            while(temp != NULL) {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    // Search
    T* search(string key) {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];
        while(temp != NULL) {
            if(temp->key == key) return (&temp->value);
            temp = temp->next;
        }
        return NULL;
    }
    // Erase (Or Delete)
    // void erase(string key) {
    //
    // }
    // Operator Overloading
    T& operator[](string key) {
        T *f = search(key);
        if(f == NULL) {
            // Insert Key, Value(Garbage) In The Hashmap
            T garbage;
            insert(key, garbage);
            f = search(key);
        }
        return (*f); // Return By Reference.
    }
};