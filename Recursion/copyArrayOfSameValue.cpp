#include<iostream>
using namespace std;

int copyIndex ( int arr[], int x, int size, int ca[] ,int csize , int index) {  
    if ( size == 0 ) {
        return csize;
    }
    if ( x == arr [0] ) {
        ca [0] = index;
        csize += 1; 
        ca += 1;   
    }
    csize = copyIndex ( arr + 1 , x , size - 1 , ca , csize , index + 1 );
    return csize;
}

void printCa_Array ( int ca[], int csize) {
    if ( csize != 0 ) {
        cout << ca [0] << " ";
        printCa_Array ( ca + 1 , csize - 1);
    }
}

int main () {
    int arr[] = {5,5,6,5,6};
    int x = 6 , size = 5;
    int ca [size];
    int ca_size = copyIndex(arr, x , size , ca , 0 , 0);    // copy the index of arr[] to ca[] if x == arr[i] ,and return the size of ca[]
    cout << ca_size << endl;
    printCa_Array( ca , ca_size);   // print the element of ca[] 
    return 0;
}