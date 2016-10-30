#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

class Decoder {
public:
	Decoder();
	~Decoder();
	void setdiagram() /*throw (invalid_argument)*/;
private:
	struct state {
		string input;
		string current;
		string output;
		string nextstep;
	};
	state array[16] = { { "0","000","00","000" },{ "0","001","01","000" },{ "0","010","01","001" },{ "0","011","00","001" },
	                    { "0","100","10","010" },{ "0","101","11","010" },{ "0","110","11","011" },{ "0","111","10","011" },
	                    { "1","000","10","100" },{ "1","001","11","100" },{ "1","010","11","101" },{ "1","011","10","101" },
	                    { "1","100","00","110" },{ "1","101","01","110" },{ "1","110","01","111" },{ "1","111","00","111" } };
};

Decoder::Decoder() {

}

Decoder::~Decoder() {
	

}

//const string file_name = "binaryFile.txt";

void Decoder::setdiagram() /*throw (invalid_argument)*/ {

	ifstream ifile("binaryFile.txt");
	/*ifile.open("binaryFile.txt");*/
	char a[3];
	string jyz = "decoded.txt";
	ofstream ofile;
	ofile.open(jyz);
	string stemp = "000";
	string nextstemp = "000";
	int n = 0;

	while (!ifile.eof())
		
	{	
		ifile.get(a[0]);
		ifile.get(a[1]);


		string b="00";
		b[0] = a[0];
		b[1] = a[1];
		/*b[2] = b[0] + b[1];*/
		for (int i = 0;i < 16;i++) {
			if (b == array[i].output && stemp == array[i].current) {
			/*	if (nextstemp == array[i].nextstep) {*/
					ofile << array[i].input;
					stemp = array[i].nextstep;
					break;
					
			/*	}*/
					
			}
		}
	}
	ifile.close();
}

