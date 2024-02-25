#include <iostream>
using namespace std;

template <typename T>
class Queue {
    private :
        T *arr; 
        int sz, capacity, nextIndex, firstIndex;
    public : 
        Queue (int n) {
            arr = new T [n];
            capacity = n ;
            nextIndex = 0;
            sz = 0;
            firstIndex = -1;
        }
        bool empty () {
            return sz == 0; 
        }
        void enqueue (T data) {
            if (sz != capacity) { 
                arr[nextIndex] = data;
                nextIndex = (nextIndex + 1) % capacity;
                if (firstIndex == -1) {
                    firstIndex = 0;
                }
                sz +=1;
            } else {
                cout<<"Queue full : Overflow\n";
            }
        }
        void dequeue () {
            if (!empty() ) {
                firstIndex = (firstIndex + 1) % capacity;
                sz--;
                cout << "Element deleted sucessfully\n";
            } else {
                cout <<"Queue empty : Underflow\n";
            }
            if (sz == 0) {
                firstIndex = -1;
                nextIndex = 0;
            }
        }
        int size () {
            return sz;
        }
        T front () {
            if (empty() ) {
                cout << "Queue empty : no element found\n";
                return 0;   // What to return which will exit for both string and int
            } return arr[firstIndex];
        }
};

int main () {
    int s = 5;
    Queue<string> q(s);
    cout << q.front() << endl;  // thorws error in string.
    // for (int i = 0; i < s; i++) {
    //     q.enqueue (i+10);
    // } 
    q.enqueue ("as");
    q.enqueue ("ss");
    q.enqueue ("ds");
    q.enqueue ("fs");
    q.enqueue ("hs");
    q.enqueue ("gs");
    cout << q.front() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.size() << endl << q.empty() << endl << q.front();
    return 0;
}