#include <iostream>
#include <queue>
using namespace std;

int main () {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout << q.size() << endl << q.empty() << endl;
    while (!q.empty() ) {
        cout << q.front() << " ";
        q.pop();
    } cout << endl <<  q.empty();
    return 0;
}