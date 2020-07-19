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

int main() {
    node *head1 = NULL;
    node *head2 = NULL;

    // buildList(head);
    // print(head);
    cin >> head1 >> head2;
    cout << head1 << endl << head2 << endl;
    return 0;
}