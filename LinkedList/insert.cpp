#include<iostream>
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

void print (Node *temp) {
    while (temp != NULL) {
        cout << temp->data <<" ";
        temp = temp->next;
    } cout << endl;
}

Node* insertInMid ( Node* head, int i, int data ) {
    Node *tempHead = head;
    // insert At begning
    if ( i == 0) {
         Node *newNode = new Node (data);
         newNode->next = head;
         return newNode;
    }
    // insert at any position other that begning
    while ( i > 1) {
        tempHead = tempHead->next;
        i -= 1;
    }   Node *newNode = new Node (data);
        Node *temp = tempHead->next;
        tempHead->next = newNode;
        newNode->next = temp;
        return head;
}

Node* deleteNode (Node *tempHead, int i ) {
    Node* head = tempHead;
    if ( i == 0 ) {
        Node* temp = head->next;
        delete (head);
        return temp;
    }
    while ( i > 1) {
        head = head->next;
        i -= 1;
    } Node *temp = head->next->next;
      delete (head->next);
      head->next = temp;
      return head;
}

int Mid_Element (Node* head) {
    Node* slow = head; 
    Node* fast = head;
    while (fast->next != NULL && fast != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    } 
    return slow->data;
}

int main () {
    cout << "Enter the elements :\n";
    cout << "Note: press -1 to stop input\n";
    Node *head = insert();
    print(head);
    int i , n;
    cout << "Enter the postion: ";
    cin >> i;
    cout << "Enter the element to be inserted : ";
    cin >> n;
    head = insertInMid (head, i, n);
    print(head);
    cout << "Enter the postion to be deleted : ";
    cin >> i;
    head = deleteNode(head, i);
    print(head);
    int mid = Mid_Element (head);
    cout <<"\nMid Index Of Linkedlist is : " << mid;
    return 0;
}