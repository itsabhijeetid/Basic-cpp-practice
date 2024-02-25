#include<iostream>
using namespace std;
int FindIndex ( int arr[], int x, int size) {
    if ( size == 0 ) {
        return -1;
    }
    if ( x == arr[size-1]) {
        return size-1;
    }
    int index = FindIndex ( arr, x, size - 1);
    if ( index == -1 )
        return -1;
    return index;
}
int main () {
    int arr[] = {5,5,6,5,6};
    int x = 5 , size = 5;
    int index = FindIndex(arr, x , size);
    cout<<index;
    return 0;
}
