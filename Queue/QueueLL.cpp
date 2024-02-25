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
class queue {
    private : 
        Node<T> *head;
        Node<T> *tail;
        int sz; 
    public :
        queue () {
            head = NULL;
            tail = NULL;
            sz = 0;
        }
        int size () {
            return sz;
        }
        bool empty () {
            return sz == 0;
        }
        void enqueue (T data) {
            Node<T>* newNode = new Node<T> (data);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            } 
            sz++;
        }
        void dequeue () {
            if (empty() ) {
                cout << "Queue underflow : no element found\n";
                return;
            } Node<T> *temp = head;
              head = head->next;
              delete temp;
              sz--;
        }
        T front () {
            if (empty() ) {
                cout << "No element found : Queue is Empty\n";
                return 0;
            }
            return head->data;
        }
};

int main () {
    queue<int> q;
    cout << q.front() << endl; // error will occur in string
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    cout << q.front() << endl;
    q.dequeue ();
    q.dequeue ();
    q.dequeue ();
    cout << q.front() << endl << q.size() << endl << q.empty();
    return 0;
}