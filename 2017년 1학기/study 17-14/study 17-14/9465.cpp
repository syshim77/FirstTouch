#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int testcase, n;
	int sticker[2][100002] = { 0 };
	int dp[2][100002] = { 0 };

	cin >> testcase;

	while (testcase--)
	{
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> sticker[i][j];
			}
		}
		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];

		for (int i = 0; i < n; i++) 
		{
			dp[0][i] = max(max(dp[0][i - 1], dp[1][i - 1] + sticker[0][i]),
				dp[1][i - 2] + sticker[0][i]);
			dp[1][i] = max(max(dp[1][i - 1], dp[0][i - 1] + sticker[1][i]), 
				dp[0][i - 2] + sticker[1][i]);
		}

		if (dp[0][n - 1] > dp[1][n - 1])
			cout << dp[0][n - 1] << endl;
		else
			cout << dp[1][n - 1] << endl;
	}

	return 0;
}