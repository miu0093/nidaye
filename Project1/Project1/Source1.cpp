#include <iostream>

using namespace std;

bool isPositive(int x) {
	if (x >= 0)
	return true;
	else {
		return false;
	}
}


int main() {

	int n;

	do {
		cin >> n;
	} while (isPositive(n));
	return 0;
}