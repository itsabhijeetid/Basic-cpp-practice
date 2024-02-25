#include <iostream>
#include <unordered_map>
using namespace std;

int main () {
    int arr[] = {1,2,3,4,5,2,3,4};
    unordered_map<int,int> m;
    for (auto i:arr) 
        m[i]++;
    // unordered_map<int,int> :: iterator it;
    for (auto it = m.begin(); it != m.end(); it++) 
        cout << it->first << " " << it->second << endl;
    return 0;
}