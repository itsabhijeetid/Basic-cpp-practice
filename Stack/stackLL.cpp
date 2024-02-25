#include <iostream>
using namespace std;

template <typename T>
class Node {
    public : 
        T data;
        Node *next;
        Node (T data) {
            this->data = data;
            next = NULL;
        }
};

template <typename T>
class Stack {
    Node<T> *head;
    int size , delElement;
    public : 
        Stack () {
            head = NULL;
            size = 0;
        }
        void push (T data) {
            Node<T> *newNode = new Node<T> (data);
            if (head == NULL) {
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            } size++;        
        }
        bool isEmpty () {
            return head == NULL; 
        }
        T top () {
            if (!isEmpty() ) {
                return head->data;
            } else {
                cout <<"Stack Empty No Element found\n";
                return 0;
            }
        }
        void pop () {
            if(!isEmpty() ) {
                delElement = head->data;
                Node<T> *temp = head;
                head = head->next;
                size--;
                delete temp;
                cout << "Element deleted Successfully\n";
            } else {
                cout <<"Stack Empty No Element found\n";
            }            
        }
        int getsize() {
            return size;
        }
};

int main () {
    Stack<int> s;
    int data;
    cin >> data;
    while (data != -1) {
        s.push(data);
        cin >> data;
    } 
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl << s.getsize() << endl << s.isEmpty();
    return 0;
}
