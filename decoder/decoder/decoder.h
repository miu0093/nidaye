//www.51wendang.com / doc / 536ed18011696144f0f192cd / 2//
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Decoder
{
public:
	void settrellis();
	void setpe(int a, int b1, int b2, int b3);
	void v(int *re, int n);
	void set_pre(int now, int *pre);
	int getcurrent(int j, int i, int in);
	int min_path(int a, int b);
	int get_out(int pre, int next);
private:
	int trellis[8][5],s_number,multi1,multi2,multi3;
	struct get_path
	{
		int pre;
		int out;
	};
};

void Decoder::setpe(int a, int b1, int b2, int b3)
{
	s_number = a;
	multi1 = b1;
	multi2 = b2;
	multi3 = b3;
}

void Decoder::settrellis()
{
	for (int i = 0;i<8;i++)
		for (int j = 0;j<5;j++)
		{
			int l, h;
			l = i & 1;
			h = (i >> 1) & 1;
			if (j % 2 == 0)
				trellis[i][j] = multi1*(j - 1) + multi2*(2 * h - 1) + multi3*(2 * l - 1);
			else
				trellis[i][j] = (j & 2) ^ h;
			cout << trellis[i][j] << " ";
			if (j == 3)
				cout << endl;
		}
}

void Decoder::v(int *re, int n)
{
	settrellis();
	vector<vector<int>>remb(4);
	vector<vector<get_path>>path(4);
	for (int i = 0;i<4;i++)
	{
		remb[i].resize(n);
		path[i].resize(n);
		for (int j = 0;j<n;j++)
		{
			remb[i][j] = 0;
			path[i][j].out = 000;
			path[i][j].pre = 000;
			/*remb[i][j] = min_path(remb[pre1][j - 1] + getcurrent(pre1, i, re[j]), remb[pre2][j - 1] + getcurrent(pre2, i, re[j]));*/
		}
	}
	
	for (int i = 0;i<4;i++)
	{
		remb[i][0] = getcurrent(0, i, re[0]);
		path[i][0].pre = 0;
		path[i][0].out = get_out(0, i);
	}
	for (int j = 1;j<n;j++)
	{
		for (int i = 0;i<4;i++)
		{
			int pre[2];
			set_pre(i, pre);
			int a = getcurrent(pre[0], i, re[j]);
			int b = getcurrent(pre[1], i, re[j]);
			remb[i][j] = min_path(remb[pre[0]][j - 1] + getcurrent(pre[0], i, re[j]), remb[pre[1]][j - 1] + getcurrent(pre[1], i, re[j]));
			if (remb[i][j] == (remb[pre[0]][j - 1] + getcurrent(pre[0], i, re[j])))
			{
				path[i][j].pre = pre[0];
				path[i][j].out = get_out(pre[0], i);
				
			}
			else
			{
				path[i][j].pre = pre[1];
				path[i][j].out = get_out(pre[1], i);
			}
		}
	}
	int minimum;
	int min = 1000;
	for (int i = 0;i<4;i++)
	{

		if (remb[i][4]<min)
		{
			min = remb[i][4];
			minimum = i;
		}

	}
	for (int j = n - 1;j >= 0;j--)
	{
		re[j] = path[minimum][j].out;
		minimum = path[minimum][j].pre;
	}
}

int Decoder::get_out(int pre, int now)
{
	int out, count = 0;
	for (int j = 0;j<2;j++)
		if (trellis[pre][2 * j + 1] == now)
		{
			out = 2 * j - 1;
			count++;
		}
	if (count == 0)
		out = 1000;
	return out;

}

void Decoder::set_pre(int now, int *pre)
{
	int count = 0;
	for (int i = 0;i<4;i++)
		for (int k = 0;k<2;k++)
		{
			if (trellis[i][2 * k + 1] == now&&count == 0)
			{
				pre[0] = i;
				count++;
			}
			if (trellis[i][2 * k + 1] == now&&count != 0)
			{
				pre[1] = i;
			}
		}
}

int Decoder::getcurrent(int j, int i, int in)
{
	int result;
	int count = 0;
	for (int k = 0;k<2;k++)
	{
		if (trellis[j][2 * k + 1] == i)
		{
			result = in - trellis[j][2 * k];
			count++;
		}
	}
	if (count == 0)
		result = 10000;
	return abs(result);
}
int Decoder::min_path(int a, int b)
{
	if (a>b)
		return b;
	else
		return a;
}

