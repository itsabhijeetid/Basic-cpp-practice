#include<iostream>
using namespace std;

void RemoveDuplicates ( char arr[] ) {

    if ( arr [0] == '\0' ) {
        return;
    }
    

}

int main () {

    char arr[] = {'a','a','b','b','b','c','e','a','a'};
    RemoveDuplicates (arr);
    cout << arr;
    return 0;

}