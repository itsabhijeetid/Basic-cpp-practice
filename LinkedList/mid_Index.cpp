#include <iostream>
using namespace std;

class Node {
    public : 
        int data;
        Node *next;
        Node (int data) {
            this->data = data;
            next = NULL;
    }
};

Node* insert () {
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    cin >> data;
    while (data != -1) {
        Node *newNode = new Node (data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int midElement (Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main () {
    Node *head = insert();
    print(head);
    cout << endl;
    // Node *mid = midElement(head);
    // cout << mid->data;
    cout << midElement(head);
    return 0;
}