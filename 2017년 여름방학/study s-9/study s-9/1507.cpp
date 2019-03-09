#include <iostream>
using namespace std;

int n;
int sec[25][25];
bool erase[25][25];
bool fail = false;

void route()
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j || i == k || j == k)
					continue;

				if (sec[i][j] == sec[i][k] + sec[k][j])
				{
					erase[i][j] = 1;
					erase[j][i] = 1;
				}
				else if (sec[i][j] > sec[i][k] + sec[k][j])
					fail = true;
			}
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> sec[i][j];
	}

	route();

	if (fail)
		cout << "-1" << '\n';
	else
	{
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				sum += !erase[i][j] * sec[i][j];
		}

		cout << sum / 2 << '\n';
	}

	return 0;
}