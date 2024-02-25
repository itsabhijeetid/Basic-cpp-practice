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

void print (Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deleteRecursively (Node *head, int i) {
    if (i == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = deleteRecursively (head->next, i - 1);
    head->next = temp;
    return head;
} 
int main () {
    Node *head = insert();
    print (head);
    int i;
    cout << "Enter the position to delete : ";
    cin >> i;
    head = deleteRecursively(head, i);
    print (head);
    return 0;
}