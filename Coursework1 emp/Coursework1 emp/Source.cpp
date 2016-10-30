#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <bitset>

using namespace std;;

bitset<4> regi;

int main() {
	int a;
	cout << "Type in a number to start." << endl;
	cin >> a;

	int b;
	cout << "Hello,My name is Encoder,Type E and start with me" << endl;
	cout << "                                                 " << endl;
	cout << "_________________________________________________" << endl;
	cin >> b;
	cout << "Please type in S to save to txt files;" << endl;
	int c;
	cin >> c;
	

	cout << "Files are saved" << endl;
	ifstream ifile;

	ifile.open("data.txt");
	ifile.get();
	vector<char> infile;

	if (!ifile.eof() && !ifile.fail())
	{
		ifile.seekg(0, ios_base::end);
		streampos fileSize = ifile.tellg();
		infile.resize(fileSize);

		ifile.seekg(0, ios_base::beg);
		ifile.read(&infile[0], fileSize);
	}
	int n = 0;
	string jyz = "0.txt";
	for (int L1 = 0;L1 < 3;L1++) {
		for (int L2 = 0; L2 < 3;L2++) {
			for (int L3 = 0;L3 < 3;L3++) {
				n++;
				stringstream ss;
				string s;
				ss << n;
				ss >> s;
				ofstream ofile(jyz);
				jyz = s + ".txt";
				for (auto ele : infile) {
					regi[3] = (ele - '0');
					int ouput1(regi[L2] ^ regi[L3]);
					int ouput2(regi[3] ^ regi[L1]);
					regi >>= 1;
					ofile << ouput1;
					ofile << ouput2;
				}
			}
		}
	}
	

	system("pause");
}
