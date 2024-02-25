/* Map is of two types
1. map -> made with BST -> O (logn)
2. unordered-map -> mad with hashtable -> O (1)
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main () {
    unordered_map <string, int> m; // unordered_map <key,value>
    // 1st way to insert 
    pair<string,int> p ("abc",1);
    m.insert(p);
    // 2nd way to insert
    m["def"] = 2;
    // for access
    cout << m["abc"] << endl;
    cout << m.at("abc") << endl;
    cout << "size : " << m.size()<< endl;
    cout << m["gef"] << endl; /*this will not give error if key is 
                              not present then also as if the key is
                              not present then it add that key and adds
                              default value to it i.e 0 and print 0*/ 
    cout << "size : " << m.size()<< endl; // size increses by 1 as m["gef"] adds that non-present key.
    // for checking presence
    if (m.count("gef") > 0) {   // count() returns only 1 and 0 is present then 1 and not present then 0 (may be not confirm).
        cout << "gef is present\n";
    }

    cout << m.at("gef") << endl; // it will through error as key is not present.
    // for deleting the element
    cout << m.erase("gef");
    cout << "size : " << m.size() << endl;
    // for checking presence
    if (m.count("gef") > 0) {
        cout << "gef is present\n";
    }
    return 0;
}