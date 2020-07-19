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

void insertAtTail(node *&head, int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }
    node *tail = head;
    while(tail->next != NULL) tail = tail->next;
    tail->next = new node(data);
    return;
}

void print(node *head) {
    // As Here, Head Is Passed By Value, Original Head Won't Change 
    while(head != NULL) {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << endl;
}

void buildList(node *&head) {
    int data;
    cin >> data;
    while(data != -1) {
        insertAtTail(head, data);
        cin >> data;
    }
}

istream& operator>>(istream &is, node *&head) {
    buildList(head);
    return is;
}

ostream& operator<<(ostream &os, node *head) {
    print(head);
    return os;
}

void reverseIterative(node *&head) {
    node *C = head; // Current Node
    node *P = NULL; // Previous Node
    node *N;        // Next Node
    while(C != NULL) {
        // Save The Next Node
        N = C->next;
        // Make The Current Node Point To Previous
        C->next = P;
        // Just Update Previous And The Current
        P = C;
        C = N;
    }
    head = P;
    return;
}

node* reverseRecursive(node *head) {
    // Base Case
    if(head->next == NULL || head == NULL) return head;
    // Recursive Case
    node *smallHead = reverseRecursive(head->next);
    node *C = head;
    C->next->next = C;
    C->next = NULL;
    return smallHead;
}

int main() {
    node *head = NULL;
    cin >> head;
    cout << head;
    // reverseIterative(head);
    head = reverseRecursive(head);
    cout << head;
    return 0;
}