#include <iostream>
using namespace std;

void CopyBack ( int new_arr[], int arr[], int size) {
    if ( size != 0 ) {
        arr[0] = new_arr[0];
        CopyBack ( new_arr + 1, arr + 1, size - 1);
    } 
}

void Merge ( int new_arr[], int arr[], int si_1, int ei_1, int si_2, int ei_2,int k ) {

    if ( si_1 == ei_1 + 1 || si_2 == ei_2 + 1) {
        return;
    }

    if ( arr[si_1] <= arr[si_2] ) {
        new_arr[0] = arr[si_1];
        k++;
        Merge ( new_arr + 1, arr, si_1 + 1, ei_1, si_2, ei_2,k); 
    } else {
        new_arr[0] = arr[si_2];
        k++;
        Merge ( new_arr + 1, arr, si_1, ei_1, si_2 + 1, ei_2,k); 
    }  
          CopyBack ( new_arr, arr, k);
  
 
    // for (int i = 0; i < k; i++ ) {
    //     arr [i] = new_arr[0];
    // }
}

void MergeSort ( int arr[], int si, int ei ) {
    if ( si >= ei) {
        return;
    } int mid = ( si + ei ) / 2;
    MergeSort ( arr, si, mid);
    MergeSort ( arr, mid + 1, ei);
    int new_arr [ ei + 1 ];
    Merge ( new_arr, arr, si, mid, mid + 1, ei,0); 

}

int main () {

    // int arr[] = {4,3,2,1,0};
    int arr[] = {1,3,5,3,6,0};
    int size = 6;
    int si = 0, ei = size - 1;
    MergeSort ( arr, si, ei);

    for ( int i = 0; i < size; i++ ) {
        cout << arr[i] << " ";
    } 
    return 0;
}