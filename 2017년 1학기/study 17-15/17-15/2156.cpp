#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int quan[10000];
	int dp[10000] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> quan[i];
	}

	dp[0] = quan[0];
	dp[1] = quan[0] + quan[1];
	for (int i = 2; i < n; i++)
	{
		dp[i] = max(max(dp[i - 1], dp[i - 2] + quan[i]), dp[i - 3] + quan[i] + quan[i - 1]);
	}

	cout << dp[n - 1];

	return 0;
}