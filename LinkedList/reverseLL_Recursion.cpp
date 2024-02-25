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

// Best Approch
Node *reverse (Node *head) {
    if (head->next == NULL || head == NULL) {
        return head;
    } Node *smallcal = reverse (head->next);
      Node *temp = head->next;
      temp->next = head;
      head->next = NULL;
      return smallcal;
}

// Better Approch
// class Pair {
//     public :
//         Node *head;
//         Node *tail;
// };

// Pair reverseLL (Node *head) {
//     if (head->next == NULL || head == NULL) {
//         Pair obj;
//         obj.head = head;
//         obj.tail = head;
//         return obj;
//     } Pair obj = reverseLL (head->next);
//       obj.tail->next = head;
//       head->next = NULL;
//       obj.tail = obj.tail->next;
//       return obj;
// }

// Node* reverse (Node *head) {
//     return reverseLL(head).head; 
// }

// Worst Approch
// Node *reverse (Node *head) {
//     if (head->next == NULL || head == NULL) {
//         return head;
//     } Node *smallcal = reverse (head->next);
//       Node *temp = head;
//       while (temp->next != NULL) {
//           temp = temp->next;
//       } temp->next = head;
//       head->next = NULL;
//       return smallcal;
// }

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
    cout << endl;
    print (rev);
    return 0;
}