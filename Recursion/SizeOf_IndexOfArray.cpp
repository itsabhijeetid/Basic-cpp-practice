#include<iostream>
using namespace std;
int CopyIndex ( int arr, int x, int size) {
    if ( size == 0) {
        return -1;
    }
}
int main() {
    int arr[] = {5,5,6,5,6};
    int x = 5 , size = 5;
    int index = CopyIndex(arr, x , size);
    cout<<index;
    return 0;
}
