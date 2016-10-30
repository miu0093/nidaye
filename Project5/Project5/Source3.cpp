#include <iostream>
#include <algorithm>

using namespace std;

//void swap(int x, int y) {
//	int temp = x;
//	x = y;
//	y = temp;
//}
//
//void swap(int* x, int* y) {
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
void swap_ref(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

//void swap1(char& x, char& y) {
//	int temp = x;
//	x = y;
//	y = temp;
//}
//
//int main() {
//	char a;
//	char b;
//	int exit;
//	cout << "Type in a number" << endl;
//	cin >> a;
//	cout << "Type in another number" << endl;
//	cin >> b;
//
//	swap1(a, b);
//	cout << "The value in a is now" << &a << endl;
//	cout << "The value in b is now" << &b << endl;
//
//	cout << "type a number to exit" << endl;
//	cin >> exit;
//
//	return 0;
//
//}
//int main() {
//	int a, b;
//
//	cout << "Please type in a number" << endl;
//	cin >> a;
//	cout << "Please type in another number" << endl;
//	cin >> b;
//
//	cout << "before swap, a = " << a << " and b = " << b << endl;
//	swap(a, b);
//	cout << "after swap (by value), a = " << a << " and b = " << b << endl;
//	swap(&a, &b);
//	cout << "after swap by pointer reference, a = " << a << " and b = " << b << endl;
//
//	swap_ref(a, b);
//	cout << "after swap using references, a = " << a << " and b = " << b << endl;
//
//	int& a_ref = a;
//
//	int exit;
//	cout << "type to exit" << endl;
//	cin >> exit;
//
//	return 0;
//
//}
