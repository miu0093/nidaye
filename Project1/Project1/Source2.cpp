#include <iostream>
using namespace std;

void numberFunction(int i) {
	cout << "The number is: " << i << endl;
	i++;
	if (i<20) {
		numberFunction(i);
	}
}

int main() {

	int exit;
	int i = 0;
	numberFunction(i);

	cin >> exit;

	return 0;
}