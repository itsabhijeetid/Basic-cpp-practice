#include <iostream>
#include<unordered_map> // we are using unordered_map to reduce the time complexcity to O(1)
#include <vector>   // we are using vector instead of array so not to take tension of size.
using namespace std;

// Total complexcity of Fun is O (n) only 
template <typename T>
vector<T> removeDuplicates (int *a, int size) {
    vector<T> output;
    unordered_map<T,bool> m;
    for (int i = 0; i < size; i++) {
        if (m.count(a[i]) > 0) {
            continue; // if element is already present in map then don't add that to vector.
        }
        m[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

int main () {
    int arr[] = {1,2,3,1,1,1,4,4,2,5,3,7,6};
    vector<int> v = removeDuplicates<int> (arr, 13);
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    return 0;
}