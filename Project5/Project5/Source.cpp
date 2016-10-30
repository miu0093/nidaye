#include <iostream>

using namespace std;

int global_variable[10] = { 7, 3, 5, 2, 1, 4, 6, 9, 10, 8 };

namespace some_namespace {
	void some_function();
}

namespace some_other_namespace {
	void some_function();
}

void swap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap_ref(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}


int main() {
	int a, b;

	cout << "Please type in a number" << endl;
	cin >> a;
	cout << "Please type in another number" << endl;
	cin >> b;

	cout << "before swap, a = " << a << " and b = " << b << endl;
	swap(a, b);
	cout << "after swap (by value), a = " << a << " and b = " << b << endl;
	swap(&a, &b);
	cout << "after swap by pointer reference, a = " << a << " and b = " << b << endl;

	swap_ref(a, b);
	cout << "after swap using references, a = " << a << " and b = " << b << endl;

	int& a_ref = a;

	return 0;
}
