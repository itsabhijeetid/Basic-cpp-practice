#include <bits/stdc++.h>
using namespace std;

int subSequence (string input, string output[]) {
    if (input == "") {
        output[0] = ""; 
        return 1;
    }
    string subString = input.substr(1);
    int size = subSequence (subString, output);
    for (int i = 0; i < size; i++) {
        output[size + i] = input[0] + output[i];
    }
    return 2 * size;
}

int main () {
    string input;
    cin >> input;
    int total_no_ofSubSequence = pow (2, input.size());
    string *output = new string [total_no_ofSubSequence]; // we can also creat string dinamicly as string is a class.
    int size = subSequence (input, output);
    cout <<size <<endl;
    for (int i = 0; i < size; i++) {
        cout << output[i] <<endl;
    }
    return 0;
}