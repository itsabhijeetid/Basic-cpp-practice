#include<iostream>
using namespace std;

int main () {
    int n,s;
    cout << "Enter the length of an array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    cout <<"Enter the search element: ";
    cin >> s;
    int low = 0, high = n-1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == s) {
            cout << "Element found at index " << mid+1<< endl;
            break;
        }
        else if (s < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (low > high)
        cout << "Not Found\n";
    return 0;
}

