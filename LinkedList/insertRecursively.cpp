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
  Node *head = NULL;
  Node *tail = NULL;
  int data;
    while (true) {
        cin >> data;
        if ( data != -1 ) {
            Node *newNode = new Node(data);
            if ( head == NULL ) {
                head = newNode;
                tail = newNode;
            } 
            else {
                tail->next = newNode;
                tail = tail->next;  // for updating tail as now it should point newNode
                // Or
                // tail = newNode; // not confirm about this
            }
        } else {
            break;
        }
    }
    return head;
}

Node *midInsert ( Node *head, int i, int data) {
    if ( i == 0 ) {
        Node *newNode = new Node (data);
        Node *temp = head;
        head = newNode;
        head->next  = temp;
        return head;
    } 
    Node* temp = midInsert (head->next, i - 1, data);
    head->next = temp;
    return head;
}

void print (Node* head) {
    while ( head != NULL ) {
        cout << head->data << " ";
        head = head->next;
    }    
}

int main () {
    Node* head = insert();
    print (head);
    int i, data;
    cout<< "Enter index : ";
    cin >> i;
    cout << "Enter data : ";
    cin >> data;
    head = midInsert(head, i, data);
    print (head);
    return 0;
}