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
Node<T>* insert (Node<T>* head, int data, int position) {
    if (position <= 0) {
        cout << "Enter valid position ";
        return head;
    }
    Node<T>* newNode = new Node<T> (data);
    Node<T>* ptr = head;
    if (position == 1) {
        head = newNode;
        return head;
    }
    while (position--) {
        ptr = ptr->next;
    }
    Node<T>* temp = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = temp;
    temp->prev = newNode;
    return head;
}


template <typename T>
void print (Node<T>* head) {
    Node<T>* temp = head;
    if (temp == NULL) {
        cout << "No Element found\n";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;
}


int main () {
    Node<int>* head;
    int data = 0, position;
    while (true) {
    cout << "Enter data and position : ";
        cin >> data >> position;
        if (data == -1)
            break;
        head = insert<int>(head, data, position);
        print (head);
    }
    return 0;
}