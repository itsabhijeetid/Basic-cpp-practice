#include<iostream>
#include<string>
using namespace std;

int main () {
    string data;
    cout << "Enter Credit Card Number: ";
    cin >> data;
    int sum = 0;
    for (int i = 0; i < data.length(); i++) {
        if (i % 2 == 0) {
            int temp = 2 * ( (int)data[i] - 48);
            data [i] = '0' +  (char) ( temp % 10 +  temp / 10 );
        } 
        sum = sum + ( (int)data[i] - 48);
    }
    if (sum % 10) 
        cout << "Not Valid";
    else    
        cout << "Valid";
    return 0;
}

