#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main () {
    unordered_map <string,int> m;
    m["abc"] = 1;  
    m["abc1"] = 2;  
    m["abc2"] = 3;  
    m["abc3"] = 4;  
    m["abc4"] = 5;  
    m["abc5"] = 6;  
    m["abc6"] = 7;
    unordered_map <string,int> :: iterator it;
    it = m.begin();
    // In unordered_map the elements are not stored in order, therefore it will print in unordered.
    while (it != m.end())
    {
        cout << it->first << " : " << it->second << endl;
        it++;
    }
    // find
    it = m.find("abc"); // returns the address of pair <key,value> in short iterator
    cout << it->second;
    m.erase(it);    // will delete the whole pair key and value.
    m.erase(m.begin(),m.end()); // will delete all the elements of map
    it = m.find("def"); 
    cout << it->first << it->second; // no output as no def present

    // erase
    return 0;
}