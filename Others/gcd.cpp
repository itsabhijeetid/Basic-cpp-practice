// #include<iostream>
// using namespace std;
// int find_fac(int num1,int num2)
// {
//   int ans=1;
//   int num=0;
//   if(num1>num2)
//     num=num2;
//   else
//     num=num1;
//   for(int i=num;i>0;i--)
//   {
//     if(num1%i==0 && num2%i==0)
//     {
//         ans=i;
//         break;
//     }
//   }
//   return ans;
// }
// int main()
// {
//   int gcd=find_fac(12,28);
//   cout<<gcd;
// }
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}
int main()
{
    int a, b;
    cout << "enter the numbers ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b);
    return 0;
}
