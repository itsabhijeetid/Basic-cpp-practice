#include <iostream>
#include <vector>
using namespace std;

int main () {
    // vector<int> v;  // static allocation
    vector<int> *v = new vector<int>;   // dynamic allocation
    vector<int> :: iterator it;   // Iterator declaration
    for (int i = 0; i < 5; i++) {
        v->push_back(i + 1);
    }
    // Output using Iterator
    for (it = v->begin(); it != v->end(); it++) {
        cout << *it << " ";     /* as iterator is an pointer to an element
                                    within the range of an element so by 
                                    derefrencing we can get the element of an 
                                    vector and without derefrencing we will get address. */ 
    }
    /* Note : v.end() or v->end points to the next postion of the
              last element of vector.
              And
              v.begin() or v->begin() points to the 1st postion of 
              the vector. */
    v->erase(it,it + 4); // will earse the element form the address pointing the it to it + 4
    return 0;
}