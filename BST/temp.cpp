#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 6; i++) {
        for (int k = 5; k > i; k--) 
            cout << "  ";
        if (i > 0)
            cout << "* ";
        for (int j = 0; j < 2*i+1; j++) {
            if (i == 5) 
                cout <<"* ";
            else
                cout << "  ";
        }
        cout <<" *"<<endl;
    }

    return 0;
}