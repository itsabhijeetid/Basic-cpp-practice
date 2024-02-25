#include<iostream>
using namespace std;
int CheckSort (int arr[] , int const &size1 ) {
    if ( size1 == 0 ) {
        return 1;
    }
    if ( arr[0] < arr[1]) {
        int n = CheckSort ( arr + 1 , size1 - 1 );
        return n;
    }
    else {
        return 0;
    }

}
int main () {
    int arr[] = {1,2,3,4};
    int size = 4;
    int n = CheckSort (arr , size );
    if ( n == 0)
        cout << "Not Sorted";
    else
        cout << "Sorted";
    return 0;
}
