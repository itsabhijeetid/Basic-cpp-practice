// Using inbuild Stack
// and also do by unordered map = https://www.youtube.com/watch?v=q-JB0hYyouo&list=PLauivoElc3gh3RCiQA82MDI-gJfXQQVnn&index=13
// Not working 

#include <iostream>
#include <stack>
using namespace std;

stack<string> s;

bool OpenBracket (char str) {
    if (str == '(' || str == '{' || str == '[') {
        string str1 = ""+str;
        s.push (str1);
        return true;
    } return false;
}

bool CloseBracket (char str) {
    if (s.top() == "(" && ( str == ')' ) || ( s.top() == "{"  && str == '}' ) || ( s.top() == "[" && str == ']' ) )  
    {
        s.pop ();
        return true;
    } 
    return false;
}

int main () {
    string str = "{a+(b-c)*d}"; // true  
     //string str =  "x{a+(b-c)}*d";
    //string str =  "x{a+(b-c)}*d(q-e)";
    //string str = "{a+(b-c+[e-f)]}"; // false
    int p = 0;
    // cin >> str;
    for (int i = 0; i < str.length(); i++) {
        // if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
        //     s.push (str[i]);
        // } 
        // else if (s.top() == ')' || s.top() == '}' || s.top() == ']') {
        //     s.pop ();
        // }
        if ( OpenBracket(str[i]) || CloseBracket(str[i]) )
        {
            p = 1;
        }  else {
                if ( !s.empty() ) {
                    p = 0; 
                }
        }
    }
    if (p == 1) {
        cout << "correct";
    } else {
        cout << "not correct";
    }
    return 0;
}