#include <iostream>

using namespace std;

int main() {

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int *x = arr;

	cout << "Value in memory location x is " << *x << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << *(x + i) << " ";
	}
	cout << endl;
	int exit;
	cout << "Type in a number to exit" << endl;
	cin >> exit;

	return 0;

}