// Doubly Circular Linked List
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
    tail->next = head;
    tail = tail->next;
    head->prev = tail;
    return head;
}


// Error Not Working 
template <typename T>
Node<T>* deleteNode (Node<T>* head, int position) {
    Node<T>* temp = head;
    if (position < 0 || head == NULL) {
        cout << "Enter valid detail\n";
        return NULL;
    }
    if (position == 0) {
        temp = head->prev;
        delete head;
        head = head->next;
        head->prev = temp;
        return head;
    }
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    } 
    Node<T>* ptr = temp->next->next;
    delete temp->next;
    temp->next = ptr;
    ptr->prev= temp;
    return head;
} 

template <typename T>
void print (Node<T>* head) {
    Node<T>* temp = head;
    if (head == NULL) {
        cout << "No Element found\n";
        return;
    }
    do 
    {
        cout << head->data << " ";
        head = head->next;
    } while (head != temp); 
    cout << endl;
}

int main () {
    Node<int>* head = insert<int>();
    print (head);
    head = deleteNode (head, 2); // Not Working
    print (head);
    return 0;
}