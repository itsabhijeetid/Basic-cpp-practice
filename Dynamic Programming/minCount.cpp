// No. of minimum square series is required to get n
//  ex n = 10, then 1^2 + 3^2 = 10 , hence 2 is ans 

#include<bits/stdc++.h>
using namespace std;

int minCount (int n) {
    int c = 0;
    while (n != 0) {
        int sq = sqrt(n);
        n = n - (sq*sq);
        c++;
    }
    return c;
}


int main () {
    int n = 6;
    cout << minCount (n);
    return 0;
}