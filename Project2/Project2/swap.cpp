#include <iostream>
#include <utility>

using namespace std;

int main() {
	int a = 14;
	int b = 36;

	int *x = &a;
	int *y = &b;

	cout << "Value in memory location pointed is " << *y << endl;
	cout << "Value in memory location pointed is " << *x << endl;

	int** j;
	int** k;

	j = &y;
	k = &x;

	cout << "j is now pointing to what b points to: " << **j << endl;
	cout << "j points to: " << *j << endl;
	cout << "j actually holds the value: " << j << endl;
	cout << j << " is the same value as b's memory location: " << &y << endl;
	cout << "j is actually at memory location " << &j << endl;
	cout << "j is eventually retrieving what is in memory location " << **&j << endl;

	cout << "k is now pointing to what b points to: " << **k << endl;
	cout << "k points to: " << *k << endl;
	cout << "k actually holds the value: " << k << endl;
	cout << k << " is the same value as a's memory location: " << &x << endl;
	cout << "k is actually at memory location " << &k << endl;
	cout << "k is eventually retrieving what is in memory location " << **&k << endl;


	int z;
	cout << "Type in a number to exit" << endl;
	cin >> z;

	return 0;
}