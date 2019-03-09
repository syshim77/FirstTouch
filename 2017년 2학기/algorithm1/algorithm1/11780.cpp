#include <iostream>
#include <algorithm>
using namespace std;

int city, bus;
int mini[105][105];
int route[105][105];

void inimax()
{
	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
			mini[i][j] = (i == j) ? 0 : 100000000;
	}
}

int floyd()
{
	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			for (int k = 1; k <= city; k++)
				mini[j][k] = min(mini[j][k], mini[j][i] + mini[i][k]);
		}
	}
}

int main()
{
	cin >> city >> bus;

	inimax();

	for (int i = 1; i <= bus; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		mini[a][b] = c;
		route[a][b] = 1;
	}

	return 0;
}