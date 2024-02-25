#include <iostream>
using namespace std;

void AddNull ( char arr[], int count ) {
    if ( arr[0] != '\0' ) { // do changes 
        arr[ count ] = '\0';
        AddNull ( arr + 1, count + 1);
    }
}

void RemoveX ( char arr[], int x, int count) {
    if ( arr[0] == '\0' ) {
        AddNull (arr , count);
    }
    if ( arr[0] =! 'o' ) {
        arr[count] = arr[0];
        count += 1;
    }   RemoveX ( arr + 1, x , count );
}
void printArray ( char arr[] ) {
    if ( arr[0] != '\0') {
        cout << arr[0] <<" ";
        printArray ( arr + 1 );
    } 
}
int main() {
    char arr[] = {'a', 'o', 'c', 'o', 'e', 'f'};
    char x = 'o';
    if ( arr[0] == 'o' ) {
        
    }
    RemoveX ( arr + 1, x , 0 );
    printArray ( arr );
    return 0;
}
