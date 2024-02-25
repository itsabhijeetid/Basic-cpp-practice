#include<iostream>
using namespace std;

int strLength ( char arr[] , int l) {
    if ( arr [0] == '\0' ) {
        return 0;
    }
    l = 1 + strLength ( arr + 1 , l);
    return l;
}

int main () {
    char arr[] = {'a','b','c','d','e','f'};
    int len = strLength(arr , 0);
    cout << len;
}