#include<bits/stdc++.h>
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
    Node *head = NULL, *tail = NULL;
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
        } cin >> data;
    } tail->next = head;
    return head;
}

Node* insertInMid (Node* head, int index, int data) {
    if (index < 0 ) {
        cout << "Please enter valid index\n";
        return head;
    }
    Node* ptr = head;
    Node* newNode = new Node (data);
    if (index == 0) {
        while (ptr->next != head) {
            ptr = ptr->next;
        }  
        newNode->next = head;
        ptr->next = newNode;
        head = newNode;
    } else {
        for (int i = 0; i < index-1; i++) {
            ptr = ptr->next;
        }
        Node* temp = ptr->next; 
        ptr->next = newNode;
        newNode->next = temp;
    } 
    return head;
}

Node* deleteNode (Node* head, int index) {
    if (index < 0 ) {
        cout << "Please enter valid index\n";
        return head;
    }
    if (index == 0) {
        Node* temp = head;
        Node* ptr = head;
        head = head->next;
        while (ptr->next != temp) {
            ptr = ptr->next;
        }  
        ptr->next = head;
        delete temp;
    } 
    else {
        Node* ptr = head;
        for (int i = 0; i < index - 1; i++) {
            ptr = ptr->next;
        } 
        Node* temp = ptr->next->next;
        delete ptr->next;
        ptr->next = temp;
        // Node* temp = ptr->next;
        // ptr->next = ptr->next->next;
        // delete temp;
    }
    return head;
}

int MidElement (Node* head) {
    Node* slow = head;
    Node* fast = head;
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != head && fast->next != head);
    return slow->data;
}

void print (Node* head) {
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main () {
    Node* head = insert ();
    print (head);
    head = insertInMid (head, 3, 55);
    print(head);
    head = deleteNode (head, 0);
    print(head);
    cout << "Mid : " << MidElement (head);
    return 0;
}