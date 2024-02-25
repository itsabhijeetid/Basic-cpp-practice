#include<iostream>
using namespace std;
void fibo (int range , int a , int b) {
    if  ( range != 0) {
         int c = a + b;
         cout << c << " ";
         fibo ( range -1 , b , c) ;
    }
}
int main() {
    int range = 10;
    int a = 0 , b = 1;
    cout<<a<<" " << b << " ";
    fibo (range-2 , a , b);
    return 0;
}
