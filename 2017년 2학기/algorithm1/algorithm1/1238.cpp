#include <iostream>
#include <algorithm>
using namespace std;

int stu, rode, en;
int t[1005][1005];
#define MAX 1000000000

void floyd()
{
	for (int i = 1; i <= stu; i++)
	{
		for (int j = 1; j <= stu; j++)
		{
			for (int k = 1; k <= stu; k++)
				t[j][k] = min(t[j][k], t[j][i] + t[i][k]);
		}
	}
}

void inimax()
{
	for (int i = 1; i <= stu; i++)
	{
		for (int j = 1; j <= stu; j++)
			t[i][j] = (i == j) ? 0 : MAX;
	}
}

int main()
{
	cin >> stu >> rode >> en;

	inimax();

	for (int i = 1; i <= rode; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		t[a][b] = c;
	}

	floyd();

	int m = 0;
	for (int i = 1; i <= stu; i++)
	{
		if (m < t[i][en] + t[en][i])
			m = t[i][en] + t[en][i];
	}

	cout << m << '\n';

	return 0;
}