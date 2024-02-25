#include<iostream>
using namespace std;
int fact ( int n ) {
    if ( n == 1) {
        return 1;
    }
    int f = n * fact( n -1 );
    return f;
}
int main () {
    int n = 4;
    int f = fact (n);
    cout<<f;
    return 0;
}
