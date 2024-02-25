#include <iostream>
using namespace std;

void swap (int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition (int arr[], int si, int ei) {
    int pivot = arr[si];
    int i = si + 1, j = ei;
    while (i < j) {
        if (arr[i] >= pivot) {
            if (arr[j] < pivot) {
                swap(arr, i, j);
                i++; j--;
            } else {
                j--;
            }
        } else {
            i++;
        }
    } 
    if (arr[i] > pivot) {
        i--;
        swap (arr, si, i);
    } else {
        swap (arr, si, i);
    }
    return i;
}


// same method with another code 
// int partition (int arr[], int si, int ei) {
//     int pivot = arr[ei];
//     int i = si - 1;
//     for (int j = si; j < ei; j++) {
//         if (arr[j] <= pivot) {
//             i++;
//             swap (arr, i, j);
//         }
//     }
//     swap (arr, i + 1, ei);
//     return i + 1;
// }

//------- Some Changes Required in Shuffle fun not fully correct .

// void Shuffle (int arr[], int len) {
//     for (int i = 0; i < len; i++) {
//         int randomIndex = rand() % len;
//         int temp = arr[i];
//         arr[i] = arr[randomIndex];
//         arr[randomIndex] = temp;
//     }
//     for (int i = 0; i < len; i++) {
//         cout << arr[i] << " ";
//     } cout << endl;
// }

void QuickSort (int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int n = partition (arr, si, ei);
    QuickSort (arr, si, n-1);
    QuickSort (arr, n+1, ei);
}

int main () {
    //int arr[] = {4,3,2,1,0,7};
    // int arr[] = {3,3,5,3,6,0,1,1,1,3,0};
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11};
    int size = 11;
    int si = 0, ei = size - 1;
    // Shuffle (arr, size);
    QuickSort ( arr, si, ei);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    } 
    return 0;
}