#include <iostream>
using namespace std;

int CheckEven ( long long int arr[], int size, int c) {
    switch (size) {
        case 0 : 
            return c;
    }
    arr[0] = arr[0] % 2;
    switch (arr[0])
    {
    case 0 :
        c++;
        break;
    }
    return CheckEven (arr + 1, size - 1, c);
}

void input (long long int arr[], int size) {
    switch (size) {
        case 0 : 
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