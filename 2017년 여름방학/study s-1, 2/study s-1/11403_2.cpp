#include <iostream>
using namespace std;

int main()
{
	int n;
	int route[105][105];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> route[i][j];
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (route[i][k] && route[k][j])
					route[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << route[i][j] << " ";
		cout << "\n";
	}

	return 0;
}