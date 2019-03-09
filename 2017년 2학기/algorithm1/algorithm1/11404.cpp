#include <iostream>
#include <algorithm>
using namespace std;

int city, bus;
int info[105][105];

void floyd()
{
	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			for (int k = 1; k <= city; k++)
				info[j][k] = min(info[j][k], info[j][i] + info[i][k]);
		}
	}
}

int main()
{
	cin >> city >> bus;

	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			if (i == j)
				info[i][j] = 0;
			else
				info[i][j] = 100000000;
		}
	}

	for (int i = 1; i <= bus; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (info[a][b] > c)
			info[a][b] = c;
	}

	floyd();

	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
			cout << info[i][j] << " ";
		cout << '\n';
	}

	return 0;
}