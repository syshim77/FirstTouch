#include <iostream>
using namespace std;

int main()
{
	int n, cnt; int max = 0;
	int cost[1000] = { 0 };
	int dp[1000] = { 0 };

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}

	while (n != 0)
	{
		for (int i = 1; i <= n; i++)
		{
			dp[i] = (n / i)*cost[i];
			if (max < dp[i])
			{
				max = dp[i];
				cnt = i;
			}
		}
		dp[0] += max;
		n %= cnt;
	}

	cout << dp[cnt];

	return 0;
}