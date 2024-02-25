#include<iostream>
using namespace std;

void fun(int arr[]) {
    arr[0] = 3;
}
int main () {
    char arr[] = {'a','o','o','o','b','c','o','d','e'};
    int size =  9;
    int count = 0;
 
    for( int i = 0; i < size; i++ ) {
        if (arr[i] != 'o') {
            arr[count] = arr[i];
            count++;
        }
    }
    for(int i = count; i < size; i++){
        arr[i] = '\0';
    }
    for (int i = 0; i < size; i++ ) {
        cout << arr[i] << " ";
    }
    return 0;
}