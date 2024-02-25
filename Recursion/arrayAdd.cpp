#include<iostream>
using namespace std;

int sum ( int arr[] , int size) {
    if ( size == 0 ) {
        return 0;
    }
    return arr[0]+ sum ( arr + 1 , size - 1);
}

int main() {
    int arr[] = {5,5,2,3,1};
    int size = 5;
    int s = sum(arr, size);
    cout<<s;
    return 0;
}
