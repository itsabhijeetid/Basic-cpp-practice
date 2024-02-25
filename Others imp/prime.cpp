// Print prime numbers from 1 to N

#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n = 0;
    cout << "Enter Range : ";
    cin >> n;
    vector<bool> v(n+1,true);
    v[0] = false;
    v[1] = false;
    int c = 0;
    for (int i = 2; i*i <= n; i++) {
        if (!v[i]) continue;
        for (int j = i*i; j <= n; j+=i) {
            v[j] = false;
        }
    }
    for (int i = 2; i < n; i++) {
        if (v[i])  {
            cout << i << " ";
            c++;
        }
    }
    cout << "\nTotal no of primes : " << c;
    return 0;
}