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

void deleteAtHead(node *&head) {
    if(head == NULL) return;
    node *temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtTail(node *&head) {
    node *prev = NULL;
    node *temp = head;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
    return;
}

void deleteInMiddle(node *&head, int p) {
    if(head == NULL) return;
    node *temp = head;
    if(p == 0) deleteAtHead(head);
    if(p > length(head)) deleteAtTail(head);
    int jump = 1;
    while(temp != NULL && jump <= (p - 1)) {
        temp = temp->next;
        jump += 1;
    } 
    if(temp == NULL || temp->next == NULL) return;
    node *next = temp->next->next;
    delete temp->next;
    temp->next = next;
    return;
}

int main() {
    node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    deleteAtHead(head);
    deleteAtTail(head);
    print(head);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    deleteInMiddle(head, 4);
    print(head);
    return 0;
}