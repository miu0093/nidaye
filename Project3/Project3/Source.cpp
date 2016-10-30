
#include <iostream>

using namespace std;

int main() {

	int a;

	int* b;

	a = 100;

	b = new int;

	cout << "The pointer b points to the memory address " << b << " located on the heap\n";
	cout << "The value in memory location b is " << *b << "\n";

	*b = a;

	cout << "The value of stack variable a is " << a << "\n";
	cout << "The 'heap' memory pointed to by b contains " << *b << "\n";

	delete b;
	b = NULL;

	return 0;
}