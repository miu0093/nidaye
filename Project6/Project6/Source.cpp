#include<iostream>
#include<string>

using namespace std;

int main() {
	/*char question1[] = "What is your firstname? ";
	string question2 = "What is your lastname? ";
	char answer1[80];
	string answer2;
	cout << question1;
	cin >> answer1;
	cout << question2;
	cin >> answer2;
	cout << "Hello, " << answer1;
	cout << " " << answer2 << endl;
*/
	//int a = 10;
	//int* ptr = &a;

	char *first = new char;
	char answer1[7] = { 'Y','U','Z','H','O','U','\0' };
	cout << "asnswer one is: " << answer1[0] << endl;
	/*cout.clear();
	cout.flush();
*/
	first = &(answer1[0]);
	cout << "first is: " << first << endl;

	char *last = new char;
	char answer2[4] = { 'J','I','N','\0' };
	last = &(answer2[0]);
	

	for (int i = 0;i < 6;i++) {

		cout << "My firstname is " << ": " << char(first[0]) << "  " << endl;

	}
	//cout << "My firstname is " << ": " << atoi(first) << "  "<<endl;

	for (int i = 0;i < 3;i++) {
	}
	cout << "My Lastname is " << ": " << last << "  "<<endl;


	int exit;
	cout << "Type a number to exit" << endl;
	cin >> exit;

	delete first;
	*first = NULL;
	delete last;
	*last = NULL;

	return 0;
}
