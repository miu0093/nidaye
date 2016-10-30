#include <bitset>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream fin("data.txt");
	string s;
	while (fin >> s) {}
	string input;
	for (int i = 0; i < 3; i++) {
		input.push_back(i % 2 ? 1 : 0); //010
		cout << input[i];
	}
	cout << endl;
	int encoder = 0;

	bitset<2> output(0U);
	bitset<3> reg(0U);

	for (int i = 0;i < 3;++i) {
		output[0] = input[i] ^ reg[2];	//00 01 01
		output[1] = reg[1] ^ reg[0];

		reg >>= 1;
		reg[2] = input[i];
		cout << output << endl;
	}

	system("pause");
	return 0;
}
