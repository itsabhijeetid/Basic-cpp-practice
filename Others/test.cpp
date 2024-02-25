#include <iostream>
using namespace std;

int main () {
	// int a = 5;
	// void *ptr = &a;
	// cout << ptr << endl;
	int arr[] = {1,2,3,14,5};
	// int arr[8];
	// arr[0] = 1;
	// arr[1] = 1;
	// arr[2] = 1;
	// arr[3] = 1;
	for (auto i:arr) {
		cout << i << " ";
	}
	return 0;
}