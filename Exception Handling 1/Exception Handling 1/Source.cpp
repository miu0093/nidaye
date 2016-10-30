#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const string file_name = "data.txt";
const string file1_name = "data2.txt";

void read_scores(vector<int>& scores) throw (invalid_argument)
{
	ifstream data_file;
	ifstream data2_file;
	int temp;
	int temp2;

	data_file.open(file_name.c_str());
	data2_file.open(file_name.c_str());

	if (data_file.fail())
		throw invalid_argument("no file exists " + file_name);

	if (data2_file.fail())
		throw invalid_argument("no file exists " + file_name);

	while (data_file >> temp)
		scores.push_back(temp);

	while (data2_file >> temp2)
		scores.push_back(temp2);

	data_file.close();
	data2_file.close();
}

double find_average(const int sum, const int divisor) throw (runtime_error)
{
	if (!divisor)
		throw runtime_error("divisor is zero");
	return (sum / (double)divisor);
}

void throwing_ftn() throw (runtime_error) {
	throw runtime_error("something went wrong\n");
}

void memory_leak() throw (runtime_error) {
	string* s = new string("hello");

	throwing_ftn();

	delete s;
}

void no_memory_leak() throw (runtime_error) {
	string* s = new string("hello");

	try {
		throwing_ftn();
	}
	catch (...) {
		delete s;
		throw;
	}
	delete s;
}

int main() {
	vector<int> scores;
	int sum = 0;

	try {
		read_scores(scores);
		for (auto &score:scores) {
			sum += score;
		}
		cout << "avg = " << find_average(sum, scores.size()) << endl;
	}
	catch (const invalid_argument& iae) {
		cout << "unable to read data: " << iae.what() << endl;
		exit(1);
	}
	catch (const runtime_error& rte) {
		cout << "unable to compute average: " << rte.what() << endl;
		exit(1);
	}

	for (auto &score:scores)
		cout << "score = " << score << endl;

	system("pause");

	return 0;
}