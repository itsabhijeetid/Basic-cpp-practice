#include <iostream>
using namespace std;

int CheckEven (long long arr[], int size, int c ) {
    if (size == 0) {
        return c;
    }
    int a[3] = {1,0,0};
    c = c + a [arr[0] % 2];
    return CheckEven (arr + 1, size - 1, c);
}

void input (long long int arr[], int size) {
    if (size == 0) {
        return;
    }
    cin >> arr[0];
    input (arr + 1, size - 1);
}

int main () {
    int size = 5;
    long long int arr[size];
    input (arr, size);
    int c = 0;
    int ans = CheckEven (arr, size, c);
    cout << ans;
    return 0;
}