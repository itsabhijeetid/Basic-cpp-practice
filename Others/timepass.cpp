#include <iostream>
using namespace std;
int main()
{
    
   int arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = i+1;
    }
    arr[5]=5;
    arr[6]=5;
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << "  ";
    }
    
    // cout<<arr[11];
    

    return 0;
}
