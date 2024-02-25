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

Node* reverse (Node* head) {
    Node* prev = NULL, *Next = head->next;
    while (Next != NULL) {
        head->next = prev;
        prev = head;
        head = Next;
        Next = Next->next;
    } 
    head->next = prev;
    return head;
}

void print (Node *temp) {
    while (temp != NULL) {
        cout << temp->data <<" ";
        temp = temp->next;
    } cout << endl;
}

int main () {
    Node *head = insert ();
    print (head);
    Node *rev = reverse (head);
    print (rev);
    return 0;
}