// Find the minimum path from n to 1
// ex n= 10, then min path to 1 is 3
// 10-1 = 9, 9/3 = 3, 3/3 = 1 , therefore minStep = 3;

#include<iostream>
using namespace std;

int minStep (int n) {
    if (n < 2)
        return 0;
    int x = minStep (n-1);
    int y = INT16_MAX, z = INT16_MAX;
    if (n % 2 == 0)
        y = minStep (n/2);
    if (n % 3 == 0)
        z = minStep (n/3);
    return 1 + min(x, min(y,z));
}

int minStepBetter (int n, int arr[]) {
    if (n < 2) {
        arr[n] = 0;
        return 0;
    }
    int x = INT16_MAX, y = INT16_MAX, z = INT16_MAX;
    if (arr[n-1] == -1) 
        x = minStepBetter (n-1 ,arr);
    else 
        x = arr[n-1];
    if ( n % 2 == 0) {
        if (arr[n/2] != -1)
         y = arr[n/2];
        else 
            y = minStepBetter (n/2, arr);
    }
    if ( n % 3 == 0) {
        if (arr[n/3] != -1)
         z = arr[n/3];
        else 
            z = minStepBetter (n/3, arr);
    }
    arr[n] = 1 + min (x, min(y,z));
    return arr[n];
}

// Memoization Method (Top to Down)
int minStepBetter (int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = -1;
    return minStepBetter (n, arr);
}

// int minStepDP (int n) {
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         arr[i] = i + 1;
//         arr[i]
//     }
// }

int main() {
    int n = 10;
    cout << minStep (n) << endl;
    cout << minStepBetter (n) << endl;
    return 0;
}
