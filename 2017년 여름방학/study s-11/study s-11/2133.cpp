#include <iostream>
using namespace std;

int main()
{
	int dp[31] = {};
	int result[31] = {};
	int n;

	dp[0] = 1; result[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= 30; i += 2)
		dp[i] = 2;

	cin >> n;

	for (int i = 2; i <= n; i += 2)
	{
		for (int j = 2; j <= i; j += 2)
			result[i] += dp[j] * result[i - j];
	}

	cout << result[n] << '\n';

	return 0;
}