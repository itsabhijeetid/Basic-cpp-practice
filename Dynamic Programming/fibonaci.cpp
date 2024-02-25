#include <iostream>
using namespace std;

long fibonnaci (long n) {
    if (n <= 1)
        return n;
    return fibonnaci(n-1) + fibonnaci(n-2);
}

long fibonnaciBetter (long n, long *arr) {
    if (n <= 1) {
        arr[n] = n;
        return n;
    }
    if (arr[n-1] == -1)
        arr[n-1] = fibonnaciBetter (n-1,arr);
    if (arr[n-2] == -1)
        arr[n-2] = fibonnaciBetter(n-2,arr);
    return arr[n-1] + arr[n-2];
}

// Memoization Method (Top to Down)
long fibonnaciBetter (long n) {
    long *arr = new long[n+1];
    for (int i = 0; i < n+1; i++)
        arr[i] = -1;
    return fibonnaciBetter (n, arr);
}

// Dynamic Programming (Bottom to Up)
long fibonnaci_DP (long n) {
    long *arr = new long [n+1];
    arr[0] = 0; 
    arr[1] = 1; 
    for (int i = 2; i < n+1; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int main () {
    long n = 12;
    cout << fibonnaci (n) << endl;
    cout << fibonnaciBetter (n) << endl;
    cout << fibonnaci_DP(n) << endl;
    return 0;
}