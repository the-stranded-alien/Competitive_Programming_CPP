#include<iostream>
using namespace std;

class node {
public: 
    int data;
    node *next;
    // Constructor
    node(int d) {
        data = d;
        next = NULL;
    }
};

// Passing Pointer Variable By Reference
void insertAtHead(node *&head, int data) {
    node *n = new node(data);
    n->next = head;
    head = n;
}

int length(node *head) {
    int len = 0;
    while(head != NULL) {
        head = head->next;
        len += 1;
    }
    return len;
}

void print(node *head) {
    // As Here, Head Is Passed By Value, Original Head Won't Change 
    while(head != NULL) {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << endl;
}

bool searchRecursive(node *head, int key) {
    if(head == NULL) return false;
    // Recursive Case
    if(head->data == key) return true;
    else return searchRecursive(head->next, key);
}

bool searchIterative(node *head, int key) {
    while(head != NULL) {
        if(head->data == key) return true;
        head = head->next;
    }
    return false;
}

int main() {
    node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 6);
    print(head);
    if(searchRecursive(head, 4)) cout << "Element Is Present\n";
    else cout << "Element Is Not Present\n";
    if(searchIterative(head, 3)) cout << "Element Is Present\n";
    else cout << "Element Is Not Present\n";
    return 0;
}