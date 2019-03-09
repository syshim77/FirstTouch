#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, res;
	int tri[501][501] = { 0 };
	int sum[501][501] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];
	}

	sum[0][0] = tri[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				sum[i][j] = sum[i - 1][j] + tri[i][j];
			else if (j == i)
				sum[i][j] = sum[i - 1][j - 1] + tri[i][j];
			else
				sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + tri[i][j];
		}
	}

	res = sum[n - 1][0];
	for (int i = 1; i < n; i++)
	{
		res = max(res, sum[n - 1][i]);
	}

	cout << res;

	return 0;
}