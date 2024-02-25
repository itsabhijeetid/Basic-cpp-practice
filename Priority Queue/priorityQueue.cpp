/* Priority Queue
It is of two types : 1. Min Priority Queue (element will come out which is having minimum priority)
, 2. Max Priority Queue (element will come out having maximum priority)
It is made by Heap Data Structure.
Heap is also of two type : 1. Min Heap (the root is smaller then both child), 
2. Max Heap (the root is greater then both child)
For making Priority Queue the best technique is by using CBT (Complete Binary Tree)
and Heap Order Property (i.e Min and Max Heap).
*/

#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    private :  
        vector<int> v;
    public : 
        void insert (int data) {
            v.push_back(data);
            int childIndex = v.size() - 1;
            int rootIndex = (childIndex - 1) / 2; 
            while (childIndex > 0)
            {
                rootIndex = (childIndex - 1) / 2;
                if (v[childIndex] < v[rootIndex]) {  // Min Heap
                    int temp = v[childIndex];
                    v[childIndex] = v[rootIndex];
                    v[rootIndex] = temp;
                } else {
                    break;
                }
                childIndex = rootIndex;
            }       
        }
        bool empty() {
            return v.size() == 0;
        }
        int size () {
            return v.size();
        }
        int removeMin () {
            if (empty() ) {
                cout << "No element found\n";
                return 0;
            }
            int removedElement = v[0];
            v[0] = v[v.size() - 1]; // v[size() - 1] is also correct may be check it
            v.pop_back();
            int rootIndex = 0;
            int minElement;
            int L_childIndex = 2*rootIndex + 1; 
            int R_childIndex = 2*rootIndex + 2;
            while (L_childIndex < v.size() ) {   // We are taking L_childIndex instead of rootIndex because by taking rootIndex it was acessing the garbage area as rootIndex have Left and right child.
                minElement = min(v[rootIndex], min(v[L_childIndex], v[R_childIndex]));  
                if (minElement == v[rootIndex]) {
                    break;
                } else if (minElement == v[L_childIndex]) {
                    swap (v[rootIndex], v[L_childIndex]);
                    rootIndex = L_childIndex;
                } else if (minElement == v[R_childIndex] && R_childIndex < v.size() ) { // By keeping L_chilIndex  rootIndex and L_childIndex are coming in range but R_childIndex was going out of range and was accessing the garbage value so, we applied condition R_childIndex < v.size() for kepping it also in range.
                    swap (v[rootIndex], v[R_childIndex]);
                    rootIndex = R_childIndex;
                }
                L_childIndex = 2*rootIndex + 1; 
                R_childIndex = 2*rootIndex + 2;
            }             
            return removedElement;
        }
};

int main () {
    PriorityQueue q;
    cout << q.size() << endl;
    cout << q.empty() << endl;
    q.insert (100);
    q.insert (10);
    q.insert (15);
    q.insert (4);
    q.insert (17);
    q.insert (21);  
    q.insert (67);
    q.insert (66);
    q.insert (16);
    q.insert (190);
    cout << q.size() << endl;
    cout << q.empty() << endl;
    while (!q.empty() )
    {
        cout << q.removeMin() << " ";
    }
    cout << endl << q.removeMin () << endl;
    return 0;
}