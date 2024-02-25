#include <iostream>
#include <vector>
using namespace std;

int main () {
    // vector<int> *v = new vector<int>();   // dynamic allocation
    vector<int> v;  // static allocation
    // taking input in vector
    for (int i = 0; i < 6; i++) {   // their is no size constriant in vector
        // v->push_back(i + 1);    // if dynamic allocation
        v.push_back(i + 1);    // if staticly allocated
    }   /* Note : we should never use v[i] = 2 ,like this for taking input 
        in vector like array as it will not double it's size . for doubling the 
        size we have to use push_back() only as it doubles it's size*/
        
        // And note : that push_back() automatically push the element backward 
        // it does not need index number as in array so if we do in between v[2] = 13
        // and after that push_back(17) then 17 will not go to 3rd index it will go to 
        // 2nd index 13 will not be considered.

    v.pop_back();   // for deleting the last element in vector.
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " "; // for dynamic allocation v->at(i);

        // cout << v[i];   // we can use this also as here it will not creat
                        // problem as we ristricted the loop it will only run 
                        // till the vector size. If we had tried to print after 
                        // v.size() then it will print the garbages.
                        // but v.at() will give error. So, v.at() is safier.
    }
    return 0;
}
