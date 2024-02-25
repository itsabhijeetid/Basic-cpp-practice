#include <iostream>
using namespace std;

template <typename T>
class Queue {
    private : 
        T *arr;
        int sz, nextIndex, firstIndex, capacity;
    public :
        Queue () {
            capacity = 4;
            sz = 0;
            arr = new T [capacity];
            firstIndex = -1;
            nextIndex = 0;
        }
        bool empty () {
            return sz == 0;
        }
        void enqueue (T data) {
            if (sz == capacity) {
                T *newArr = new T [2 * capacity];
                int j = 0;
                for (int i = firstIndex; i < capacity; i++) {
                    newArr[j] = arr[i];
                    j++;
                } for (int i = 0; i < firstIndex; i++) {
                    newArr[j] = arr[i];
                    j++;
                }
                delete [] arr;
                arr = newArr;
                firstIndex = 0;
                nextIndex = capacity; // or nextIndex = j; 
                capacity *= 2;
            } 
            arr[nextIndex] = data;
            nextIndex = (nextIndex + 1) % capacity;
            sz++;
            if (firstIndex == -1) {
                firstIndex = 0;
            }
        }
        void dequeue () {
            if (empty() ) {
                cout << "Queue empty : underflow\n";
                return;
            } firstIndex = (firstIndex + 1) % capacity;
            sz--;
            cout << "Element deleted sucessfully\n";
            if (sz == 0) {
                nextIndex = 0;
                firstIndex = -1;
            }
        }
        int size () {
            return sz;
        }
        T front () {
            if (empty() ) {
                cout << "Queue Empty : no element found\n";
                return 0;
            } return arr[firstIndex];
        }
};

int main () {
    Queue<int> q;
    // Queue<string> q;
    cout << q.front() << endl;  // thorws error in string.
    for (int i = 0; i < 10; i++) {
        q.enqueue (i+10);
    } cout << q.size() << endl;
    // q.enqueue ("as");
    // q.enqueue ("ss");
    // q.enqueue ("ds");
    // q.enqueue ("fs");
    // q.enqueue ("hs");
    // q.enqueue ("gs");
    cout << q.front() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.size() << endl << q.empty() << endl << q.front();
    return 0;
}