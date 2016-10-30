#include "decoder.h"
#include <iostream>

using namespace std;

void main()
{
	int re[] = { -1,3,3,-1,3 };
	Decoder vb;
	cout << "Show the diagram" << endl;
	vb.setpe(2, 1, 2, 1);
	vb.v(re, 5);
	cout << "X" << endl;
	for (int i = 0;i<5;i++)
		cout << re[i] << " ";
	getchar();
	cout << endl;
}
