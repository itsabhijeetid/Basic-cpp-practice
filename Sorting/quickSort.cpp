#include <bits/stdc++.h>
using namespace std;

void QuickSort (int arr[], int start, int end) {
    if (start >= end)
        return;
    int pivot = arr[end];
    int i = -1;
    for (int j = start; j < end; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[start+i], arr[j]);
        } 
    }
    i++;
    swap(arr[start+i], arr[end]);
    QuickSort (arr, start, start+i-1);
    QuickSort (arr, start+i+1, end);
}

void QuickSort (int arr[], int size) {
    shuffle (arr, arr+size, default_random_engine (0)); // shuffle the array element randomly for a better result.
    QuickSort (arr, 0, size-1);
}

int main () {
    int arr[] = {10,4,6,19,45,2,0};
    int n = 7;
    QuickSort (arr, n);
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    return 0;
}