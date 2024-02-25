#include <iostream>
using namespace std;
int power(int a, int b)
{
    int temp;
    if (b == 0)
        return 1;
    temp = power(a, b / 2);
    if (b % 2 == 0)
        return temp * temp;
    else
        return a * temp * temp;
}
int main()
{
    int num1, num2;
    cout << "enter the number ";
    cin >> num1 >> num2;
    cout << "Power of "<< num1 << "^" << num2 << " = " << power(num1, num2);
}
