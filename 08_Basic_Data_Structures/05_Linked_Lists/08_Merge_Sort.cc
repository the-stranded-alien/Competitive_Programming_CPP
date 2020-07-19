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

node *midPoint(node *head) {
    if(head == NULL || head->next == NULL) return head;
    node *slow = head;
    node *fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *merge(node *a, node *b) {
    if(a == NULL) return b;
    if(b == NULL) return a;
    node *c;
    if(a->data < b->data) {
        c = a;
        c->next = merge(a->next, b);
    }
    else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node *mergeSort(node *head) {
    // Base Case
    if(head == NULL || head->next == NULL) return head;
    // Recursive Case
    // 1. Mid Point
    node *mid = midPoint(head);

    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    // 2. Sort Recursively
    a = mergeSort(a);
    b = mergeSort(b);

    // 3. Merge 'a' & 'b'
    node *c = merge(a, b);
    return c;
}

int main() {
    node *head = NULL;
    cin >> head;
    head = mergeSort(head);
    cout << head;
    return 0;
}