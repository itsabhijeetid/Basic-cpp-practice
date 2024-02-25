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
    int data;
    Node *head = NULL;
    Node *tail = NULL;  
    cin >> data;
    while (data != -1 ) {
        Node *newNode = new Node (data);
        if ( head == NULL ){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }   cin >> data;
    }
    return head;
}

Node* merge (Node *h1, Node *h2) {
    Node *head = NULL , *tail = NULL;
    while (h1 != NULL && h2 != NULL) {
        if (h1->data < h2->data) {
            if (head == NULL) {
                head = h1;
                tail = h1;
            } else {
                tail->next = h1;
                tail = tail->next;
            } 
            h1 = h1->next;
        } else {
            if (head == NULL) {
                head = h2;
                tail = h2;
            } else {
                tail->next = h2;
                tail = tail->next;
            }
            h2 = h2->next;
        } 
    } 
    if (h1 == NULL) {
        tail->next = h2;
    } else {
       tail->next = h1; 
    }
    return head;
}

void print (Node *temp) {
    while (temp != NULL) {
        cout << temp->data <<" ";
        temp = temp->next;
    } cout << endl;
}

int main () {
    Node *h1 = insert();
    cout << "h1 : ";
    print (h1);
    Node *h2 = insert();
    cout << "\nh2 : ";
    print (h2);
    Node *h3 = merge (h1, h2);
    cout << "\nh3 : ";
    print (h3);
    return 0;
}