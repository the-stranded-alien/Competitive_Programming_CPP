#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    // Constructor
    Node(int data) {
        this->data = data;
    }
};

Node *getNode(Node *&head, int data) {
    Node *temp = head;
    while(temp->next != head) {
        if(temp->data == data) return temp;
        temp = temp->next;
    }
    if(temp->data == data) return temp;
    else return NULL;
}

void push(Node *&head, int data) {
    Node *ptr = new Node(data);
    Node *temp = head; // Used To Traverse The LL
    ptr->next = head;
    if(head != NULL) {
        while(temp->next != head) temp = temp->next;
        temp->next = ptr;
    } else {
        ptr->next = ptr;
    }
    head = ptr;
    return;
}

void deleteNode(Node *&head, int data) {
    Node *del = getNode(head, data);
    if(del == NULL) {
        cout << "Node Not Present In The Circular Linked List\n";
        return;
    }
    if(head == del) head = del->next;
    Node *temp = head;
    while(temp->next != del) temp = temp->next;
    temp->next = del->next;
    delete del;
    return;
}

void printCLL(Node *head) {
    Node *temp = head;
    while(temp->next != head) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }        
    cout << temp->data << " : END\n";
    return;
}

int main() {
    Node *head = NULL;
    push(head, 10);
    push(head, 20);
    push(head, 30);
    push(head, 40);
    push(head, 50);
    push(head, 60);
    printCLL(head);
    deleteNode(head, 30);
    printCLL(head);
    return 0;
}