#include <iostream>
using namespace std;

void Merge ( int arr[], int si, int mid, int ei) {
    int size_1 = mid - si + 1;
    int size_2 = ei - mid;
    int a[size_1] , b[size_2];
    for (int i = 0; i < size_1; i++) {
        a[i] = arr[si + i];
    } 
    for (int i = 0; i < size_2; i++) {
        b[i] = arr[mid + i + 1];
    }
    int i = 0 , j = 0, k = si;
    while (i < size_1 && j < size_2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++ ; k++;
        } else {
            arr[k] = b[j];
            j++ ; k++;
        }
    } 
    while (i < size_1) {
        arr[k] = a[i];
        i++ ; k++;
    } while (j < size_2) {
        arr[k] = b[j];
        j++; k++;
    }
}
void MergeSort ( int arr[], int si, int ei ) {
    if ( si >= ei) {
        return;
    } int mid = ( si + ei ) / 2;
    MergeSort ( arr, si, mid);
    MergeSort ( arr, mid + 1, ei);
    Merge (arr, si, mid,ei); 
}

int main () {

    int arr[] = {4,3,2,1,0,1};
    // int arr[] = {1,3,5,3,6,0};
    int size = 6;
    int si = 0, ei = size - 1;
    MergeSort ( arr, si, ei);

    for ( int i = 0; i < size; i++ ) {
        cout << arr[i] << " ";
    } 
    return 0;
}