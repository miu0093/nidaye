#include "lookup.h"
#include<iostream>

using namespace std;


int main() {

	int a;
	cout << "Type in a number to start decoding." << endl;
	cin >> a;
	Decoder *i = new Decoder();
	i->setdiagram();
	cout << "-_-_-_-_-_-_-_-_-_-_-" << endl;
	cout << "                     " << endl;
	cout << "Decoding successfully" << endl;
	int b;
	cout << "Please type in S to save your output." << endl;
	cin >> b;
	cout << "Thanks for using the decoder." << endl;

	system("pause");
}