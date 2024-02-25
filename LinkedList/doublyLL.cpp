// Doubly Linked List
#include <iostream>
using namespace std;

template <typename T>
class Node {
    public : 
        T data;
        Node* next;
        Node* prev;
        Node (T data) {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

template <typename T>
Node<T>* insert () {
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
    T data;
    cin >> data;
    while (data != -1) {
        Node<T>* newNode = new Node<T> (data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            Node<T>* temp = tail;
            tail = tail->next;
            tail->prev = temp;
        }
        cin >> data;
    }
    return head;
}

template <typename T>
Node<T>* deleteNode (Node<T>* head, int position) {
    Node<T>* temp = head;
    if (position < 0 || head == NULL) {
        cout << "Enter valid detail\n";
        return NULL;
    }
    if (position == 0) {
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    } 
    if (temp->next->next == NULL) {
        delete temp->next;
        temp->next = NULL;
        return head;
    }
    Node<T>* ptr = temp->next->next;
    delete temp->next;
    temp->next = ptr;
    ptr->prev= temp;
    return head;
} 

template <typename T>
void print (Node<T>* head) {
    Node<T>* temp = NULL;
    if (head == NULL) {
        cout << "No Element found\n";
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        // if (head->next == NULL) {
        //     temp = head;
        // }
        head = head->next;
    } cout << endl;
    // while (temp != NULL)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->prev;
    // }
    // cout << endl;
}

Node<int>* reverse (Node<int>* head) {
    Node<int>* current = head;
    Node<int>* prevNode = NULL;
    Node<int>* nextNode= head->next;
    while (nextNode != NULL) {
       current->next = prevNode;
       current->prev = nextNode;
       prevNode = current;
       current = nextNode;
       nextNode = nextNode->next;
    } 
    current->next = prevNode;
    current->prev = nextNode;
    return current;
}

int main () {
    Node<int>* head = insert<int>();
    print (head);
    Node<int>* rev = reverse(head);
    print (rev);
    head = deleteNode (rev, 4);   
    print (head);
    return 0;
}